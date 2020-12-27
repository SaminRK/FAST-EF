## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

docker container rm prod-oai-spgwc

docker run --privileged --name prod-oai-spgwc --network prod-oai-public-net --ip 192.168.61.4 \
             --env-file ./spgwc-env.list oai-spgwc:production
