#include "snpt.h"

void get_snpt_msg_pckt_infos(snpt_msg_pckt_t *snpt_msg_pckt)
{
    printf("--------------------------------------\n");
    printf("dst_uuid: %s\n", get_uuid_str(snpt_msg_pckt->dst_uuid));
    printf("msg: %s\n", snpt_msg_pckt->msg);
}

snpt_msg_pckt_t *init_snpt_msg_pckt(uuid_t dst_uuid, const char *msg)
{
    snpt_msg_pckt_t *new_msg_pckt = malloc(sizeof(snpt_msg_pckt_t));

    uuid_copy(new_msg_pckt->dst_uuid, dst_uuid);
    strncpy(new_msg_pckt->msg, msg, MAX_BODY_LENGTH);
    return (new_msg_pckt);
}