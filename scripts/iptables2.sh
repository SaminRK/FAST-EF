sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# Samin
EPC_HOST='192.168.0.106'
ENB_NETWORK='192.168.0.0/24'
# Sadman
#EPC_HOST='192.168.1.103'
#ENB_NETWORK='192.168.1.105'

sudo iptables -t nat -I PREROUTING 1 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 2152 -j DNAT --to-destination 192.168.61.5
sudo iptables -t nat -I PREROUTING 2 -s ${ENB_NETWORK} -d ${EPC_HOST} -j DNAT --to-destination 192.168.61.3
