sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# Samin
EPC_HOST='192.168.0.106'
ENB_NETWORK='192.168.0.0/24'
# Sadman
EPC_HOST='192.168.43.99'
ENB_NETWORK='192.168.43.224'

sudo iptables -t nat -I PREROUTING 1 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 7152 -j REDIRECT --to-ports 7000
sudo iptables -t nat -I PREROUTING 2 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 8152 -j REDIRECT --to-ports 7001
# sudo iptables -t nat -I PREROUTING 1 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 7152 -j DNAT --to-destination 192.168.61.5:2152
# sudo iptables -t nat -I PREROUTING 2 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 8152 -j DNAT --to-destination 192.168.61.9:2152
sudo iptables -t nat -I PREROUTING 3 -s ${ENB_NETWORK} -d ${EPC_HOST} -p sctp --dport 16412 -j DNAT --to-destination ${EPC_HOST}:36414
sudo iptables -t nat -I PREROUTING 4 -s ${ENB_NETWORK} -d ${EPC_HOST} -p sctp --dport 26412 -j DNAT --to-destination ${EPC_HOST}:36415
