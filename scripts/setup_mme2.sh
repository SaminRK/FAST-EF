## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"


python3 component/oai-mme/ci-scripts/generateConfigFiles.py --kind=MME \
          --hss_s6a=192.168.63.2 --mme_s6a=192.168.63.3 \
          --mme_s1c_IP=192.168.61.3 --mme_s1c_name=eth0 \
          --mme_s10_IP=192.168.61.3 --mme_s10_name=eth0 \
          --mme_s11_IP=192.168.61.3 --mme_s11_name=eth0 \
          --spgwc0_s11_IP=192.168.61.4 \
          --mcc=320 --mnc=230 --tac_list="5 6 7" \
          --from_docker_file --env_for_entrypoint
