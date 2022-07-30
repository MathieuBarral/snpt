#include "snpt.h"

void get_snpt_create_pckt_infos(snpt_create_pckt_t *snpt_create_pckt)
{
    printf("--------------------------------------\n");
    printf("uuid: %s\n", get_uuid_str(snpt_create_pckt->uuids[0]));
    printf("other_uuid: %s\n", get_uuid_str(snpt_create_pckt->uuids[1]));
    printf("name: %s\n", snpt_create_pckt->data[0]);
    printf("desc: %s\n", snpt_create_pckt->data[1]);
    printf("msg: %s\n", snpt_create_pckt->data[2]);
}

snpt_create_pckt_t *init_snpt_create_pckt(uuid_t **uuids, \
const char *name, const char *desc, const char *msg)
{
    snpt_create_pckt_t *new_create_pckt = \
    malloc(sizeof(snpt_create_pckt_t));
    if (!uuid_is_null(*uuids[0]))
        uuid_copy(new_create_pckt->uuids[0], *uuids[0]);
    if (!uuid_is_null(*uuids[1]))
        uuid_copy(new_create_pckt->uuids[1], *uuids[1]);
    memset(new_create_pckt->data[0], '\0', MAX_NAME_LENGTH);
    memset(new_create_pckt->data[1], '\0', MAX_DESCRIPTION_LENGTH);
    memset(new_create_pckt->data[2], '\0', MAX_BODY_LENGTH);
    strncpy(new_create_pckt->data[0], name, MAX_NAME_LENGTH);
    strncpy(new_create_pckt->data[1], desc, MAX_DESCRIPTION_LENGTH);
    strncpy(new_create_pckt->data[2], msg, MAX_BODY_LENGTH);
    return (new_create_pckt);
}