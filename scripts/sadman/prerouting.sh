
# Redirect - to check which one works
# not checked with enb
sudo iptables -t nat -I PREROUTING 1 -s 192.168.1.105 -p UDP --dport 2152 -j REDIRECT --to-ports 7000
# not checked with enb
sudo iptables -t nat -A PREROUTING -p udp -d 127.0.0.1/24 --dport 1153 -j DNAT --to-destination 127.0.0.1:7000

# iptables -t nat -I PREROUTING -p udp -d 127.0.0.1 --dport 1153 -j DNAT --to-destination 192.168.1.105
# Log - iptables -t nat -I PREROUTING -p udp -j LOG --log-level info

# doesn't work with enb
sudo iptables -t nat -I PREROUTING -p udp -d 192.168.61.5 --dport 2152 -j DNAT --to-destination 127.0.0.1:2152
# not valid
sudo iptables -t mangle -I PREROUTING -p udp -d 192.168.61.5 --dport 2152 -j DNAT --to-destination 127.0.0.1:2152
# does't work in one pc
sudo iptables -t nat -A OUTPUT -p udp --dport 2152 -d 192.168.61.5 -j DNAT --to-destination 127.0.0.1:2152