sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

sudo iptables -t nat -I OUTPUT 1 -d 127.0.0.1 -p tcp --dport 4043 -j DNAT --to-destination 192.168.0.106
