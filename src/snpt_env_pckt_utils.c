#include "snpt.h"

void get_snpt_env_pckt_infos(snpt_env_pckt_t *snpt_env_pckt)
{
    printf("--------------------------------------\n");
    printf("team_uuid: %s\n", get_uuid_str(snpt_env_pckt->team_uuid));
    printf("channel_uuid: %s\n", get_uuid_str(snpt_env_pckt->channel_uuid));
    printf("thread_uuid: %s\n", get_uuid_str(snpt_env_pckt->thread_uuid));
}

snpt_env_pckt_t *init_snpt_env_pckt(uuid_t team_uuid, uuid_t channel_uuid, \
uuid_t thread_uuid)
{
    snpt_env_pckt_t *new_env_pckt = malloc(sizeof(snpt_env_pckt_t));

    if (!uuid_is_null((team_uuid)))
        uuid_copy(new_env_pckt->team_uuid, team_uuid);
    if (!uuid_is_null((channel_uuid)))
        uuid_copy(new_env_pckt->channel_uuid, channel_uuid);
    if (!uuid_is_null((thread_uuid)))
        uuid_copy(new_env_pckt->thread_uuid, thread_uuid);
    return (new_env_pckt);
}