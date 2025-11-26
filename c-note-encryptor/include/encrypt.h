#ifndef C_NOTE_ENCRYPTOR_ENCRYPT_H
#define C_NOTE_ENCRYPTOR_ENCRYPT_H

#include "types.h"
#include "loglist.h"

#ifdef __cplusplus
extern "C" {
#endif

StatusCode encrypt_file(const NoteInfo *info, const char *password, LogNode **log);
StatusCode decrypt_file(const NoteInfo *info, const char *password, LogNode **log);

#ifdef __cplusplus
}
#endif

#endif /* C_NOTE_ENCRYPTOR_ENCRYPT_H */
