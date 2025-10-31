#ifndef NOTE_ENCRYPT_H
#define NOTE_ENCRYPT_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

StatusCode encrypt_file(const NoteInfo *info, const char *password);
StatusCode decrypt_file(const NoteInfo *info, const char *password);

#ifdef __cplusplus
}
#endif

#endif /* NOTE_ENCRYPT_H */
