## SCTP Dispatcher

The MME, SCTP dispatcher and eNB should be started in order.

The SCTP dispatcher will be started from the terminal as follows:
`sctp_dispatcher --enb_ip 192.168.0.108 --mme_ip 192.168.61.3 --enb_port 36412 --mme_port 36412`

Currently we will hardcode all ip addresses and ports.

Steps:
1. Setup server side to connect to enb.
2. Relay messages from enb to mme.
* Create dummy mmes and enbs in necessary.

sctp_dispatcher process overview:
1. first it connects to mme.
2. it tries to get information about the associations opened with mme? or the number of streams with mme.
3. it opens server socket replicating the same configurations.
4. after setup, asses on changes in streams as required.
5. passes data from one side to another.