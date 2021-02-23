# Virtual Interface

## Summary

- Vif creates a gtp network device 'gtpvif' and allocates an ip address to it.
- Vif observes, with raw socket, GTP dataplane packets exchanged between eNB and SPGW-U. From these, it catches UE IP and uplink and downlink TEID allocated for a UE.
- It creates a GTP tunnel with eNB for each UE keeping downlink TEID same as SPGW-U. This makes the host pc act as MEC server. Any traffic from this host to eNB would appear to be coming from SPGW-U.

## Operation

- Create tunnel
  - Ping from UE to any address (e.g. 8.8.8.8)
  - Turn on vif in the PC containing EPC. It will create a GTP tunnel from this PC for this UE. Now, UE can be pinged from this PC.
- Check that tunnel is created.
  - `ifconfig gtpvif`
  - Navigate to `libgtpnl/tools` and run `./gtp-tunnel list`
- Destroy GTP device
  - Navigate to `libgtpnl/tools` and run `./gtp-link del gtpvif`

## Useful Links

[libgtpnl homepage](https://osmocom.org/projects/linux-kernel-gtp-u/wiki)

[Linux kernel GTP module doc](https://github.com/torvalds/linux/blob/master/Documentation/networking/gtp.rst)

[Using GTP with libgtpnl](https://www.slideshare.net/kentaroebisawa/using-gtp-on-linux-with-libgtpnl)

[A simple script to create GTP tunnel with libgtpnl](https://github.com/abousselmi/gtp-gw)
