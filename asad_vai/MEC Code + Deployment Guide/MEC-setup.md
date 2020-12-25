# MEC setup
###### tags: `MEC`

## Prerequisites

- For the support for GTP kernel module, your kernel version should be greater than **4.7**
- Linux distribution: We use **ubuntu 16.04.5**

### Flow
1. install libosmocore
2. install gtp kernel



#### Install libosmocore

```
$ git clone git://git.osmocom.org/libosmocore
$ cd libosmocore/
$ autoreconf -i
$ ./configure
$ make
$ sudo make install
$ sudo ldconfig -i
$ cd ..
```



:::warning
**If you encounter the problem following** 
```
configure.ac:17: error: possibly undefined macro: XXX
If this token and others are legitimate, please use m4_pattern_allow.
See the Autoconf documentation.
autoreconf: /usr/bin/autoconf failed with exit status: 1
```

**[ Solve ]**
```
$ sudo apt-get install libtool
```
:::


:::danger
If CONFIG_GTP is not enabled, you cannot use kernel GTP-U!
Check if package libc-ares-dev is installed and if not please add it.
:::


:::success
**prequesite :**   

```
$ sudo apt install libtalloc-dev libpcsclite-dev
$ sudo apt install libmnl-dev
$ sudo apt install libc-ares-dev
$ sudo apt-get install libghc-gnutls-dev
$ sudo apt-get install libsctp-dev
```
:::


* Then build libgtpnl like this :  

```
$ git clone git://git.osmocom.org/libgtpnl.git
$ cd libgtpnl
$ autoreconf -fi
$ ./configure
$ make
$ sudo make install
$ sudo ldconfig
```


* Build OsmoGGSN like this :

```
$ git clone git://git.osmocom.org/osmo-ggsn.git
$ cd osmo-ggsn
$ autoreconf -fi
$ ./configure --enable-gtp-linux
$ make
$ sudo make install
$ sudo ldconfig
```



* Following message is shown at end of the command: ./configure --enable-gtp-linux

```
OsmoGGSN Configuration:
  GTP Linux kernel support:            yes
```


### Using OpenGGSN with kernel which has GTP-U support¶


* In order to find out whether gtp.ko module is available we can enter following command:

```
$ find /lib/modules/`uname -r` -name gtp.ko
```

Output below shows that gtp.ko module is present:

```
/lib/modules/4.8.0-30-generic/kernel/drivers/net/gtp.ko
```

We are loading module gtp from kernel issuing command:

```
$ sudo modprobe gtp
```

when you enter:

```
$ lsmod | grep gtp
```
then more information about gtp and related udp tunnel can be obtained:

```
gtp                    28672  0
udp_tunnel             16384  1 gtp
```



