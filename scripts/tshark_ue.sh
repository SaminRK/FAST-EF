TIME_DIR="../archives/`date +%F`"

mkdir -p $TIME_DIR

UE_PCAP_FILE="$TIME_DIR/ue_`date +%F`_$1.pcap"

sudo tshark -ni oaitun_ue1 -f 'not (udp port 5353 or udp port 1900 or arp)' -w $UE_PCAP_FILE