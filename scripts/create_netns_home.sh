# default values 
NAME="ns2"
HOST_VETH_IP="10.20.50.2"
NETNS_VETH_IP="10.20.50.3"
VETH_NETWORK="10.20.50.0"

ip netns add $NAME
ip link add veth2 type veth peer name veth3
ip link set veth3 netns $NAME
ne2="ip netns exec $NAME"

# set address
ip addr add $HOST_VETH_IP/24 dev veth2
$ne2 ip addr add $NETNS_VETH_IP/24 dev veth3
ip link set veth2 up
$ne2 ip link set veth3 up
$ne2 ip link set lo up

# set route
$ne2 ip route add default via $HOST_VETH_IP
sysctl net.ipv4.ip_forward=1

iptables -t nat -A POSTROUTING -s $VETH_NETWORK/24 -d 0.0.0.0/0 -j MASQUERADE
