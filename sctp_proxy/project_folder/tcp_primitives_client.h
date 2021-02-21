#include <stdint.h>

int send_msg(uint8_t * buffer, uint32_t length);
int connect_to_remote(const char *ip_addr, uint16_t port);