/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the terms found in the LICENSE file in the root of this source tree.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file sctp_primitives_server.c
 *  \brief Main server primitives
 *  \author Sebastien ROUX, Lionel GAUTHIER
 *  \date 2013
 *  \version 1.0
 *  @ingroup _sctp
 *  @{
 */

#ifndef FILE_SCTP_PRIMITIVES_SERVER_SEEN
#define FILE_SCTP_PRIMITIVES_SERVER_SEEN

#include <stdint.h>

typedef uint32_t sctp_assoc_id_t;

/** \brief SCTP data received callback
 \param buffer pointer to buffer received
 \param length pointer to the length of buffer
 \param ppid packet protocol id
 \param stream stream no
 **/
typedef void (*server_sctp_recv_callback)(uint8_t *buffer, uint32_t length,
                                          uint16_t ppid, uint16_t stream);

typedef struct sctp_init_s {
    int ipv4, ipv6;
    int nb_ipv4_addr, nb_ipv6_addr;
    uint16_t port;
    struct in_addr *ipv4_address;
    struct in6_addr *ipv6_address;
    uint32_t ppid;
} SctpInit;

/** \brief SCTP Init function. Initialize SCTP layer
 \param nb_instreams
 \param nb_outstreams
 @returns -1 on error, 0 otherwise.
 **/
int sctp_init(int nb_instreams, int nb_outstreams);

int sctp_create_new_listener(SctpInit *init_p);
void set_sctp_message_handler(server_sctp_recv_callback handler);
int server_sctp_send_msg_to_first_assoc(uint16_t stream, const uint8_t *buffer,
                                        const uint32_t length);
int server_sctp_send_msg(sctp_assoc_id_t sctp_assoc_id, uint16_t stream,
                         const uint8_t *buffer, const uint32_t length);
void sctp_exit(void);

#endif /* FILE_SCTP_PRIMITIVES_SERVER_SEEN */

/* @} */
