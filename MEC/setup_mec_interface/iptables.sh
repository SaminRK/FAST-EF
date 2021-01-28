#sudo iptables -t nat -A PREROUTING -p tcp -i brqee20f75a-69 --dst 10.0.0.2  -j DNAT --to-destination 10.0.2.7:7000
#sudo iptables -t nat -A PREROUTING -p tcp  -d 10.0.0.2  -j DNAT --to-destination 10.0.2.7:7000
#sudo iptables -t nat -A PREROUTING -p udp -i brq17d79419-c6 --dport 6006 -j DNAT --to-destination 10.0.2.3:6006
#sudo iptables -t nat -A PREROUTING -p tcp -i brq17d79419-c6 --dport 6002 -j DNAT --to 10.0.2.5:80
#sudo iptables -t nat -A PREROUTING -p tcp --dport 6002 -j DNAT --to 10.0.2.5:80
#sudo iptables -t nat -A PREROUTING -p tcp -i brq17d79419-c6 --dport 6003 -j DNAT --to-destination 10.0.2.2:80
sudo iptables -t nat -A PREROUTING -p udp -d 172.17.100.254 --dport 2152 -j DNAT --to-destination 172.17.1.2:7000
#sudo iptables -t nat -A PREROUTING -p udp -d 172.17.1.1 --dport 2152 -j DNAT --to-destination 172.17.1.3:7000
#sudo iptables -t nat -A PREROUTING -p udp -d 172.17.100.254 --dport 2152 -j DNAT --to-destination 10.0.2.101:7788
#sudo iptables -t nat -A PREROUTING -p udp -d 172.17.1.1 --dport 2152 -j DNAT --to-destination 172.17.1.3:2152
