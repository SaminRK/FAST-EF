## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openairinterface5g/"

source oaienv
# Edit openair3/NAS/TOOLS/ue_eurecom_test_sfr.conf
cd cmake_targets/lte_build_oai/build
../../nas_sim_tools/build/conf2uedata -c $OPENAIR_HOME/openair3/NAS/TOOLS/ue_eurecom_test_sfr.conf -o .

sudo RFSIMULATOR=192.168.2.200 ./lte-uesoftmodem -C 2685000000 -r 50 --rfsim




