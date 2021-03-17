import socket
import pprint
from datetime import datetime
from pycrate_asn1dir import S1AP
from pycrate_asn1rt.utils import *
from pycrate_mobile import NASLTE
from pycrate_mobile import NAS

def parse_msg(msg):
    PDU = S1AP.S1AP_PDU_Descriptions.S1AP_PDU
    PDU.from_aper(msg)
    s1ap_obj = PDU.get_val()
    pp = pprint.PrettyPrinter(indent=1)
    pp.pprint(s1ap_obj)
    #print(s1ap_obj)
    enbUES1apId = -1
    inner1 = s1ap_obj[1]['value']
    for ie in inner1[1]['protocolIEs']:
        if ie['id'] == 8:
            enbUES1apId = ie['value'][1]
            print('GOT ENB UE S1AP ID ', enbUES1apId)
        elif ie['id'] == 26:
            inner2 = ie['value'][1]
            # if (s1ap_obj[0] == 'initiatingMessage'):
            #     pp.pprint(NASLTE.parse_NASLTE_MO(inner2))
            # else:
            #     pp.pprint(NASLTE.parse_NASLTE_MO(inner2))
            nas = NASLTE.parse_NASLTE_MO(inner2)
            pp.pprint(nas)
            if inner1[0] == 'InitialUEMessage':
                print('GOT INITIAL UE MSG')
                print(nas['EPSID'])
        elif ie['id'] == 24:
            inner2 = ie['value'][1][0]['value'][1]['nAS-PDU'] #.NASMessage
            pp.pprint(inner2)
            val, err = NASLTE.parse_NASLTE_MT(inner2)
            pp.pprint(val)
            print(type(val))
            pp.pprint(val['NASMessage'])
            val, err = NAS.parse_NAS_MT(val['NASMessage'].get_val())
            pp.pprint(val)
            # print(type(val['NASMessage']))
            # print(type(val['NASMessage'].get_val()))
            # print(val['NASMessage'].get_val())
            # pp.pprint(NASLTE.parse_NASLTE_MT(inner2)[0].NASMessage)
#                if (s1ap_obj[0] == 'initiatingMessage'):
#                    inner1 = s1ap_obj[1]['value']
#                    #pp.pprint(inner1)
#                    if (inner1[0] == 'DownlinkNASTransport'):
#                        for ie in inner1[1]['protocolIEs']:
#                            if (ie['value'][0] == 'NAS-PDU'):
#                                inner2 = ie['value'][1]
#                                pp.pprint(inner2)
#                                nas_packet = NASLTE.parse_NASLTE_MT(inner2)
#                                pp.pprint(nas_packet)
                #IEs = get_val_at(PDU, ['initiatingMessage', 'value', 'S1SetupRequest', 'protocolIEs'])
                #for ie in IEs: print(ie['value'])
#                print(s1ap_packet)

            # print(chunk_data)

        print()

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
