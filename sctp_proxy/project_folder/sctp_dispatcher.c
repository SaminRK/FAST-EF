#include <arpa/inet.h>

#include "sctp_primitives_client.h"

int main() {
    char *locals[] = {"192.168.0.108"};
    sctp_data_t client_config;
    sctp_connect_to_remote_host(locals, 1, "192.168.61.3", 36412, SOCK_STREAM,
                                (sctp_data_t *)&client_config);

    while (1) {
        ;
    }
}