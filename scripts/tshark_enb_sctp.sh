TIME_DIR="../archives/`date +%m-%d`_$1_enb_ue"

mkdir -p $TIME_DIR

SCTP_LOG_FILE="$TIME_DIR/sctp_`date +%m-%d`_$1.pcap"

tshark -ni any -f sctp -w $SCTP_LOG_FILE