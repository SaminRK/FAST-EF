TIME_DIR="../archives/`date +%F`/`date +%H_%M`"

mkdir -p $TIME_DIR

SCTP_LOG_FILE="$TIME_DIR/sctp.pcap"

tshark -ni any -f sctp -w $SCTP_LOG_FILE