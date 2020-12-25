echo removing past containers

docker stop -t 1 prod-oai-hss
docker container rm prod-oai-hss

cd component/oai-hss

echo creating new container

docker create --privileged --name prod-oai-hss --network prod-oai-private-net --ip 192.168.62.3 \
                -a stdin -a stdout --env-file ./hss-env.list oai-hss:production


docker network connect --ip 192.168.61.2 prod-oai-public-net prod-oai-hss

echo start
docker start prod-oai-hss
docker attach prod-oai-hss #needed to attach in order to see output in terminal

cd -

