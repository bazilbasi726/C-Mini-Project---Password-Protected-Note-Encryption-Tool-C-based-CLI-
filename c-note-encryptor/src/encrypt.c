#include <stdio.h>
#include <string.h>

#include "encrypt.h"

static StatusCode xor_transform(const NoteInfo *info, const char *password) {
    if (info == NULL || password == NULL || info->input_path == NULL || info->output_path == NULL) {
        return STATUS_INVALID_ARGUMENT;
    }

    if (password[0] == '\0') {
        return STATUS_PASSWORD_ERROR;
    }

    if (strcmp(info->input_path, info->output_path) == 0) {
        return STATUS_INVALID_ARGUMENT;
    }

    FILE *input = fopen(info->input_path, "rb");
    if (!input) {
        return STATUS_IO_ERROR;
    }

    FILE *output = fopen(info->output_path, "wb");
    if (!output) {
        fclose(input);
        return STATUS_IO_ERROR;
    }

    /* Demonstrate fscanf/fprintf without altering the file contents. */
    long original_pos = ftell(input);
    if (original_pos != -1L) {
        char preview[64];
        if (fscanf(input, "%63s", preview) == 1) {
            fprintf(stderr, "[info] preview token: %s\n", preview);
        }
        fseek(input, original_pos, SEEK_SET);
    }

    unsigned char key = (unsigned char)password[0];
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        unsigned char out_ch = ((unsigned char)ch) ^ key;
        if (fputc(out_ch, output) == EOF) {
            fclose(input);
            fclose(output);
            return STATUS_IO_ERROR;
        }
    }

    StatusCode status = ferror(input) ? STATUS_IO_ERROR : STATUS_OK;
    fclose(input);
    fclose(output);
    return status;
}

StatusCode encrypt_file(const NoteInfo *info, const char *password) {
    return xor_transform(info, password);
}

StatusCode decrypt_file(const NoteInfo *info, const char *password) {
    return xor_transform(info, password);

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
#include "encrypt.h"

void encrypt_note(const char *input, char *output) {
    (void)input;
    (void)output;
}
