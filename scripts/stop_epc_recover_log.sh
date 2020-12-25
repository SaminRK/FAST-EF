## move to openair-epc-fed directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

# Setup colors for colorful echos
RED='\033[0;31m'
NC='\033[0m' # No Color

# Stopping 
echo -e ${RED}Stopping containers${NC}

docker exec -it prod-oai-hss /bin/bash -c "killall --signal SIGINT oai_hss tshark tcpdump"
docker exec -it prod-oai-mme /bin/bash -c "killall --signal SIGINT oai_mme tshark tcpdump"
docker exec -it prod-oai-spgwc /bin/bash -c "killall --signal SIGINT oai_spgwc tshark tcpdump"
docker exec -it prod-oai-spgwu-tiny /bin/bash -c "killall --signal SIGINT oai_spgwu tshark tcpdump"
sleep 10
docker exec -it prod-oai-hss /bin/bash -c "killall --signal SIGKILL oai_hss tshark tcpdump"
docker exec -it prod-oai-mme /bin/bash -c "killall --signal SIGKILL oai_mme tshark tcpdump"
docker exec -it prod-oai-spgwc /bin/bash -c "killall --signal SIGKILL oai_spgwc tshark tcpdump"
docker exec -it prod-oai-spgwu-tiny /bin/bash -c "killall --signal SIGKILL oai_spgwu tshark tcpdump"

# Recovering logs 
date_dir="`date +%F`"
time_dir="`date +%H_%M`"
archive_dir=./archives
#cd $archive_dir
# [ -d $date_dir ] || mkdir $date_dir
# cd $date_dir
# [ -d $time_dir ] || mkdir $time_dir
log_dir=$archive_dir/$date_dir/$time_dir
mkdir -p $log_dir/oai-hss-cfg $log_dir/oai-mme-cfg $log_dir/oai-spgwc-cfg $log_dir/oai-spgwu-cfg

# retrieve the modified configuration files
docker cp prod-oai-hss:/openair-hss/etc/. $log_dir/oai-hss-cfg
docker cp prod-oai-mme:/openair-mme/etc/. $log_dir/oai-mme-cfg
docker cp prod-oai-spgwc:/openair-spgwc/etc/. $log_dir/oai-spgwc-cfg
docker cp prod-oai-spgwu-tiny:/openair-spgwu-tiny/etc/. $log_dir/oai-spgwu-cfg

# Then, the logs
docker cp prod-oai-hss:/openair-hss/hss_check_run.log $log_dir
docker cp prod-oai-mme:/openair-mme/mme_check_run.log $log_dir
docker cp prod-oai-spgwc:/openair-spgwc/spgwc_check_run.log $log_dir
docker cp prod-oai-spgwu-tiny:/openair-spgwu-tiny/spgwu_check_run.log $log_dir

# Finally the PCAP.
docker cp prod-oai-hss:/tmp/hss_check_run.pcap $log_dir
docker cp prod-oai-mme:/tmp/mme_check_run.pcap $log_dir
docker cp prod-oai-spgwc:/tmp/spgwc_check_run.pcap $log_dir
docker cp prod-oai-spgwu-tiny:/tmp/spgwu_check_run.pcap $log_dir

echo -e ${RED}Collecting logs${NC}

# stop containers
echo -e ${RED} Stopping Containers ${NC}

docker stop -t 1 prod-cassandra prod-oai-hss prod-oai-mme prod-oai-spgwc prod-oai-spgwu-tiny
sleep 2

## move back to current directory
cd -

