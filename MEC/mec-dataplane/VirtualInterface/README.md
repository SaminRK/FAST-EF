# Virtual Interface 
## Summary 
- Vif creates a virtual network device 'gtp0' and allocates an ip address to it. 
- Vif observes, with raw socket, GTP dataplane packets exchanged between eNB and SPGW-U. From these, it catches UE IP and uplink and downlink TEID allocated for a UE. 
- It creates a GTP tunnel with the TEIDs using `libgtpnl` library (?) 