#ifndef NOTE_TYPES_H
#define NOTE_TYPES_H

#include <stddef.h>

/**
 * Represents whether the tool should encrypt or decrypt a file.
 */
typedef enum {
    MODE_ENCRYPT = 0,
    MODE_DECRYPT
} EncryptionMode;

/**
 * Captures command-line derived information about the note transformation.
 */
typedef struct {
    const char *input_path;
    const char *output_path;
    EncryptionMode mode;
} NoteInfo;

/**
 * Bit-field flags describing validation state in the CLI layer.
 */
typedef struct {
    unsigned has_password : 1;
    unsigned io_ready : 1;
    unsigned mode_set : 1;
    unsigned reserved : 5;
} Flags;

/**
 * Placeholder status codes returned by transformation routines.
 */
typedef enum {
    STATUS_OK = 0,
    STATUS_INVALID_ARGUMENT,
    STATUS_IO_ERROR
} StatusCode;

#endif /* NOTE_TYPES_H */
