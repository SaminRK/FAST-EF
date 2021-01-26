## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

python3 component/oai-spgwu-tiny/ci-scripts/generateConfigFiles.py --kind=SPGW-U \
          --sxc_ip_addr=192.168.61.4 --sxu=eth0 --s1u=eth0 \
          --from_docker_file --env_for_entrypoint \
          --network_ue_nat_option=yes
