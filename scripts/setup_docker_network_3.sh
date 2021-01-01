docker network rm prod-oai-public-net prod-oai-private-net prod-oai-hss-net

docker network create --attachable --subnet 192.168.61.0/26 --ip-range 192.168.61.0/26 prod-oai-public-net
docker network create --attachable --subnet 192.168.62.0/26 --ip-range 192.168.62.0/26 prod-oai-private-net
docker network create --attachable --subnet 192.168.63.0/26 --ip-range 192.168.63.0/26 prod-oai-hss-net


