sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT

MY_IP=192.168.0.108

sudo iptables -t nat -I OUTPUT 1 -s $MY_IP -d 192.168.61.5 -p UDP --dport 2152 -j DNAT --to-destination $MY_IP:7000
