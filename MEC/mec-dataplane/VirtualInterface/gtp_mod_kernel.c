#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <net/if.h>

#include <libgtpnl/gtp.h>
#include <libgtpnl/gtpnl.h>
#include <libmnl/libmnl.h>
#include <errno.h>
#include <time.h>

#include "gtp_mod_kernel.h"


static struct {
  int                 genl_id;
  struct mnl_socket  *nl;
  bool                is_enabled;
} gtp_nl;


#define GTP_DEVNAME "gtpvif"
#define GTPV1U_UDP_PORT 2152

//------------------------------------------------------------------------------
int gtp_mod_kernel_init(int *fd0, int *fd1u, struct in_addr *ue_net, int mask, int gtp_dev_mtu)
{
  // we don't need GTP v0, but interface with kernel requires 2 file descriptors
  *fd0 = socket(AF_INET, SOCK_DGRAM, 0);
  *fd1u = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in sockaddr_fd0 = {
      .sin_family = AF_INET,
      .sin_port = htons(3386),
      .sin_addr = {
          .s_addr   = INADDR_ANY,
      },
  };
  struct sockaddr_in sockaddr_fd1 = {
      .sin_family = AF_INET,
      .sin_port = htons(GTPV1U_UDP_PORT),
      .sin_addr = {
          .s_addr   = INADDR_ANY,
      },
  };

  if (bind(*fd0, (struct sockaddr *) &sockaddr_fd0,
      sizeof(sockaddr_fd0)) < 0) {
    printf("bind GTPv0 port\n");
    return -1;
  }
  if (bind(*fd1u, (struct sockaddr *) &sockaddr_fd1,
      sizeof(sockaddr_fd1)) < 0) {
    printf("bind S1U port\n");
    return -1;
  }

  if (gtp_dev_create(-1, GTP_DEVNAME, *fd0, *fd1u) < 0) {
    printf("Cannot create GTP tunnel device: %s\n", strerror(errno));
    return -1;
  }
  gtp_nl.is_enabled = true;

  gtp_nl.nl = genl_socket_open();
  if (gtp_nl.nl == NULL) {
    printf("Cannot create genetlink socket\n");
    return -1;
  }
  gtp_nl.genl_id = genl_lookup_family(gtp_nl.nl, "gtp");
  if (gtp_nl.genl_id < 0) {
    printf("Cannot lookup GTP genetlink ID\n");
    return -1;
  }
  printf("Using the GTP kernel mode (genl ID is %d)\n", gtp_nl.genl_id);

  char buffer[50];
  memset(buffer, '\0', sizeof(char)*50);
  sprintf(buffer, "ip link set dev %s mtu %u", GTP_DEVNAME, gtp_dev_mtu);

  int ret = system ((const char *)buffer);
  if (ret) {
    printf("ERROR in system command %s: %d\n", buffer, ret);
    return -1;
  }

  struct in_addr ue_gw;
  ue_gw.s_addr = ue_net->s_addr | htonl(1);
  memset(buffer, '\0', 50);
  sprintf(buffer, "ip addr add %s/%u dev %s", inet_ntoa(ue_gw), mask, GTP_DEVNAME);
  ret = system ((const char *)buffer);
  if (ret) {
    printf("ERROR in system command %s: %d\n", buffer, ret);
    return -1;
  }



  if (gtp_dev_config(GTP_DEVNAME, ue_net, mask) < 0) {
    printf(        "Cannot add route to reach network\n");
    return -1;
  }


  return 1;
}

//------------------------------------------------------------------------------
void gtp_mod_kernel_stop(void)
{
  if (!gtp_nl.is_enabled)
    return;

  gtp_dev_destroy(GTP_DEVNAME);
}

//------------------------------------------------------------------------------
int gtp_mod_kernel_tunnel_add(struct in_addr ue, struct in_addr enb, uint32_t i_tei, uint32_t o_tei)
{
  struct gtp_tunnel *t;
  int ret;

  if (!gtp_nl.is_enabled)
    return 1;

  t = gtp_tunnel_alloc();
  if (t == NULL)
    return -1;


  gtp_tunnel_set_ifidx(t, if_nametoindex(GTP_DEVNAME));
  gtp_tunnel_set_version(t, 1);
  gtp_tunnel_set_ms_ip4(t, &ue);
  gtp_tunnel_set_sgsn_ip4(t, &enb);
  gtp_tunnel_set_i_tei(t, i_tei);
  gtp_tunnel_set_o_tei(t, o_tei);

  ret = gtp_add_tunnel(gtp_nl.genl_id, gtp_nl.nl, t);
  gtp_tunnel_free(t);

  return ret;
}

//------------------------------------------------------------------------------
int gtp_mod_kernel_tunnel_del(uint32_t i_tei, uint32_t o_tei)
{
  struct gtp_tunnel *t;
  int ret;

  if (!gtp_nl.is_enabled)
    return 1;

  t = gtp_tunnel_alloc();
  if (t == NULL)
    return -1;

  gtp_tunnel_set_ifidx(t, if_nametoindex(GTP_DEVNAME));
  gtp_tunnel_set_version(t, 1);
  gtp_tunnel_set_i_tei(t, i_tei);
  gtp_tunnel_set_o_tei(t, o_tei);

  ret = gtp_del_tunnel(gtp_nl.genl_id, gtp_nl.nl, t);
  gtp_tunnel_free(t);

  return ret;
}

//------------------------------------------------------------------------------
bool gtp_mod_kernel_enabled(void)
{
  return gtp_nl.is_enabled;
}
