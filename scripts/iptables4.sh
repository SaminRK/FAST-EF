sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

sudo iptables -t nat -I PREROUTING 1 -d 192.168.0.108 -j DNAT --to-destination 192.168.61.2
sudo iptables -t nat -I OUTPUT 1 -s 192.168.61.2 -j DNAT --to-destination 192.168.0.106

