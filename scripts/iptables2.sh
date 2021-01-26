sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

sudo iptables -t nat -I PREROUTING 1 -s 192.168.0.0/24 --dport 2152 -j DNAT --to-destination 192.168.61.5
sudo iptables -t nat -I PREROUTING 2 -s 192.168.0.0/24 -j DNAT --to-destination 192.168.61.3

