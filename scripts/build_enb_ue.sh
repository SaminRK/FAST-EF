## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openairinterface5g/"

source oaienv
cd cmake_targets/
./build_oai -C -w SIMU --eNB --UE

