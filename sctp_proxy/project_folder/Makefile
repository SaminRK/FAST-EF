#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: sctp_dispatcher

sctp_dispatcher: sctp_primitives_client.o sctp_primitives_server.o backtrace.o sctp_common.o dynamic_memory_check.o bstrlib.o tcp_primitives_client.o
	$(CC) $(CFLAGS) -o sctp_dispatcher sctp_primitives_client.o sctp_primitives_server.o backtrace.o sctp_common.o dynamic_memory_check.o bstrlib.o tcp_primitives_client.o sctp_dispatcher.c -lsctp -pthread

sctp_primitives_server.o: sctp_primitives_server.c sctp_primitives_server.h
	$(CC) $(CFLAGS) -c sctp_primitives_server.c

sctp_primitives_client.o: sctp_primitives_client.c sctp_primitives_client.h
	$(CC) $(CFLAGS) -c sctp_primitives_client.c

bstrlib.o: bstrlib.c bstrlib.h
	$(CC) $(CFLAGS) -c bstrlib.c

dynamic_memory_check.o: dynamic_memory_check.c dynamic_memory_check.h
	$(CC) $(CFLAGS) -c dynamic_memory_check.c

backtrace.o: backtrace.c backtrace.h
	$(CC) $(CFLAGS) -c backtrace.c

sctp_common.o: sctp_common.c sctp_common.h
	$(CC) $(CFLAGS) -c sctp_common.c

tcp_primitives_client.o: tcp_primitives_client.c tcp_primitives_client.h
	$(CC) $(CFLAGS) -c tcp_primitives_client.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) count *.o *~
