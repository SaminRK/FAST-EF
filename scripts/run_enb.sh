## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../openairinterface5g/"

source oaienv
cd cmake_targets/lte_build_oai/build
ENODEB=1 sudo -E ./lte-softmodem -O $OPENAIR_HOME/ci-scripts/conf_files/lte-fdd-basic-sim.conf --basicsim


cd -
