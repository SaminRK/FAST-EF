sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD DROP

sudo iptables -t nat -D OUTPUT 1
