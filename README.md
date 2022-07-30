# Simple Network ProTocol

A simple binary based network protocol made for an Microsoft Teams type client/server communication.

The implemented functions are :

```c
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
```

## Build

To build the project you can use the following command :

```
make                build the project
make re             clean and rebuild the project
make clean          clean object files
make fclean         clean object files and shared library
```

The result of the build is and shared library file named `libsnpt.so`.