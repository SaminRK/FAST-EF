#/*
# * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
# * contributor license agreements.  See the NOTICE file distributed with
# * this work for additional information regarding copyright ownership.
# * The OpenAirInterface Software Alliance licenses this file to You under
# * the OAI Public License, Version 1.1  (the "License"); you may not use this file
# * except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *      http://www.openairinterface.org/?page_id=698
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *-------------------------------------------------------------------------------
# * For more information about the OpenAirInterface (OAI) Software Alliance:
# *      contact@openairinterface.org
# */

LIBS	 = -lutil -pthread -lrt

CC = gcc
CFLAGS = -g -Wall
TARGET = UserProcess

default: $(TARGET)

$(TARGET): user_parser.o socket.o device.o parser.o stty.o
	$(CC) $(CFLAGS) $(LIBS) -o $(TARGET) user_simulator.c user_parser.o socket.o device.o parser.o commonDef.h stty.o

user_parser.o: user_parser.c
	$(CC) $(CFLAGS) $(LIBS) -c user_parser.c

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c

socket.o: socket.c commonDef.h
	$(CC) $(CFLAGS) -c socket.c

device.o: device.c
	$(CC) $(CFLAGS) -c device.c commonDef.h

stty.o: stty.c
	$(CC) $(CFLAGS) -c stty.c commonDef.h

clean: clean
	$(RM) $(TARGET) *.o



# default: sctp_dispatcher

# sctp_dispatcher: sctp_primitives_client.o sctp_primitives_server.o backtrace.o sctp_common.o dynamic_memory_check.o bstrlib.o tcp_primitives_client.o
# 	$(CC) $(CFLAGS) -o sctp_dispatcher sctp_primitives_client.o sctp_primitives_server.o backtrace.o sctp_common.o dynamic_memory_check.o bstrlib.o tcp_primitives_client.o sctp_dispatcher.c -lsctp -pthread

# sctp_primitives_server.o: sctp_primitives_server.c sctp_primitives_server.h
# 	$(CC) $(CFLAGS) -c sctp_primitives_server.c

# sctp_primitives_client.o: sctp_primitives_client.c sctp_primitives_client.h
# 	$(CC) $(CFLAGS) -c sctp_primitives_client.c

# bstrlib.o: bstrlib.c bstrlib.h
# 	$(CC) $(CFLAGS) -c bstrlib.c

# dynamic_memory_check.o: dynamic_memory_check.c dynamic_memory_check.h
# 	$(CC) $(CFLAGS) -c dynamic_memory_check.c

# backtrace.o: backtrace.c backtrace.h
# 	$(CC) $(CFLAGS) -c backtrace.c

# sctp_common.o: sctp_common.c sctp_common.h
# 	$(CC) $(CFLAGS) -c sctp_common.c

# tcp_primitives_client.o: tcp_primitives_client.c tcp_primitives_client.h
# 	$(CC) $(CFLAGS) -c tcp_primitives_client.c

# # To start over from scratch, type 'make clean'.  This
# # removes the executable file, as well as old .o object
# # files and *~ backup files:
# #
