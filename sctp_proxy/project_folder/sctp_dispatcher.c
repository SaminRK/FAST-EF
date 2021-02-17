#include <arpa/inet.h>
#include <stdlib.h>

#include "sctp_primitives_server.h"
#include "sctp_primitives_client.h"

sctp_data_t client_config;

void server_to_client(uint8_t *buffer, uint32_t length, uint16_t ppid,
                      uint16_t stream) {
    client_sctp_send_msg((sctp_data_t *)&client_config, ppid, stream, buffer,
                         length);

}

int client_to_server(uint32_t assocId, uint32_t stream, uint8_t *buffer,
                     uint32_t length) {
    return server_sctp_send_msg(assocId, stream, buffer, length);
}

int main() {
    char *locals[] = {"192.168.0.108"};
    sctp_connect_to_remote_host(locals, 1, "192.168.61.3", 36412, SOCK_STREAM,
                                (sctp_data_t *)&client_config);

    sctp_init(client_config.instreams, client_config.outstreams);

    SctpInit sctp_init;
    sctp_init.ipv4 = 1;
    sctp_init.ipv6 = 1;
    sctp_init.nb_ipv4_addr = 1;
    sctp_init.nb_ipv6_addr = 0;
    sctp_init.ipv4_address = calloc(1, sizeof(struct in6_addr));
    inet_aton("192.168.61.3", (struct in_addr *)&sctp_init.ipv4_address[0]);
    sctp_init.port = 36414;
    sctp_init.ppid =
        18;  // https://www.iana.org/assignments/sctp-parameters/sctp-parameters.xhtml#sctp-parameters-25

    set_sctp_message_handler((server_sctp_recv_callback)&server_to_client);
    sctp_create_new_listener((SctpInit *)&sctp_init);

    // while (1) {
    //     sctp_run((sctp_data_t *)&client_config,
    //              (client_sctp_recv_callback)client_to_server);
    // }

    sctp_exit();
}