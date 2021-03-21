sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT


sudo iptables -t nat -I PREROUTING 1 -d 192.168.0.106 -p tcp --dport 4043  -j DNAT --to-destination 10.0.2.1
