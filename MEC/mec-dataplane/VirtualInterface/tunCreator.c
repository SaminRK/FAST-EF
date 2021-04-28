#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <libgtpnl/gtp.h>
#include <libgtpnl/gtpnl.h>
#include <arpa/inet.h>
#include <linux/udp.h>
#include <linux/if_ether.h>
#include "gtp_mod_kernel.h"


#define UE_NETMASK  24
#define SGI_MTU     1500
#define LOCAL_PORT  5566
#define MAXLINE     4096
#define MAX_CLIENTS 30
#define ADDR_STRLEN 50

#define UE_SUBNET   "12.1.1.30"  
#define ENB_IP      "192.168.45.220"

typedef struct{
	char ip[50];
	int ul_teid;
	int dl_teid;
} ue_info;

int main(){
	int rv;
	// int rv = system ("rmmod gtp");
	int fd0 = 0, fd1u = 0;
	
    rv = system ("modprobe gtp");
	if (rv != 0) {
		printf("ERROR in loading gtp kernel module (check if built in kernel)\n");
		return -1;
	}
	struct in_addr ueip;
    
    inet_pton(AF_INET, UE_SUBNET, &(ueip));
	rv = gtp_mod_kernel_init(&fd0, &fd1u, &ueip, UE_NETMASK, SGI_MTU);
	printf("===kernel init rv===: %d\n", rv);

	struct in_addr enb = {.s_addr = 0};
	enb.s_addr = ((in_addr_t)192 |
	     ((in_addr_t)168 << 8) |
	     ((in_addr_t)45 << 16) |
	     ((in_addr_t)220 << 24));

    ue_info ue1;
    strcpy(ue1.ip, "12.1.1.2");
    ue1.ul_teid = 1;
    ue1.dl_teid = 0xca6fe0dd;
    
    struct in_addr ue = {.s_addr = 0};
    inet_pton(AF_INET, ue1.ip, &ue);
    rv = gtp_mod_kernel_tunnel_add(ue, enb, ue1.ul_teid, ue1.dl_teid);
    printf("ip = %s, ul = %d, dl = %x, ================add tunnel rv: %d================\n", 
        ue1.ip, ue1.ul_teid, ue1.dl_teid, rv);
    
	while(1);

    return 0;
}    