# FAST-EF

This repository contains the code and setup files for FAST-EF.


## Repository structure
	-- openair-epc-fed
	-- openairinterface5g
	-- MEC
		
	-- utils
		
	-- scripts (need to clean and generalise)
		-- installations, network setup, docker setups and run scripts
	-- assets
		-- image-of-implementation-setup.png

## Setup steps

### LTE Network
#### Core network
Clone the core network repository from [https://github.com/saadsakib/openair-epc-fed.git](https://github.com/saadsakib/openair-epc-fed.git). This repository is forked from [https://github.com/OPENAIRINTERFACE/openair-epc-fed.git](https://github.com/OPENAIRINTERFACE/openair-epc-fed.git) by openairinterface. The author @Sadman has added roaming protocol in the core network which was not present in the original repository.
	```git clone https://github.com/saadsakib/openair-epc-fed.git```
Try following this documentation provided by openairinterface in order to deploy the core network [https://github.com/saadsakib/openair-epc-fed/blob/roaming/docs/DEPLOY_HOME.md](https://github.com/saadsakib/openair-epc-fed/blob/roaming/docs/DEPLOY_HOME.md)

We have used a script to setup the home and foreign core network. You can try and use that as well.
	```./open-air-fed/two_epc_run.sh```

#### RAN
Clone the RAN repository from [https://gitlab.eurecom.fr/oai/openairinterface5g.git](https://gitlab.eurecom.fr/oai/openairinterface5g.git)
	```git clone https://gitlab.eurecom.fr/oai/openairinterface5g.git```
Try following this documentation provided by openairinterface in order to deploy the RAN: Building the RAN [https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/master/doc/BUILD.md](https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/master/doc/BUILD.md) and running the RAN [https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/master/doc/RUNMODEM.md](https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/master/doc/RUNMODEM.md)

We have used a script to setup the enb and ue. You can try and use that as well.
	```./open-air-fed/ran_files/```
The conf files we have use for setup can also be found in this folder.
	
### MEC Setup

1. Installing dependencies for MEC dataplane. This can be found at [MEC/mec-dataplane/MEC-setup.md](MEC/mec-dataplane/MEC-setup.md)

2. Installing depepndencies for MEC controlplane. Installing pycrate. You can follow instructions provided in the repository of pycrate [https://github.com/P1sec/pycrate](https://github.com/P1sec/pycrate)

3. Setup network for the experiment. The network needs to be setup according to the number of machines used. We have setup the networks using the following scripts.

