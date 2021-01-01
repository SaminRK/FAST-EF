## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

docker stop -t 0 prod-oai-mme
docker container rm prod-oai-mme

docker create --privileged --name prod-oai-mme --network prod-oai-public-net --ip 192.168.61.3 \
             -a stdin -a stdout --env-file ./mme-env.list oai-mme:production

docker network connect --ip 192.168.63.3 prod-oai-hss-net prod-oai-mme

echo start
docker start prod-oai-mme
docker attach prod-oai-mme #needed to attach in order to see output in terminal


