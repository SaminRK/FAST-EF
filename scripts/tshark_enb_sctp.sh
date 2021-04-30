TIME_DIR="../archives/`date +%F`"

mkdir -p $TIME_DIR

SCTP_LOG_FILE="$TIME_DIR/sctp_`date +%F`_$1.pcap"

tshark -ni any -f sctp -w $SCTP_LOG_FILE