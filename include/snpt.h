#ifndef SNPT_H
    #define SNPT_H

    #include <stdint.h>
    #include <stdlib.h>
    #include <string.h>
    #include <uuid/uuid.h>
    #include <stdio.h>
    #include <arpa/inet.h>
    #include <stdbool.h>

    // SNPT binary mask
    #define SNPT_FLAG_MASK 0x0000ff
    #define SNPT_STATUS_MASK 0xff0000
    #define SNPT_OK_CODE_MASK 0x00ff00
    #define SNPT_EVENT_CODE_MASK 0x00ff00
    #define SNPT_ERR_CODE_MASK 0x00ff00

    // SNPT status code
    #define SNPT_ERR_CODE 0x010000
    #define SNPT_OK_CODE 0x020000

    // SNPT events code
    #define SNPT_TEAM_CREATED 0x000100
    #define SNPT_CHANNEL_CREATED 0x000200
    #define SNPT_THREAD_CREATED 0x000300
    #define SNPT_REPLY_CREATED 0x000400

    // SNPT errors code
    #define SNPT_WRONG_USER_UUID 0x000100
    #define SNPT_WRONG_TEAM_UUID 0x000200
    #define SNPT_WRONG_CHANNEL_UUID 0x000300
    #define SNPT_WRONG_THREAD_UUID 0x000400
    #define SNPT_EXISTING_UUID 0x000500
    #define SNPT_UNAUTHORIZED 0x000600

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define MAX_DATA_LENGTH 2048

    // SNPT operation code
    typedef enum snpt_flags_s {
        LOGIN_CODE = 0x000001,
        LOGOUT_CODE,
        LISTUSR_CODE,
        GETUSR_CODE,
        SEND_CODE,
        GETMSG_CODE,
        SUB_CODE,
        SUB_REQ_CODE,
        UNSUB_CODE,
        USE_CODE,
        CREATE_CODE,
        LIST_CODE,
        INFO_CODE,
        CALLBACK_CODE,
        EVENT_CODE
    } snpt_flags_t;

    typedef struct snpt_sub_pckt_s {
        uuid_t team_uuid;
    } snpt_sub_pckt_t;

    typedef struct snpt_msg_pckt_s {
        uuid_t dst_uuid;
        char msg[MAX_BODY_LENGTH];
    } snpt_msg_pckt_t;

    typedef struct snpt_create_pckt_s {
        uuid_t uuids[2];
        char data[3][MAX_BODY_LENGTH];
    } snpt_create_pckt_t;

    typedef struct snpt_env_pckt_s {
        uuid_t team_uuid;
        uuid_t channel_uuid;
        uuid_t thread_uuid;
    } snpt_env_pckt_t;

    typedef struct snpt_usr_pckt_s {
        uuid_t uuid;
        char username[MAX_NAME_LENGTH];
    } snpt_usr_pckt_t;

    typedef struct snpt_msg_s {
        uuid_t dst_uuid;
        uuid_t sen_uuid;
        char msg[MAX_BODY_LENGTH];
        struct snpt_msg_s *prev;
        struct snpt_msg_s *next;
    } snpt_msg_t;

    typedef struct snpt_threads_s {
        uuid_t thread_uuid;
        char name[MAX_NAME_LENGTH];
        snpt_msg_t *msg_list;
        struct snpt_threads_s *prev;
        struct snpt_threads_s *next;
    } snpt_threads_t;

    typedef struct snpt_channels_s {
        uuid_t channel_uuid;
        char name[MAX_NAME_LENGTH];
        char desc[MAX_DESCRIPTION_LENGTH];
        snpt_threads_t *threads_list;
        struct snpt_channels_s *prev;
        struct snpt_channels_s *next;
    } snpt_channels_t;

    typedef struct snpt_teams_s {
        uuid_t team_uuid;
        char name[MAX_NAME_LENGTH];
        char desc[MAX_DESCRIPTION_LENGTH];
        snpt_channels_t *channels_list;
        struct snpt_teams_s *prev;
        struct snpt_teams_s *next;
    } snpt_teams_t;

    typedef struct snpt_user_data_s {
        int fd;
        uuid_t uuid;
        bool is_usr_connected;
        char username[MAX_NAME_LENGTH];
        snpt_env_pckt_t *env;
        snpt_teams_t *sub_team;
        snpt_msg_t *msg_list;
        struct snpt_user_data_s *prev;
        struct snpt_user_data_s *next;
    } snpt_user_data_t;

    typedef struct snpt_pckt_s {
        snpt_flags_t flag;
        size_t data_size;
        uint8_t data[MAX_DATA_LENGTH];
    } snpt_pckt_t;

    snpt_pckt_t *init_snpt_pckt(snpt_flags_t flag, void *data, size_t data_size);
    void *get_snpt_pckt_data(snpt_pckt_t *snpt_pckt);
    void get_snpt_pckt_infos(snpt_pckt_t *pckt);
    snpt_msg_pckt_t *init_snpt_msg_pckt(uuid_t dst_uuid, const char *msg);
    void get_snpt_msg_pckt_infos(snpt_msg_pckt_t *snpt_msg_pckt);
    snpt_env_pckt_t *init_snpt_env_pckt(uuid_t team_uuid, uuid_t channel_uuid, uuid_t thread_uuid);
    void get_snpt_env_pckt_infos(snpt_env_pckt_t *snpt_env_pckt);
    snpt_create_pckt_t *init_snpt_create_pckt(uuid_t **uuids, const char *name, const char *desc, const char *msg);
    void get_snpt_create_pckt_infos(snpt_create_pckt_t *snpt_create_pckt);
    snpt_usr_pckt_t *init_snpt_usr_pckt(uuid_t usr_uuid, const char *username);
    void get_snpt_usr_pckt_infos(snpt_usr_pckt_t *snpt_usr_pckt);
    snpt_env_pckt_t *init_snpt_env_pckt(uuid_t team_uuid, uuid_t channel_uuid, uuid_t thread_uuid);
    void get_snpt_use_pckt_infos(snpt_env_pckt_t *snpt_use_pckt);
    snpt_sub_pckt_t *init_snpt_sub_pckt(uuid_t team_uuid);
    void get_snpt_sub_pckt_infos(snpt_sub_pckt_t *snpt_sub_pckt);
    void encode_snpt_pckt(snpt_pckt_t *pckt);
    void decode_snpt_pckt(snpt_pckt_t *pckt);
    uuid_t *get_new_uuid(void);
    char *get_uuid_str(uuid_t uuid);

#endif