## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openair-epc-fed/"

docker container rm prod-cassandra -f

docker run --name prod-cassandra --network prod-oai-private-net --ip 192.168.62.2 -d \
             -e CASSANDRA_CLUSTER_NAME="OAI HSS Cluster" \
             -e CASSANDRA_ENDPOINT_SNITCH=GossipingPropertyFileSnitch cassandra:2.1

docker cp component/oai-hss/src/hss_rel14/db/oai_db.cql prod-cassandra:/home
sleep 30 # fix later, try to avoid sleep
echo nodetool
docker exec -it prod-cassandra /bin/bash -c "nodetool status"

# cassandra needs time to start
sleep 10
echo cqlash
docker exec -it prod-cassandra /bin/bash -c "cqlsh --file /home/oai_db.cql 192.168.62.2"

