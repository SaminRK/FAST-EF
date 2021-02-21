sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# Samin
EPC_HOST='192.168.0.106'
ENB_NETWORK='192.168.0.0/24'
# Sadman
EPC_HOST='192.168.1.103'
ENB_NETWORK='192.168.1.0/24'

sudo iptables -t nat -I PREROUTING 1 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 2152 -j REDIRECT --to-ports 7000
sudo iptables -t nat -I PREROUTING 2 -s 192.168.0.0/24 -d 192.168.0.106 -p SCTP --dport 36412 -j REDIRECT --to-ports 9000
sudo iptables -t nat -I PREROUTING 3 -s 192.168.0.0/24 -d 192.168.0.106 -j DNAT --to-destination 192.168.61.3
#sudo iptables -t mangle -A PREROUTING -s 192.168.0.0/24 -j TEE --gateway 127.0.0.2
#sudo iptables -t nat -A PREROUTING -d 127.0.0.2 -j DNAT  --to 127.0.0.1:9000
