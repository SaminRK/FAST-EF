import argparse
import socket
import binascii
import struct
import requests
import json 
# import sysv_ipc
import hashlib
from datetime import datetime

is_subscribed = {}
AUTH_MODULE_ADDR = None

def check_if_subscribed(ip):
    if ip in is_subscribed:
        pass
    else: 
        response = requests.get(f"{AUTH_MODULE_ADDR}/user/data", params={'ip': ip})
        is_subscribed[ip] = response.json()
    
    print('is_subscribed', is_subscribed)
    return True 

def getHeadInfo(raw_packet) :

    gtp_length = 8
    ip_length = 20
    udp_length = 8
    tcp_length = 20
    udp_dport = 0
    # registered mec server
    server_list = []
    server_list.append("192.168.21.2")
    server_list.append("12.1.1.31")     # MEC Gateway
    #server_list.append("192.172.0.1")
    #server_list.append("45.45.0.1") #MNC
    #server_list.append("10.0.2.11")
    #server_list.append("10.0.2.9")
    #server_list.append("10.0.2.7")
    #server_list.append("10.0.2.6")
    #server_list.append("10.0.2.101")
    #server_list.append("45.45.0.2")
    
    # get gtp header
    gtp_header = struct.unpack("!BBHL", raw_packet[:gtp_length])
   	#print "GTP Header : "
   	#print "Flags : {0}".format(gtp_header[0])
   	#print "Message Type : {0}".format(g-tp_header[1])
   	#print "Length : {0}".format(gtp_header[2])
    # get ip header
    ip_packet = raw_packet[gtp_length:]
    if(len(ip_packet) < 24):
        ip_packet += b'0'*24

    #if(len(ip_packet) < 20):
    #    ip_packet += b'0'*20


    ip_header = struct.unpack("BBHHHBBH4s4s", ip_packet[:ip_length])
    #ip_header = struct.unpack("BBHHHBBH4s4s4s", ip_packet[:24]) #MNC
	
    IHL = (ip_header[0] & 0xf) * 4

    if ip_header[6] == 6: #tcp
        tcp_packet = ip_packet[IHL:]
        if(len(tcp_packet) < 4):
            tcp_packet += b'0'*4
        tcp_header = struct.unpack("!HH", tcp_packet[:4])
    #	print "TCP header"
    #	print "IP Header : "
    #	print "From: {0} --> to: {1}".format(socket.inet_ntoa(ip_header[8]), socket.inet_ntoa(ip_header[9]))
    elif ip_header[6] == 17: #udp
        udp_packet = ip_packet[IHL:]
        if(len(udp_packet) < 8):
            udp_packet += b'0'*8    
        udp_header = struct.unpack("!HHHH", udp_packet[:udp_length])
        udp_sport = udp_header[0]
        udp_dport = udp_header[1]
        #print "ip dst: {0}, udp port: {1}".format(socket.inet_ntoa(ip_header[9]), udp_sport)
    
    ip_src = socket.inet_ntoa(ip_header[8])
    ip_dest = socket.inet_ntoa(ip_header[9])
    print('ip source', ip_src, 'ip dest', ip_dest)
    
    for i in server_list:    
        if ip_dest == i:# or udp_dport == 53: #//MNC: 10 
            # Access control
            if ip_dest == server_list[0]:
                check_if_subscribed(ip_src)
            
            return True, gtp_header[3], ip_src # MNC: 9
    return False, gtp_header[3], ip_src        # MNC: 9

# Run 
# (foreign) python3 dispatcher.py -n foreign 
# (home) python3 dispatcher.py -n home

def main() :
    global AUTH_MODULE_ADDR
    
    my_parser = argparse.ArgumentParser()
    my_parser.add_argument('-n', '--network', type=str, help='network (home | foreign)')
    args = my_parser.parse_args()

    LOCAL_IP = "0.0.0.0" # IP address of this machine
    CORE_PORT = 2152
    MEC_PORT = 2152

    if args.network == 'foreign':
        CORE_IP = '192.168.61.5'    # spgwu ip address
        MEC_IP = '10.20.40.3'
        LOCAL_PORT = 7000
        AUTH_MODULE_ADDR = "http://10.20.40.3:15005"
    else:
        CORE_IP = '192.168.61.9'
        MEC_IP = '10.20.50.3'
        LOCAL_PORT = 7001
        AUTH_MODULE_ADDR = "http://10.20.50.3:15005"

    # receive the traffic
    ListenSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # IP, UDP
    ListenSock.bind((LOCAL_IP, LOCAL_PORT)) # LOCAL, 2152
    # send the traffic
    ForwardSocket_teid = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    ForwardSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    print("dispatcher started ...")
	
    while True:
        print("waiting for packet")
        gtp_pkg, addr = ListenSock.recvfrom(2048)
		#print "received addr:", addr
		#print '{}:{}'.format(addr[0], str(addr[1]))    
	    # get header info

        Redirection, TEID, SRC_IP= getHeadInfo(gtp_pkg)
        print(gtp_pkg)

        # Test
        
        #m = hashlib.sha512()
        #data = "TEST.DATA"
        #m.update(data)
        #h = m.hexdigest()
        
        #pkt = str(SRC_IP) + str(",ulteid:") + str(TEID)
        if Redirection:
			#l = ForwardSocket.sendto(gtp_pkg,( "172.17.1.2", 7000 )) #MEC_IP, MEC_PORT     
            l = ForwardSocket.sendto(gtp_pkg,( MEC_IP, MEC_PORT ))      
			#print "end time: {0}, packet length: {1}".format(datetime.now(), len(gtp_pkg))
            print("sending to MEC server...")
        else:
            ForwardSocket.sendto( gtp_pkg, ( CORE_IP, CORE_PORT ))
            print("sending to Core...")
		    #print ""
    

	
if __name__ == '__main__' :
    main()


