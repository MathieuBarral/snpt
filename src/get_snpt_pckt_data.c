#include "snpt.h"

void check_err_type(uint16_t err_flag)
{
    switch (err_flag)
    {
        case SNPT_WRONG_USER_UUID:
            printf("Wrong User UUID\n");
            break;
        case SNPT_WRONG_TEAM_UUID:
            printf("Wrong Team UUID\n");
            break;
        case SNPT_WRONG_CHANNEL_UUID:
            printf("Wrong Channel UUID\n");
            break;
        case SNPT_WRONG_THREAD_UUID:
            printf("Wrong Thread UUID\n");
            break;
    }
}

void *get_data_buff(size_t size, uint8_t *data)
{
    uint8_t *data_buff = malloc(sizeof(uint8_t) * size);

    memcpy(data_buff, data, size);
    return (data_buff);
}

void *get_snpt_pckt_data(snpt_pckt_t *snpt_pckt)
{
    if (!snpt_pckt)
        return (NULL);
    if ((snpt_pckt->flag & SNPT_STATUS_MASK) == SNPT_ERR_CODE) {
        check_err_type(snpt_pckt->flag & SNPT_ERR_CODE_MASK);
        return (NULL);
    }
    return (get_data_buff(snpt_pckt->data_size, snpt_pckt->data));
}