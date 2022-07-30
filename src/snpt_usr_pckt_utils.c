#include "snpt.h"

void get_snpt_usr_pckt_infos(snpt_usr_pckt_t *snpt_usr_pckt)
{
    printf("--------------------------------------\n");
    printf("usr_uuid: %s\n", get_uuid_str(snpt_usr_pckt->uuid));
    printf("username: %s\n", snpt_usr_pckt->username);
}

snpt_usr_pckt_t *init_snpt_usr_pckt(uuid_t usr_uuid, const char *username)
{
    snpt_usr_pckt_t *new_usr_pckt = malloc(sizeof(snpt_usr_pckt_t));

    uuid_copy(new_usr_pckt->uuid, usr_uuid);
    strncpy(new_usr_pckt->username, username, MAX_NAME_LENGTH);
    return (new_usr_pckt);
}