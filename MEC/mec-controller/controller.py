import socket
import pprint
import ipaddress
import requests
from datetime import datetime
from pycrate_asn1dir import S1AP
from pycrate_asn1rt.utils import *
from pycrate_mobile import NASLTE
from pycrate_mobile import NAS
from requests.exceptions import Timeout

store = {}

def parse_msg(msg):
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
                requests.post(url='http://localhost:15005/oidc/store', json=store[enbUES1apId], timeout= 1.0)
                print('SENT DATA TO OIDC MODULE')
            except Exception:
                print('COULD NOT SEND DATA')

def main() :
    LOCAL_PORT = 9001

    ListenSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ListenSock.bind(('localhost', LOCAL_PORT))
    ListenSock.listen(5)

    print("waiting for client to connect...")

    clientSock, address = ListenSock.accept()

    print("Connection with client established")

    while clientSock:
        try:
            msg = clientSock.recv(4096)
            parse_msg(msg)
        except Exception:
            break

if __name__ == '__main__' :
    main()
