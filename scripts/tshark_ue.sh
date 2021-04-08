TIME_DIR="../archives/`date +%F`/`date +%H_%M`"

mkdir -p $TIME_DIR

UE_PCAP_FILE="$TIME_DIR/ue.pcap"

tshark -ni oaitun_ue1 -f 'not (udp port 5353 or udp port 1900 or arp)' -w $UE_PCAP_FILE