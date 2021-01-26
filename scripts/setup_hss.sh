## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/component/oai-hss/"

python3 ci-scripts/generateConfigFiles.py --kind=HSS \
           --cassandra=192.168.62.2 \
           --hss_s6a=192.168.61.2 \
           --apn1=apn1.carrier.com --apn2=apn2.carrier.com \
           --users=30 --imsi=320230100000001 \
           --ltek=0c0a34601d4f07677303652c0462535b --op=63bfa50ee6523365ff14c1f45f88737d \
           --nb_mmes=1 \
           --from_docker_file --env_for_entrypoint
