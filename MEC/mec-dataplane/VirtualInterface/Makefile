CC = gcc
CFLAGS = -g -Wall
INCLUDE = .
LIBS = -lgtpnl


#testvif.out: gtp_mod_kernel.o vif-controlplane.c
#	$(CC) $(CFLAGS) -o testvif.out gtp_mod_kernel.o vif-controlplane.c $(LIBS)
#	@chmod u+x testvif.out

tc.out: tunCreator.c gtp_mod_kernel.o
	$(CC) $(CFLAGS) -o tc.out gtp_mod_kernel.o tunCreator.c $(LIBS)
	@chmod u+x tc.out

vif.out: gtp_mod_kernel.o vif.c
	$(CC) $(CFLAGS) -o vif.out gtp_mod_kernel.o vif.c $(LIBS)
	@chmod u+x vif.out

gtp_mod_kernel.o: gtp_mod_kernel.c gtp_mod_kernel.h
	$(CC) $(CFLAGS) -c gtp_mod_kernel.c $(LIBS)
clean:
	@rm -rf vif.out *.o
