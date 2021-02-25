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
//#define UE_SUBNET   "192.172.0.0"  //OAI
// TODO: Change UE_SUBNET
#define UE_SUBNET   "12.1.1.30"  //OAI

//#define UE_SUBNET   "45.45.0.0"  //NEXTEPC
#define CORE_IP     "192.168.61.5"  // SPGW-U IP
#define ENB_IP      "192.168.1.105"

typedef struct{
	char ip[50];
	int ul_teid;
	int dl_teid;
}client_info;

void client_info_init(client_info **clients, int size);
int update_info(client_info **c, char *ip, int teid, int direction, int size);
int process_packet(char *buffer, client_info **clients);
char *check_completed(client_info **clients, int size, int index);
void addr2str(struct in_addr *addr, char *str, int size);


int main(){

	// Initializing GTPV1U interface
	
	// Clean hard previous mappings.
	int rv = system ("rmmod gtp");
	int sockfd_raw;
	int fd0 = 0, fd1u = 0;
	
    rv = system ("modprobe gtp");
	if (rv != 0) {
		printf("ERROR in loading gtp kernel module (check if built in kernel)\n");
		return -1;
	}
	struct in_addr ueip;
    // char *pkt = (char *)malloc(sizeof(char) * MAXLINE);
	char pkt[MAXLINE] = {0};

    client_info *clients = (client_info *)malloc(sizeof(client_info) * MAX_CLIENTS);	
    client_info_init(&clients, MAX_CLIENTS);    


    
    inet_pton(AF_INET, UE_SUBNET, &(ueip));
	rv = gtp_mod_kernel_init(&fd0, &fd1u, &ueip, UE_NETMASK, SGI_MTU);
	printf("===kernel init rv===: %d\n", rv);

	struct in_addr enb = {.s_addr = 0};
	enb.s_addr = ((in_addr_t)192 |
	     ((in_addr_t)168 << 8) |
	     ((in_addr_t)1 << 16) |
	     ((in_addr_t)105 << 24));
	
    
    sockfd_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sockfd_raw < 0){
        perror("sockfd_raw");
        return -1;
    }
    
    struct sockaddr_in cli_addr; 
    int pp;
    int tunnel_created = 0;
	// receive ue info 	
	while(1){
        socklen_t len = sizeof(cli_addr);
    	memset(pkt, '\0', sizeof(char) * MAXLINE);

        recvfrom(sockfd_raw, pkt, MAXLINE, 0, (struct sockaddr*)&cli_addr, &len);
        pp = process_packet(pkt+14, &clients); // link eth_header length = 14
        
        if(pp != -1){
            for(int i = 0; i < 3; i++){
                //if(!strncmp(clients[i].ip, "45.45", 5))
                    // printf("index: %d, %s %x %x\n", i, clients[i].ip, clients[i].ul_teid, (unsigned int)clients[i].dl_teid);
            }   
            char *temp = check_completed(&clients, MAX_CLIENTS, pp);
    	    struct in_addr ue = {.s_addr = 0};
            if(temp && tunnel_created == 0){
                inet_pton(AF_INET, temp, &ue);
    	        rv = gtp_mod_kernel_tunnel_add(ue, enb, clients[pp].ul_teid, clients[pp].dl_teid);
    	        printf("ip = %s, ul = %d, dl = %x, ================add tunnel rv: %d================\n", 
                 clients[pp].ip, clients[pp].ul_teid, clients[pp].dl_teid, rv);
                tunnel_created = 1;
            }

        }
	}
    
	return 0;
}


void client_info_init(client_info **clients, int size){
    for(int i = 0; i < size; i++){
        memset((*clients)[i].ip, '\0', sizeof(clients[i]->ip));
        (*clients)[i].ul_teid = 0;
        (*clients)[i].dl_teid = 0;
    }
}    


