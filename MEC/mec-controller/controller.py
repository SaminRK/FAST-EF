import socket
import pprint
import ipaddress
import json
import time
import requests
import aiohttp
import asyncio
from datetime import datetime
from pycrate_asn1dir import S1AP
from pycrate_asn1rt.utils import *
from pycrate_mobile import NASLTE
from pycrate_mobile import NAS
from requests.exceptions import Timeout
import argparse

store = {}
args = None
mecManagerAmsUrl = None
MEC_IDP_ADDR = "http://localhost:15005"
CLOUD_IDP_ADDR = "http://104.196.145.129:15005"

async def send_subscription_data_to_idp(session, store, enbUES1apId, prefetch, idp_addr):
    st = time.time()
    print('Subscription data send. Start at', round(st, 3))
    if prefetch:
        print('Prefetching user data')
        async with session.get(f'{mecManagerAmsUrl}/manager/user/data', params={'imsi': store[enbUES1apId]['imsi']}) as resp:
            print('Prefetch user data response', resp.status)
            store[enbUES1apId]['subscriptionData'] = await resp.json()
            print("Subscription data fetched. Finished at", round(time.time() - st, 3))
            async with session.post(f'{idp_addr}/oidc/store', json=store[enbUES1apId]) as resp_post:
                print('user data post to idp response', resp_post.status)
                print("Subscription data sent. Finished at", round(time.time() - st, 3))
    else: 
        async with session.post(f'{idp_addr}/oidc/store', json=store[enbUES1apId]) as resp_post:
            print('user data post to idp response', resp_post.status)
            print("Subscription data sent. Finished at", round(time.time() - st, 3))
            

async def prefetch_state(session, store, enbUES1apId):
    async with session.post(f'{mecManagerAmsUrl}/ams/prefetch/state', json={'imsi': store[enbUES1apId]['imsi']}) as resp:
        print('prefetch state response', resp.status)

def parse_msg(msg):
    global store

    PDU = S1AP.S1AP_PDU_Descriptions.S1AP_PDU
    PDU.from_aper(msg)
    s1ap_obj = PDU.get_val()
    pp = pprint.PrettyPrinter(indent=1)
    # pp.pprint(s1ap_obj)

    enbUES1apId = -1
    inner1 = s1ap_obj[1]['value']
    for ie in inner1[1]['protocolIEs']:
        if ie['id'] == 8:
            enbUES1apId = ie['value'][1]
            print('GOT ENB UE S1AP ID ', enbUES1apId)
        elif ie['id'] == 26:
            inner2 = ie['value'][1]
            nas, err = NASLTE.parse_NASLTE_MO(inner2)
            # pp.pprint(nas)
            if inner1[0] == 'InitialUEMessage':
                print('GOT INITIAL UE MSG')
                code, imsi = nas['EPSID']['EPSID'].decode()
                print('GOT IMSI ', imsi)
                store[enbUES1apId] = {
                    'enb_ue_s1ap_id': enbUES1apId,
                    'imsi': imsi,
                }
                
        elif ie['id'] == 24:
            inner2 = ie['value'][1][0]['value'][1]['nAS-PDU'] #.NASMessage
            # pp.pprint(inner2)
            nas, code = NASLTE.parse_NASLTE_MT(inner2)
            # pp.pprint(nas)
            esm, code = NAS.parse_NAS_MT(nas['NASMessage'].get_val())
            # pp.pprint(esm)
            remote_ip = esm['ESMContainer']['ESMActDefaultEPSBearerCtxtRequest']['PDNAddr']['PDNAddr']['Addr'].get_val()
            remote_ip = str(ipaddress.IPv4Address(remote_ip))
            print('GOT IP ADDRESS: ', remote_ip)
            store[enbUES1apId]['remote_ip'] = remote_ip
            print(store[enbUES1apId])
            print('SENDING DATA TO OIDC MODULE')
            try:
                async def asyncio_main():
                    async with aiohttp.ClientSession() as session:
                        tasks = []
                        
                        # tasks.append(asyncio.ensure_future(send_subscription_data_to_idp(session, 
                        #     store, enbUES1apId, args.prefetch_user_data, CLOUD_IDP_ADDR)))
                        tasks.append(asyncio.ensure_future(send_subscription_data_to_idp(session, 
                            store, enbUES1apId, args.prefetch_user_data, MEC_IDP_ADDR)))
                        
                        if args.prefetch_state:
                            print('Prefetching state. Telling AMS that UE has entered.')
                            tasks.append(asyncio.ensure_future(prefetch_state(session, store, enbUES1apId)))
                        
                        await asyncio.gather(*tasks)

                asyncio.run(asyncio_main())
                print('SENT DATA TO OIDC MODULE')           
            except Exception as e:
                print(e)
                print('COULD NOT SEND DATA')

def main() :
    parser = argparse.ArgumentParser()
    parser.add_argument('-u', '--prefetch_user_data', default=False, action='store_true')
    parser.add_argument('-s', '--prefetch_state', default=False, action='store_true')
    parser.add_argument('-n', '--network', default='home', type=str, help='network (home | foreign)')
    
    global args
    args = parser.parse_args() 

    if not args.network:
        parser.error('No network set, add --network (home | foreign)')
    
    global mecManagerAmsUrl
    if args.network == 'home':
        mecManagerAmsUrl = 'http://localhost:8000'
    elif args.network == 'foreign': 
        mecManagerAmsUrl = 'http://localhost:8001'

    LOCAL_PORT = 9001

    ListenSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ListenSock.bind(('0.0.0.0', LOCAL_PORT))
    ListenSock.listen(5)

    print("waiting for client to connect...")

    clientSock, address = ListenSock.accept()

    print("Connection with client established")

    while clientSock:
        try:
            msg = clientSock.recv(4096)
            parse_msg(msg)
        except Exception as e:
            print(e)
            break

if __name__ == '__main__' :
    main()
