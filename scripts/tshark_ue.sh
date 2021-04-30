TIME_DIR="../archives/`date +%m-%d`_$1_enb_ue"

mkdir -p $TIME_DIR

UE_PCAP_FILE="$TIME_DIR/ue_`date +%m-%d`_$1.pcap"

sudo tshark -ni oaitun_ue1 -f 'not (udp port 5353 or udp port 1900 or arp)' -w $UE_PCAP_FILE