#include <stdio.h>

/* Type definition for the message header.
   Uses char underlying type for the msg_type which guarantees
   size of the header of 2 bytes regardless of compilation flags or target platform.
   Can be used with either C23, or with older C standard with compiler extensions enabled. */
typedef struct __attribute__((packed))
{
    enum : char
    {
        BROADCAST_MSG_TYPE,
        UNICAST_MSG_TYPE,
    } msg_type;
    char msg_len;
} msg_header_t;

/* Doesn't use underlying type for msg_type which may cause different size of msg_header_pre_c23_t depending
   on compiler options or platform */
typedef struct __attribute__((packed))
{
    enum
    {
        _BROADCAST_MSG_TYPE,
        _UNICAST_MSG_TYPE,
    } msg_type;
    char msg_len;
} msg_header_pre_c23_t;

int main(void)
{
    /* Always 2 bytes */
    printf("sizeof(msg_header_t)        : %zu bytes\n", sizeof(msg_header_t));

    /* Depends on platform and compilation flags. */
    printf("sizeof(msg_header_pre_c23_t): %zu bytes\n", sizeof(msg_header_pre_c23_t));
}
