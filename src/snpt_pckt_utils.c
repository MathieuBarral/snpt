#include "snpt.h"

void get_snpt_pckt_infos(snpt_pckt_t *pckt)
{
    printf("--------------------------------------\n");
    printf("flag: %d\n", pckt->flag);
    printf("data_size: %ld\n", pckt->data_size);
}

void encode_snpt_pckt(snpt_pckt_t *pckt)
{
    pckt->flag = htonl(pckt->flag);
    pckt->data_size = htonl(pckt->data_size);
}

void decode_snpt_pckt(snpt_pckt_t *pckt)
{
    pckt->flag = ntohl(pckt->flag);
    pckt->data_size = ntohl(pckt->data_size);
}