echo removing past containers

docker stop -t 1 prod-oai-hss
docker container rm prod-oai-hss

## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/component/oai-hss"

echo creating new container

docker create --privileged --name prod-oai-hss --network prod-oai-private-net --ip 192.168.62.3 \
                -a stdin -a stdout --env-file ./hss-env.list oai-hss:production


docker network connect --ip 192.168.64.2 prod-oai-hss-overlay prod-oai-hss

echo start
docker start prod-oai-hss
docker attach prod-oai-hss #needed to attach in order to see output in terminal
