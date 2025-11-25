#include <stdio.h>
#include <string.h>

#include "encrypt.h"
#include "loglist.h"

static void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s (-e|-d) <input> <output>\n", program_name);
}

static void trim_newline(char *buffer) {
    if (!buffer) {
        return;
    }
    size_t len = strcspn(buffer, "\n");
    buffer[len] = '\0';
}

int main(int argc, char *argv[]) {
    const char *program_name = (argc > 0 && argv && argv[0]) ? argv[0] : "c-note-encryptor";
    if (argc != 4) {
        print_usage(program_name);
        return STATUS_INVALID_ARGUMENT;
    }

    Flags flags = {0};
    NoteInfo info = {0};

    const char *mode_flag = argv[1];
    if (strcmp(mode_flag, "-e") == 0) {
        info.mode = MODE_ENCRYPT;
        flags.mode_set = 1;
    } else if (strcmp(mode_flag, "-d") == 0) {
        info.mode = MODE_DECRYPT;
        flags.mode_set = 1;
    } else {
        print_usage(program_name);
        return STATUS_INVALID_ARGUMENT;
    }

    info.input_path = argv[2];
    info.output_path = argv[3];

    char password[256];
    printf("Enter password: ");
    fflush(stdout);
    if (!fgets(password, sizeof(password), stdin)) {
        fprintf(stderr, "Failed to read password.\n");
        return STATUS_INVALID_ARGUMENT;
    }

    trim_newline(password);
    if (password[0] == '\0') {
        fprintf(stderr, "Password cannot be empty.\n");
        return STATUS_INVALID_ARGUMENT;
    }
    flags.has_password = 1;

    flags.io_ready = 1;

    StatusCode result = STATUS_OK;
    if (info.mode == MODE_ENCRYPT) {
        result = encrypt_file(&info, password);
    } else {
        result = decrypt_file(&info, password);
    }

    if (result != STATUS_OK) {
        fprintf(stderr, "Operation failed with status %d.\n", result);
    }

    (void)flags;
    return result;
#include "encrypt.h"
#include "loglist.h"
#include <stdio.h>

int main(void) {
    puts("C Note Encryptor placeholder");
    return 0;
}
