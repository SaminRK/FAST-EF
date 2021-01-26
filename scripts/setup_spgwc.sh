## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

DNS_IP_ADDRESS="8.8.8.8"
SECONDARY_DNS_IP_ADDRESS="8.8.4.4"

python3 component/oai-spgwc/ci-scripts/generateConfigFiles.py --kind=SPGW-C \
          --s11c=eth0 --sxc=eth0 --apn=apn1.carrier.com \
          --dns1_ip=$DNS_IP_ADDRESS --dns2_ip=$SECONDARY_DNS_IP_ADDRESS \
          --from_docker_file --env_for_entrypoint \
          --push_protocol_option=yes
