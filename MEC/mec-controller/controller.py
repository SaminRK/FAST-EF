import socket
import pprint
from datetime import datetime
from pycrate_asn1dir import S1AP
from pycrate_asn1rt.utils import *
from pycrate_mobile import NASLTE

def parse_msg(msg):
    PDU = S1AP.S1AP_PDU_Descriptions.S1AP_PDU
    PDU.from_aper(msg)
    s1ap_obj = PDU.get_val()
    pp = pprint.PrettyPrinter(indent=1)
    pp.pprint(s1ap_obj)
    #print(s1ap_obj)
    inner1 = s1ap_obj[1]['value']
    for ie in inner1[1]['protocolIEs']:
        if ie['id'] == 26:
            inner2 = ie['value'][1]
            if (s1ap_obj[0] == 'initiatingMessage'):
                pp.pprint(NASLTE.parse_NASLTE_MO(inner2))
            else:
                pp.pprint(NASLTE.parse_NASLTE_MO(inner2))
        elif ie['id'] == 24:
            inner2 = ie['value'][1][0]['value'][1]['nAS-PDU'][0] #.NASMessage
            pp.pprint(NASLTE.parse_NASLTE_MO(inner2))
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

    ListenSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    ListenSock.bind(('localhost', LOCAL_PORT))
    ListenSock.listen(5)

    print("waiting for client to connect...")

    clientSock, address = ListenSock.accept()

    print("Connected with client")

    while True:
        try:
            msg = clientSock.recv(4096)
            parse_msg(msg)
        except Exception:
            break

if __name__ == '__main__' :
    main()


