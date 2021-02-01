sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

# sudo iptables -t nat -I PREROUTING 1 -s 192.168.0.0/24 -d 192.168.0.106 -p UDP --dport 2152 -j REDIRECT --to-ports 7000
# sudo iptables -t nat -I PREROUTING 2 -s 192.168.0.0/24 -d 192.168.0.106 -j DNAT --to-destination 192.168.61.3
sudo iptables -t mangle -A PREROUTING -p udp -s 192.168.0.0/24 --sport 1028:65535 -d 192.168.0.106 -j TEE --gateway 127.0.0.2
sudo iptables -t nat -A PREROUTING -p udp -m multiport --sports 1028:65535 -d 127.0.0.2 -j DNAT  --to 127.0.0.1:9000
