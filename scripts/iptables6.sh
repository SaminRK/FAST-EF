sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

sudo iptables -t nat -I PREROUTING 1 -s 192.168.0.0/24 -d 192.168.0.108 -j DNAT --to-destination 192.168.63.2

