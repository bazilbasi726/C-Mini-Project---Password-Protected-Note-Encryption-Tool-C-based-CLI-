#include <stdio.h>

#include "encrypt.h"

StatusCode encrypt_file(const NoteInfo *info, const char *password) {
    (void)info;
    (void)password;
    puts("encrypt_file stub");
    return STATUS_OK;
}

StatusCode decrypt_file(const NoteInfo *info, const char *password) {
    (void)info;
    (void)password;
    puts("decrypt_file stub");
    return STATUS_OK;
}
