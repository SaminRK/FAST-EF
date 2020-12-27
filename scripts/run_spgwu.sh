## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

docker container rm prod-oai-spgwu-tiny

docker run --privileged --name prod-oai-spgwu-tiny --network prod-oai-public-net --ip 192.168.61.5 \
             --env-file ./spgwu-env.list oai-spgwu-tiny:production
