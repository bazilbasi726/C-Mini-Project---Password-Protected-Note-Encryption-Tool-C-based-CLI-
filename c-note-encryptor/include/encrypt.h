#ifndef C_NOTE_ENCRYPTOR_ENCRYPT_H
#define C_NOTE_ENCRYPTOR_ENCRYPT_H

#include "types.h"
#include "loglist.h"

#ifdef __cplusplus
extern "C" {
#endif

StatusCode encrypt_file(const NoteInfo *info, const char *password, LogNode **log);
StatusCode decrypt_file(const NoteInfo *info, const char *password, LogNode **log);
StatusCode encrypt_file(const NoteInfo *info, const char *password);
StatusCode decrypt_file(const NoteInfo *info, const char *password);

#ifdef __cplusplus
}
#endif

#endif /* C_NOTE_ENCRYPTOR_ENCRYPT_H */
#ifndef ENCRYPT_H
#define ENCRYPT_H

void encrypt_note(const char *input, char *output);

#endif
