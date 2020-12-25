## corrections need to cd to correct directory before each stage

## move to project root directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR/../"

# colors
txtblk='\033[0;30m' # Black - Regular
txtred='\033[0;31m' # Red
txtgrn='\033[0;32m' # Green
txtblu='\033[0;34m' # Blue
txtpur='\033[0;35m' # Purple
txtwht='\033[0;37m' # White
txtrst='\033[0m'    # Text Reset

# removing previous repo
echo -e ${txtred}Removing existing repositories${txtrst}
rm -rf openair-epc-fed/

# download from oai
echo -e ${txtred}Downloading repository from OAI${txtrst}

git clone https://github.com/OPENAIRINTERFACE/openair-epc-fed.git
cd openair-epc-fed
git checkout master
git pull origin master
./scripts/syncComponents.sh

# building HSS
echo -e ${txtred}Building HSS${txtrst}

docker build --target oai-hss --tag oai-hss:production \
               --file component/oai-hss/docker/Dockerfile.ubuntu18.04 \
               component/oai-hss
docker image prune --force
docker image ls

# building MME
echo -e ${txtred}Building MME${txtrst}

docker build --target oai-mme --tag oai-mme:production \
               --file component/oai-mme/docker/Dockerfile.ubuntu18.04 component/oai-mme
docker image prune --force
docker image ls

# building SPGW-C
echo -e ${txtred}Building SPGW-C${txtrst}

docker build --target oai-spgwc --tag oai-spgwc:production \
               --file component/oai-spgwc/docker/Dockerfile.ubuntu18.04 component/oai-spgwc
docker image prune --force
docker image ls

# building SPGW-C
echo -e ${txtred}Building SPGW-U${txtrst}

docker build --target oai-spgwu-tiny --tag oai-spgwu-tiny:production \
               --file component/oai-spgwu-tiny/docker/Dockerfile.ubuntu18.04 component/oai-spgwu-tiny
docker image prune --force
docker image ls


## move back to last directory
cd -
