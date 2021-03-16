ip netns add ns
ip link add veth0 type veth peer name veth1
ip link set veth1 netns ns
ne1="ip netns exec ns"

# set address
ip addr add 10.20.40.2/24 dev veth0
$ne1 ip addr add 10.20.40.3/24 dev veth1
ip link set veth0 up
$ne1 ip link set veth1 up
$ne1 ip link set lo up

# set route
$ne1 ip route add default via 10.20.40.2
sysctl net.ipv4.ip_forward=1
iptables -t nat -A POSTROUTING -s 10.20.40.0/24 -d 0.0.0.0/0 -j MASQUERADE
