grep "TODO" to see what you may need to change

- Our IP of EPC: 172.17.100.254/16
      IP of eNB: 172.17.1.1/16


- MEC-setup.md: This document will teach you how to install gtp module in your MEC platform


- setup-mec-interface/
    --> There are two scripts should be executed before entering mec-dataplane/


- mec-dataplane/
    --> there are two programs should be executed:
        --> python Dispatcher/dispatcher.py (We use python2)

        --> sudo ./VirtualInterface/vif.out
            (However, you should compile it through Makefile in VirtualInterface/)
