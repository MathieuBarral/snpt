#include "snpt.h"

void get_snpt_sub_pckt_infos(snpt_sub_pckt_t *snpt_sub_pckt)
{
    printf("--------------------------------------\n");
    printf("team_uuid: %s\n", get_uuid_str(snpt_sub_pckt->team_uuid));
}

snpt_sub_pckt_t *init_snpt_sub_pckt(uuid_t team_uuid)
{
    snpt_sub_pckt_t *new_sub_pckt = malloc(sizeof(snpt_sub_pckt_t));

    if (!uuid_is_null((team_uuid)))
        uuid_copy(new_sub_pckt->team_uuid, team_uuid);
    return (new_sub_pckt);
}