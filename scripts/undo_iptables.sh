sudo sysctl net.ipv4.conf.all.forwarding=1

sudo iptables -P FORWARD ACCEPT # it is always needed to accept forwarding

sudo iptables -t nat -D OUTPUT 1
