import socket
import binascii
import struct
import sysv_ipc
import hashlib
import ipaddress
import pprint
from datetime import datetime
from pycrate_asn1dir import S1AP
from pycrate_asn1rt.utils import *
from pycrate_mobile import NASLTE


# 0      0   0.(Version 	IHL) 	1.(DSCP 	ECN) 	2.Total Length
# 4 	32 	 3. Identification 	4.(Flags 	Fragment Offset)
# 8 	64 	 5. Time To Live 	6. Protocol 	7. Header Checksum
# 12 	96 	 8. Source IP Address
# 16 	128 	9. Destination IP Address

def parseIPPacket(ip_packet):
    ip_length = 20
    if (len(ip_packet) < 24):
        ip_packet += b'0'*24
    ip_header = struct.unpack("!BBHHHBBH4s4s", ip_packet[:ip_length])

    IHL = (ip_header[0] & 0xf) * 4

    src_ip = ipaddress.IPv4Address(ip_header[8])
    dest_ip = ipaddress.IPv4Address(ip_header[9])

    print('Source IP: {0}, Destination IP: {1}'.format(str(src_ip), str(dest_ip)))
    if ip_header[6] == 6:
        print("Protocol: TCP")
    elif ip_header[6] == 17:
        print("Protocol: UDP")
    elif ip_header[6] == 132:
        print("Protocol: SCTP")

    print()

def parseSCTPPacket(ip_packet):
    ip_length = 20
    if (len(ip_packet) < 24):
        ip_packet += b'0'*24
    ip_header = struct.unpack("!BBHHHBBH4s4s", ip_packet[:ip_length])

    if ip_header[6] == 132: #SCTP

        chunk_type = ["DATA", "INIT", "INIT ACK", "SACK", "HEARTBEAT","HEARTBEAT ACK","ABORT", "SHUTDOWN", "SHUTDOWN ACK", "ERROR", "COOKIE ECHO", "COOKIE ACK", "ECNE", "CWR", "SHUTDOWN COMPLETE", "AUTH"]

        IHL = (ip_header[0] & 0xf) * 4
        src_ip = ipaddress.IPv4Address(ip_header[8])
        dest_ip = ipaddress.IPv4Address(ip_header[9])
        print('SCTP Packet')
        sctp_packet = ip_packet[IHL:]
        if(len(sctp_packet) < 12):
            sctp_packet += b'0'*12
        sctp_header = struct.unpack("!HH4s4s", sctp_packet[:12])
        print('{0}:{1} -> {2}:{3}'.format(str(src_ip), str(sctp_header[0]), str(dest_ip), str(sctp_header[1])))
        sctp_data = sctp_packet[12:]
        bytes_parsed = 0
        print('sctp data length: {0}'.format(len(sctp_data)))
        while bytes_parsed < len(sctp_data)-3: # the last three bytes may not contain data but is part of sctp packet
            chunk_info = struct.unpack("!BBH", sctp_data[bytes_parsed:bytes_parsed+4])
            print('type: {0}, flags: {1}'.format(str(chunk_info[0]), str(chunk_info[1])), end=" ")
            print('length: {0}'.format(str(chunk_info[2])))
            chunk_data = sctp_data[bytes_parsed+4:bytes_parsed+chunk_info[2]]
            bytes_parsed += chunk_info[2]
            print("TYPE: ", chunk_type[chunk_info[0]])
            if chunk_info[0] == 0:
                data_info = struct.unpack("!4sHH4s", chunk_data[:12])
                print('TSN: ', str(int.from_bytes(data_info[0], byteorder='big', signed=False)), 'Stream Id: ', str(data_info[1]), 'Stream seq num: ', data_info[2] , 'Payload protocol Id: ', str(int.from_bytes(data_info[3], byteorder='big', signed=False)))
                s1ap_packet = chunk_data[12:]
                PDU = S1AP.S1AP_PDU_Descriptions.S1AP_PDU
                PDU.from_aper(s1ap_packet)
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
    LOCAL_IP = "0.0.0.0" # IP address of this machine
    CORE_IP = "192.168.61.3" # mme ip address
    CORE_PORT = 36412
    MEC_IP = "192.168.61.3"
    MEC_PORT = 9001

    # create a raw socket for litsening
    # https://man7.org/linux/man-pages/man7/ip.7.html
#    ListenSock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_SCTP)
#    ListenSock.bind(("192.168.0.108", CORE_PORT))
#    buffer_size = 1024*1024
#    conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#    conn = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_TCP)

    conn = socket.socket(socket.AF_PACKET, socket.SOCK_DGRAM, socket.ntohs(3))
#    conn.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, buffer_size)
#    conn.bind(('wlp3s0', 0))
    
    # receive the traffic
#    ListenSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # IP, UDP
#    ListenSock.bind((LOCAL_IP, 9000)) # LOCAL, 2152
#    # send the traffic
#    ForwardSocket_teid = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#    ForwardSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    print("dispatcher started ...")
	
    while True:
        #print("waiting for packet")
        #packet, addr = ListenSock.recvfrom(2048)
        raw_data, addr = conn.recvfrom(4096)
        #print("received addr:", addr)
        #print('{}:{}'.format(addr[0], str(addr[1])))
	    # get header info

        parseIPPacket(raw_data)
        #parseSCTPPacket(raw_data)
        #parseIPPacket(packet)

#        Redirection, TEID, SRC_IP= getHeadInfo(gtp_pkg)
        #print(raw_data)
        #print(packet)

        # Test
        
        #m = hashlib.sha512()
        #data = "TEST.DATA"
        #m.update(data)
        #h = m.hexdigest()
        
        #pkt = str(SRC_IP) + str(",ulteid:") + str(TEID)

		#l = ForwardSocket.sendto(gtp_pkg,( "172.17.1.2", 7000 )) #MEC_IP, MEC_PORT     
#        l = ForwardSocket.sendto(gtp_pkg,( MEC_IP, MEC_PORT ))
		#print "end time: {0}, packet length: {1}".format(datetime.now(), len(gtp_pkg))
#        print("sending to MEC server...")
        
#        ForwardSocket.sendto( gtp_pkg, ( CORE_IP, CORE_PORT ))
#        print("sending to Core...")
		#print ""
    

	
if __name__ == '__main__' :
    main()


