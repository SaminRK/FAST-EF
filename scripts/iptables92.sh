sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# Samin
EPC_HOST='192.168.0.106'
ENB_NETWORK='192.168.0.0/24'
# Sadman
EPC_HOST='192.168.45.225'
ENB_NETWORK='192.168.45.220'

sudo iptables -t nat -I PREROUTING 1 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 7152 -j REDIRECT --to-ports 7000
sudo iptables -t nat -I PREROUTING 2 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 8152 -j REDIRECT --to-ports 7001
# sudo iptables -t nat -I PREROUTING 1 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 7152 -j DNAT --to-destination 192.168.61.5:2152
# sudo iptables -t nat -I PREROUTING 2 -s ${ENB_NETWORK} -d ${EPC_HOST} -p UDP --dport 8152 -j DNAT --to-destination 192.168.61.9:2152
sudo iptables -t nat -I PREROUTING 3 -s ${ENB_NETWORK} -d ${EPC_HOST} -p sctp --dport 16412 -j DNAT --to-destination ${EPC_HOST}:36414
sudo iptables -t nat -I PREROUTING 4 -s ${ENB_NETWORK} -d ${EPC_HOST} -p sctp --dport 26412 -j DNAT --to-destination ${EPC_HOST}:36415
# MEC Proxy -> MEC Manager 
sudo iptables -t nat -I PREROUTING 5 -s ${ENB_NETWORK} -d ${EPC_HOST} -p tcp --dport 8011 -j DNAT --to-destination 10.20.40.3:8000
sudo iptables -t nat -I PREROUTING 6 -s ${ENB_NETWORK} -d ${EPC_HOST} -p tcp --dport 8012 -j DNAT --to-destination 10.20.50.3:8000

