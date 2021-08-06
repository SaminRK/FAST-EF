#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sctp_primitives_client.h"
#include "sctp_primitives_server.h"
#include "tcp_primitives_client.h"

sctp_data_t client_config;

void server_to_client(uint8_t *buffer, uint32_t length, uint16_t ppid,
                      uint16_t stream) {
    client_sctp_send_msg((sctp_data_t *)&client_config, ppid, stream, buffer,
                         length);
   send_msg(buffer, length);
}

int client_to_server(uint16_t stream, uint8_t *buffer, uint32_t length) {
    int ret = server_sctp_send_msg_to_first_assoc(stream, buffer, length);
    send_msg(buffer, length);
    return ret;
}

int main(int argc, char *argv[]) {
    // Samin
    // char epc_host[30] = "192.168.0.106"
    // Sadman
    char epc_host[30] = "192.168.45.225";
    char *locals[] = {epc_host};

    if(argc < 2){  
      printf("Usage %s (home | foreign) \n", argv[0]);
      exit(1);  
   }

    int sctp_dispatcher_port, mec_controller_port;
    char mme_ip[30], mec_controller_ip[30];
    mec_controller_port = 9001;
    if(!strcmp(argv[1], "foreign")) {
        strcpy(mme_ip, "192.168.61.3");
        strcpy(mec_controller_ip, "10.20.40.3");
        sctp_dispatcher_port = 36414;
    } else {
        strcpy(mme_ip, "192.168.61.7");
        strcpy(mec_controller_ip, "10.20.50.3");
        sctp_dispatcher_port = 36415;
    }

    sctp_connect_to_remote_host(locals, 1, mme_ip, 36412, SOCK_STREAM,
                                (sctp_data_t *)&client_config);

    sctp_init(client_config.instreams, client_config.outstreams);

    SctpInit sctp_init;
    sctp_init.ipv4 = 1;
    sctp_init.ipv6 = 1;
    sctp_init.nb_ipv4_addr = 1;
    sctp_init.nb_ipv6_addr = 0;
    sctp_init.ipv4_address = calloc(1, sizeof(struct in6_addr));
    inet_aton(epc_host, (struct in_addr *)&sctp_init.ipv4_address[0]);
    sctp_init.port = sctp_dispatcher_port;
    sctp_init.ppid =
        18;  // https://www.iana.org/assignments/sctp-parameters/sctp-parameters.xhtml#sctp-parameters-25

    set_sctp_message_handler((server_sctp_recv_callback)&server_to_client);
    
    /**
     * creates TCP connection to mec controller
    */
   connect_to_remote(mec_controller_ip, mec_controller_port);
    /**
     * Loops
    */
    sctp_create_new_listener((SctpInit *)&sctp_init);
    while (1) {
        sctp_run((sctp_data_t *)&client_config,
                 (client_sctp_recv_callback)client_to_server);
    }
    sctp_exit();
    // TODO: also close tcp connection
}
