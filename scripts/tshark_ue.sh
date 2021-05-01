TIME_DIR="../archives/`date +%m-%d`_$1_enb_ue"

mkdir -p $TIME_DIR

# Run ./tshark_ue.sh 17-40 (h | f)

UE_PCAP_FILE="$TIME_DIR/ue_`date +%m-%d`_$1_$2.pcap"

sudo tshark -ni oaitun_ue1 -f 'not (udp port 5353 or udp port 1900 or arp)' -w $UE_PCAP_FILE
