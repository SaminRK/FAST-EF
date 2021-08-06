#!/bin/bash

#eNB_IF=enx9cebe8304e7c
#eNB_MAC=9c:eb:e8:30:4e:7c
eNB_IF=enx00e04c68e53d
eNB_MAC=00:e0:4c:68:e5:3d

EPC_IF=enx00e04c68d6d7
EPC_MAC=00:e0:4c:68:d6:d7

# TODO: Change IF1, MAC1, IF2, MAC2 to your own interface

sudo ifconfig $eNB_IF up
sudo ifconfig $EPC_IF up

sudo ifconfig $eNB_IF 172.17.1.2/32
sudo ifconfig $EPC_IF 172.17.1.3/32
sudo arp -i $eNB_IF -s 172.17.100.254 $eNB_MAC pub
sudo arp -i $EPC_IF -s 172.17.1.1 $EPC_MAC pub

sudo route add -host 172.17.100.254 $EPC_IF
sudo route add -host 172.17.1.1  $eNB_IF

#sudo ip route add default via 172.17.1.2 dev $eNB_IF
#sudo route add -net 192.172.0.0 gw 172.17.1.1 netmask 255.255.255.0 dev $eNB_IF
#sudo route add -net 45.45.0.0 gw 172.17.1.1 netmask 255.255.255.0 dev $IF1

sudo sysctl -w net.ipv4.ip_forward=1
