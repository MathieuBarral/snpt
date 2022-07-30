#include <stdlib.h>
#include <uuid/uuid.h>
#include <string.h>

char *get_uuid_str(uuid_t uuid)
{
    char *uuid_str = malloc(sizeof(char) * 37);

    memset(uuid_str, '\0', 37);
    uuid_unparse_lower(uuid, uuid_str);
    return (uuid_str);
}

uuid_t *get_new_uuid(void)
{
    uuid_t *new_uuid = malloc(sizeof(uuid_t));

    uuid_generate_random(*new_uuid);
    return (new_uuid);
}