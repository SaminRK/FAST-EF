# Readme

## Run

We used 2 PCs. eNB and MEC proxy was run in 1 PC. EPC and freediameter relay nodes were run in another.

The components were run in the following sequence. Where not stated explicitly, the commands were run in FAST-EF repository.

### In eNB PC,

Create iptables rules to send traffic from eNB and MEC proxy to EPC PC

```
sh scripts/iptables91.sh
```

Run MEC proxy

```
npm run debug
```

### In EPC PC,

Create iptables rules to forward traffic to EPC and MEC components

```
sh scripts/iptables92.sh
```

We created two network namespaces that represent MEC. In each, a GTP interface is created and corresponding MEC components are run. (home = ne2 / ns2 / veth2 -> veth3, foreign = ne1 / ns1 / veth0 -> veth1)

```
cd scripts/
sh create_netns_home.sh
sh create_netns_foreign.sh
ne1='ip netns exec ns1'
ne2='ip netns exec ns2'
```

Run EPC components and freediameter relays. To run freediameter relays, you need to have freediameter installed. In openair-epc-fed repository,

```
sh two_epc_run.sh
```

Run tshark in 2 terminals to capture sctp, gtp or icmp packets.

```
tshark -ta -ni any -f sctp
tshark -ta -ni any -Y "gtp or icmp"
```

Run userplane dispatcher home, userplane dispatcher foreign (restart each time with epc)

```
cd MEC/mec-dataplane/mec-dataplane/Dispatcher/
python3 dispatcher.py -n [ home | foreign ]
```

Run vif home + foreign. This creates GTP interfaces with libgtpnl library. Make sure you install necessary requirements first

```
cd MEC/mec-dataplane/mec-dataplane/VirtualInterface/
make tc.out && [$ne2 | $ne1] ./tc.out
```

Create dummy interface inside network namespaces.

```
cd scripts
[ $ne2 | $ne1] ./create_device.sh
http server home, http server foreign
```

Run mec controller in home & foreign namespaces. This requires CryptoMobile and pycrate to be installed.

```
[ $ne2 |  $ne1 ] python3 controller.py [-u] [-s]
```

Run sctp proxy

```
cd MEC/sctp-proxy
make && ./sctp_dispatcher [ home | foreign ]
```

Run cellular oidc idp provider (restart each time with epc)

```
cd MEC/cellular-oidc/with-node
[ $ne2 | $ne1 ] npm run debug:inmec or , debug:[home | foreign]
```

Run MEC manager and AMS in home & foreign namespaces (restart with epc)

```
cd MEC/mec-controller/
[ $ne2 | $ne1 ] npm run debug:[home | foreign]
```

Run app backend home + foreign (restart with epc)

```
cd MEC/mec-app/backend
[ $ne2 | $ne1] npm run debug:[home | foreign]
```

Run app frontend home + foreign

```
cd MEC/mec-app/frontend-vanilla
npm run build
[ $ne2 | $ne1] http-server
```

Run tshark inside network namespaces

```
[$ne2 | $ne1] tshark -ni any
```

### Again in eNB PC,  
Run enb, ue from openairinterface5G repository

```
./enb_run.sh -n (home | foreign)
./ue_run.sh
```

After ue connects,

```
cd scripts
sh create_ue_routes.sh
```