int update_info(client_info **c, char *ip, int teid, int direction, int size){
    // direction 1: ul, direction 2: dl
    for(int i = 0; i < size; i++){
        //existed entry
        if(!strcmp((*c)[i].ip, ip)){
            if(direction == 1){
                (*c)[i].ul_teid = teid;
            }
            else if(direction == 2){
                (*c)[i].dl_teid = teid;
            }
            return i;
        }
        // new entry
        if(i == size-1){
            for(int j = 0; j < size; j++){
                if((*c)[j].ul_teid == 0){
                    strcpy((*c)[j].ip, ip); 
                    if(direction == 1){
                        (*c)[j].ul_teid = teid;
                    }
                    else if(direction == 2){
                        (*c)[j].dl_teid = teid;
                    }
                    return j;
                }
            }
        }
    }
    return -1;
}


void addr2str(struct in_addr *addr, char *str, int size){
    memset(str, '\0', sizeof(char) * size);
    inet_ntop(AF_INET, addr, str, 48);
}

int process_packet(char *buffer, client_info** clients){
    struct iphdr *iph = (struct iphdr*)buffer, *pl_iph = (struct iphdr*)(buffer+8+20+8); // IP:20 udp:8 gtp:8
    if(iph->protocol == 17){
        int iphdrlen = iph->ihl * 4; // change for auto registry
 
        struct udphdr *udph = (struct udphdr*)(buffer + iphdrlen);
        char *gtphdr = (char *)buffer;
        uint32_t *teid = (uint32_t*)(gtphdr+32);
        *teid = ntohl((uint32_t)*teid);
	    struct in_addr dst = {.s_addr = 0};
	    dst.s_addr = iph->daddr;
        char *dstip = malloc(sizeof(char) * ADDR_STRLEN);
        /*memset(dstip, '\0', sizeof(char) * ADDR_STRLEN);
        inet_ntop(AF_INET, &dst, dstip, 48);*/
	    struct in_addr src = {.s_addr = 0};
        addr2str(&dst, dstip, ADDR_STRLEN);
     
        src.s_addr = iph->saddr;
        char *srcip = malloc(sizeof(char) * ADDR_STRLEN);
        addr2str(&src, srcip, ADDR_STRLEN);
        /*memset(srcip, '\0', sizeof(char) * ADDR_STRLEN);
        inet_ntop(AF_INET, &src, srcip, 48);*/
        
        if(!strcmp(dstip, CORE_IP)){
            printf("src: %s, dst: %s:%hu, teid: %u\n", srcip, dstip, ntohs(udph->dest), *teid);
	        struct in_addr src = {.s_addr = 0};
            //printf("%x %x\n", pl_iph->saddr, pl_iph->daddr);
	        src.s_addr = pl_iph->saddr; //MNC :daddr
            char *ueip = malloc(sizeof(char) * ADDR_STRLEN);
            addr2str(&src, ueip, ADDR_STRLEN);
            /*memset(ueip, '\0', sizeof(char) * ADDR_STRLEN);
            inet_ntop(AF_INET, &src, ueip, 48);*/
            if(*teid == 0)
                *teid = 1;
            int pp = update_info(clients, ueip, *teid, 1, MAX_CLIENTS);
			free(srcip);
            free(dstip);
            free(ueip);
            return pp;
        }
        else if(!strcmp(dstip, ENB_IP)){
            printf("dst: %s:%hu, teid: %x\n", dstip, ntohs(udph->dest), *teid);
	        struct in_addr dst = {.s_addr = 0};
	        dst.s_addr = pl_iph->daddr;
            char *ueip = malloc(sizeof(char) * ADDR_STRLEN);
            addr2str(&dst, ueip, ADDR_STRLEN);
            /*memset(ueip, '\0', sizeof(char) * ADDR_STRLEN);
            inet_ntop(AF_INET, &dst, ueip, 48);*/
            int pp = update_info(clients, ueip, *teid, 2, MAX_CLIENTS);
			free(srcip);
            free(dstip);
            free(ueip);
            return pp;
        }
    }
    return -1;
}

char *check_completed(client_info **clients, int size, int index){
    if((*clients)[index].ul_teid != 0 && (*clients)[index].dl_teid != 0)
        return (*clients)[index].ip;
    return NULL;
}
