## move to openair-epc-fed directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

## without sleeps after docker instructions, it does not work
# Setup colors for colorful echos
RED='\033[0;31m'
NC='\033[0m' # No Color


# stop containers

echo -e ${RED} Stopping Containers ${NC}

docker stop -t 1 prod-cassandra prod-oai-hss prod-oai-mme prod-oai-spgwc prod-oai-spgwu-tiny
sleep 2

# remove containers

echo -e ${RED} Removing Containers ${NC}

docker container rm prod-cassandra prod-oai-hss prod-oai-mme prod-oai-spgwc prod-oai-spgwu-tiny
sleep 2

# list docker images

echo -e ${RED} Image List ${NC}
docker image ls

# run containers from images

echo -e ${RED} Running Cassandra ${NC}
docker run --name prod-cassandra -d -e CASSANDRA_CLUSTER_NAME="OAI HSS Cluster" \
             -e CASSANDRA_ENDPOINT_SNITCH=GossipingPropertyFileSnitch cassandra:2.1
sleep 2

echo -e ${RED} Running HSS ${NC}
docker run --privileged --name prod-oai-hss -d --entrypoint /bin/bash oai-hss:production -c "sleep infinity"
sleep 2

echo -e ${RED} Connecting HSS to public-net ${NC}
docker network connect prod-oai-public-net prod-oai-hss
sleep 2

echo -e ${RED} Running MME ${NC}
docker run --privileged --name prod-oai-mme --network prod-oai-public-net \
             -d --entrypoint /bin/bash oai-mme:production -c "sleep infinity"
sleep 2

echo -e ${RED} Running SPGW-C ${NC}
docker run --privileged --name prod-oai-spgwc --network prod-oai-public-net \
             -d --entrypoint /bin/bash oai-spgwc:production -c "sleep infinity"
sleep 2

echo -e ${RED} Running SPGW-U ${NC}
docker run --privileged --name prod-oai-spgwu-tiny --network prod-oai-public-net \
             -d --entrypoint /bin/bash oai-spgwu-tiny:production -c "sleep infinity"
sleep 2


# Setup CASSANDRA
echo -e ${RED} Cassandra Network Setup ${NC}
docker cp component/oai-hss/src/hss_rel14/db/oai_db.cql prod-cassandra:/home
docker exec -it prod-cassandra /bin/bash -c "nodetool status"
Cassandra_IP=`docker inspect --format="{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}" prod-cassandra`
echo -e ${RED} Cassandra IP address : ${Cassandra_IP} ${NC}
echo -e ${RED} Cassandra cqlsh ${NC}
docker exec -it prod-cassandra /bin/bash -c "cqlsh --file /home/oai_db.cql ${Cassandra_IP}"
sleep 2


# Setup HSS
echo -e ${RED} Setup HSS ${NC}
HSS_IP=`docker exec -it prod-oai-hss /bin/bash -c "ifconfig eth1 | grep inet" | sed -f ./ci-scripts/convertIpAddrFromIfconfig.sed`
python3 component/oai-hss/ci-scripts/generateConfigFiles.py --kind=HSS --cassandra=${Cassandra_IP} \
          --hss_s6a=${HSS_IP} --apn1=apn1.carrier.com --apn2=apn2.carrier.com \
          --users=200 --imsi=320230100000001 \
          --ltek=0c0a34601d4f07677303652c0462535b --op=63bfa50ee6523365ff14c1f45f88737d \
          --nb_mmes=1 --from_docker_file
docker cp ./hss-cfg.sh prod-oai-hss:/openair-hss/scripts
docker exec -it prod-oai-hss /bin/bash -c "cd /openair-hss/scripts && chmod 777 hss-cfg.sh && ./hss-cfg.sh"
sleep 2

# Setup MME
echo -e ${RED} Setup MME ${NC}
MME_IP=`docker inspect --format="{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}" prod-oai-mme`
SPGW0_IP=`docker inspect --format="{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}" prod-oai-spgwc`
python3 component/oai-mme/ci-scripts/generateConfigFiles.py --kind=MME \
          --hss_s6a=${HSS_IP} --mme_s6a=${MME_IP} \
          --mme_s1c_IP=${MME_IP} --mme_s1c_name=eth0 \
          --mme_s10_IP=${MME_IP} --mme_s10_name=eth0 \
          --mme_s11_IP=${MME_IP} --mme_s11_name=eth0 --spgwc0_s11_IP=${SPGW0_IP} \
          --mcc=320 --mnc=230 --tac_list="5 6 7" --from_docker_file
docker cp ./mme-cfg.sh prod-oai-mme:/openair-mme/scripts
docker exec -it prod-oai-mme /bin/bash -c "cd /openair-mme/scripts && chmod 777 mme-cfg.sh && ./mme-cfg.sh"
sleep 2

# Setup SGPW-C
echo -e ${RED} Setup SPGW-C ${NC}
YOUR_DNS_IP_ADDRESS=8.8.8.8
A_SECONDARY_DNS_IP_ADDRESS=8.8.4.4
python3 component/oai-spgwc/ci-scripts/generateConfigFiles.py --kind=SPGW-C \
          --s11c=eth0 --sxc=eth0 --apn=apn1.carrier.com \
          --dns1_ip=${YOUR_DNS_IP_ADDRESS} --dns2_ip=${A_SECONDARY_DNS_IP_ADDRESS} --from_docker_file
docker cp ./spgwc-cfg.sh prod-oai-spgwc:/openair-spgwc
docker exec -it prod-oai-spgwc /bin/bash -c "cd /openair-spgwc && chmod 777 spgwc-cfg.sh && ./spgwc-cfg.sh"
sleep 2

# Setup SPGW-U
echo -e ${RED} Setup SPGW-U ${NC}
python3 component/oai-spgwu-tiny/ci-scripts/generateConfigFiles.py --kind=SPGW-U \
          --sxc_ip_addr=${SPGW0_IP} --sxu=eth0 --s1u=eth0 --from_docker_file
docker cp ./spgwu-cfg.sh prod-oai-spgwu-tiny:/openair-spgwu-tiny
docker exec -it prod-oai-spgwu-tiny /bin/bash -c "cd /openair-spgwu-tiny && chmod 777 spgwu-cfg.sh && ./spgwu-cfg.sh"
sleep 2

# Starting Network functions with tracing

echo -e ${RED} Starting Network functions with tracing ${NC}
docker exec -d prod-oai-hss /bin/bash -c "nohup ./bin/oai_hss -j ./etc/hss_rel14.json --reloadkey true > hss_check_run.log 2>&1"
sleep 2
docker exec -d prod-oai-mme /bin/bash -c "nohup ./bin/oai_mme -c ./etc/mme.conf > mme_check_run.log 2>&1"
sleep 2
docker exec -d prod-oai-spgwc /bin/bash -c "nohup ./bin/oai_spgwc -o -c ./etc/spgw_c.conf > spgwc_check_run.log 2>&1"
sleep 2
docker exec -d prod-oai-spgwu-tiny /bin/bash -c "nohup ./bin/oai_spgwu -o -c ./etc/spgw_u.conf > spgwu_check_run.log 2>&1"

## move back to current directory
cd -

