#include "snpt.h"

snpt_pckt_t *init_snpt_pckt(snpt_flags_t flag, void *data, size_t data_size)
{
    snpt_pckt_t *new_pckt = malloc(sizeof(snpt_pckt_t));

    memset(new_pckt, '\0', sizeof(snpt_pckt_t));
    new_pckt->flag = flag;
    new_pckt->data_size = data_size;
    memcpy(new_pckt->data, data, data_size);
    return (new_pckt);
}