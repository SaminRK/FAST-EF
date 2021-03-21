# default values 
NAME="ns1"
HOST_VETH_IP="10.20.40.2"
NETNS_VETH_IP="10.20.40.3"
VETH_NETWORK="10.20.40.0"

ip netns add $NAME
ip link add veth0 type veth peer name veth1
ip link set veth1 netns $NAME
ne1="ip netns exec $NAME"

# set address
ip addr add $HOST_VETH_IP/24 dev veth0
$ne1 ip addr add $NETNS_VETH_IP/24 dev veth1
ip link set veth0 up
$ne1 ip link set veth1 up
$ne1 ip link set lo up

# set route
$ne1 ip route add default via $HOST_VETH_IP
sysctl net.ipv4.ip_forward=1

iptables -t nat -A POSTROUTING -s $VETH_NETWORK/24 -d 0.0.0.0/0 -j MASQUERADE
