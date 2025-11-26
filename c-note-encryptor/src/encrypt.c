#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "encrypt.h"
#include "loglist.h"

static void log_message(LogNode **log, const char *message) {
    if (log && message) {
        *log = loglist_append(*log, message);
    }
}

static void log_message_with_number(LogNode **log, const char *prefix, long value, const char *suffix) {
    if (!log || (!prefix && !suffix)) {
        return;
    }
    char buffer[128];
    int written = snprintf(buffer, sizeof(buffer), "%s%ld%s", prefix ? prefix : "", value, suffix ? suffix : "");
    if (written > 0) {
        log_message(log, buffer);
    }
}

static StatusCode xor_transform(const NoteInfo *info, const char *password, LogNode **log) {
    if (info == NULL || password == NULL || info->input_path == NULL || info->output_path == NULL) {
        log_message(log, "Invalid arguments provided to xor_transform.");
        return STATUS_INVALID_ARGUMENT;
    }

    if (password[0] == '\0') {
        log_message(log, "Password is empty.");
        return STATUS_PASSWORD_ERROR;
    }

    if (strcmp(info->input_path, info->output_path) == 0) {
        log_message(log, "Input and output paths cannot be the same.");
        return STATUS_INVALID_ARGUMENT;
    }

    FILE *input = fopen(info->input_path, "rb");
    if (!input) {
        log_message(log, "Failed to open input file.");
        return STATUS_IO_ERROR;
    }
    log_message(log, "Opened input file successfully.");

    FILE *output = fopen(info->output_path, "wb");
    if (!output) {
        log_message(log, "Failed to open output file for writing.");
        fclose(input);
        return STATUS_IO_ERROR;
    }
    log_message(log, "Opened output file successfully.");

    /* Demonstrate fscanf/fprintf without altering the file contents. */
    long original_pos = ftell(input);
    if (original_pos != -1L) {
        char preview[64];
        if (fscanf(input, "%63s", preview) == 1) {
            fprintf(stderr, "[info] preview token: %s\n", preview);
        }
        fseek(input, original_pos, SEEK_SET);
    }

    /* Detect zero-byte inputs and short-circuit with an empty output. */
    long file_size = -1L;
    if (fseek(input, 0, SEEK_END) == 0) {
        file_size = ftell(input);
        if (file_size == 0) {
            log_message(log, "Input file is empty; producing empty output.");
            fclose(input);
            fclose(output);
            return STATUS_OK;
        }
        fseek(input, 0, SEEK_SET);
    }

    unsigned char key = (unsigned char)password[0];
    int ch;
    long processed = 0;
    while ((ch = fgetc(input)) != EOF) {
        unsigned char out_ch = ((unsigned char)ch) ^ key;
        if (fputc(out_ch, output) == EOF) {
            log_message(log, "Failed to write transformed byte.");
            fclose(input);
            fclose(output);
            return STATUS_IO_ERROR;
        }
        processed++;
    }

    StatusCode status = ferror(input) ? STATUS_IO_ERROR : STATUS_OK;
    if (status == STATUS_OK) {
        log_message_with_number(log, "Processed ", processed, " bytes successfully.");
    } else {
        log_message(log, "Error detected during file transformation.");
    }

    fclose(input);
    fclose(output);
    return status;
}

StatusCode encrypt_file(const NoteInfo *info, const char *password, LogNode **log) {
    log_message(log, "Starting encryption.");
    StatusCode status = xor_transform(info, password, log);
    if (status == STATUS_OK) {
        log_message(log, "Encryption completed successfully.");
    }
    return status;
}

StatusCode decrypt_file(const NoteInfo *info, const char *password, LogNode **log) {
    log_message(log, "Starting decryption.");
    StatusCode status = xor_transform(info, password, log);
    if (status == STATUS_OK) {
        log_message(log, "Decryption completed successfully.");
    }
    return status;
}
