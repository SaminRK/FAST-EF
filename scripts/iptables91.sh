sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# Samin
EPC_HOST='192.168.0.106'
# Sadman
EPC_HOST='192.168.1.103'

sudo iptables -t nat -I OUTPUT 1 -d 192.168.61.5 -p udp --dport 2152 -j DNAT --to-destination ${EPC_HOST}:7152
sudo iptables -t nat -I OUTPUT 2 -d 192.168.61.3 -j DNAT --to-destination ${EPC_HOST}
