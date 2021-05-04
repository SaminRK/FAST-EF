ne1='ip netns exec ns1'
ne2='ip netns exec ns2'

  
TIME_DIR="../archives/`date +%m-%d`_$1_mec"

mkdir -p $TIME_DIR

HOME_LOG_FILE="$TIME_DIR/home_`date +%m-%d`_$1.pcap"
FOREIGN_LOG_FILE="$TIME_DIR/foreign_`date +%m-%d`_$1.pcap"

sudo $ne2 tshark -ni any -f 'not (udp port 5353 or udp port 1900 or arp)' -w $HOME_LOG_FILE &
sudo $ne1 tshark -ni any -f 'not (udp port 5353 or udp port 1900 or arp)' -w $FOREIGN_LOG_FILE