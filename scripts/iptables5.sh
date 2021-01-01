sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

sudo iptables -t filter -I DOCKER-USER -d 192.168.0.0/16 -j ACCEPT
sudo iptables -t filter -I DOCKER-USER -d 192.168.0.0/16 -j ACCEPT

sudo iptables -t nat -I OUTPUT -d 192.168.0.0/16 -j DNAT --to-destination 192.168.0.108
sudo iptables -t nat -I PREROUTING -s 192.168.0.0/16 -d 192.168.0.106 -j DNAT --to-destination 192.168.61.3
