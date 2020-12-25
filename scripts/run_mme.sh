docker stop -t 0 prod-oai-mme
docker container rm prod-oai-mme

docker run --privileged --name prod-oai-mme --network prod-oai-public-net --ip 192.168.61.3 \
             --env-file ./mme-env.list oai-mme:production
