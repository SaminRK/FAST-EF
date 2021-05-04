sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# Samin
EPC_HOST='192.168.0.106'
# Sadman
EPC_HOST='192.168.45.225'

sudo iptables -t nat -I OUTPUT 1 -d 192.168.61.5 -p udp --dport 2152 -j DNAT --to-destination ${EPC_HOST}:7152
sudo iptables -t nat -I OUTPUT 2 -d 192.168.61.9 -p udp --dport 2152 -j DNAT --to-destination ${EPC_HOST}:8152
sudo iptables -t nat -I OUTPUT 3 -d 192.168.61.3 -p sctp --dport 36412 -j DNAT --to-destination ${EPC_HOST}:16412
sudo iptables -t nat -I OUTPUT 4 -d 192.168.61.7 -p sctp --dport 36412 -j DNAT --to-destination ${EPC_HOST}:26412
# MEC Proxy -> MEC Manager
sudo iptables -t nat -I OUTPUT 5 -d 10.20.40.3 -p tcp --dport 8000 -j DNAT --to-destination ${EPC_HOST}:8011
sudo iptables -t nat -I OUTPUT 6 -d 10.20.50.3 -p tcp --dport 8000 -j DNAT --to-destination ${EPC_HOST}:8012
