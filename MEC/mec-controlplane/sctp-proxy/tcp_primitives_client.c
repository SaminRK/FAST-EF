#include "tcp_primitives_client.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int sockfd;

int send_msg(uint8_t *buffer, uint32_t length) {
    if (send(sockfd, (const void *)buffer, length, 0) < 0) {
        printf("send packet failed");
        return -1;
    };

    return 0;
}

int connect_to_remote(const char *ip_addr, uint16_t port) {
    struct sockaddr_in servaddr;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        return -1;
    } else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip_addr);
    servaddr.sin_port = htons(port);

    // connect the client socket to server socket
    if (connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) !=
        0) {
        printf("connection with the server failed...\n");
        return -1;
    } else
        printf("connected to the server..\n");

    return 0;
}
