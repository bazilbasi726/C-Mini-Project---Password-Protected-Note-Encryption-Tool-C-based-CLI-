#ifndef C_NOTE_ENCRYPTOR_TYPES_H
#define C_NOTE_ENCRYPTOR_TYPES_H

#include <stddef.h>

/* Operational mode selected from the command line. */
typedef enum EncryptionMode {
    MODE_ENCRYPT = 0,
    MODE_DECRYPT
} EncryptionMode;

/* Aggregated paths and configuration captured from the CLI. */
typedef struct NoteInfo {
    const char *input_path;
    const char *output_path;
    EncryptionMode mode;
} NoteInfo;

/* Simple bit-field flags tracking validation state in main.c. */
typedef struct Flags {
    unsigned has_password : 1;
    unsigned io_ready : 1;
    unsigned mode_set : 1;
    unsigned reserved : 5;
} Flags;

/* Status codes shared across modules during the scaffold phase. */
typedef enum StatusCode {
    STATUS_OK = 0,
    STATUS_INVALID_ARGUMENT = 2,
    STATUS_IO_ERROR = 3,
    STATUS_PASSWORD_ERROR = 4
} StatusCode;

#endif /* C_NOTE_ENCRYPTOR_TYPES_H */
    STATUS_INVALID_ARGUMENT,
    STATUS_IO_ERROR
} StatusCode;

#endif /* C_NOTE_ENCRYPTOR_TYPES_H */
#ifndef TYPES_H
#define TYPES_H

typedef struct {
    char username[64];
    char password[64];
} user_credentials_t;

#endif
