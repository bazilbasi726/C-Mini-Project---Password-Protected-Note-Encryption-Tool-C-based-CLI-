#include <stdio.h>
#include <string.h>

#include "encrypt.h"
#include "loglist.h"

static void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s (-e|-d) <input> <output>\n", program_name);
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    print_usage("c-note-encryptor");
    puts("Scaffold executable placeholder - no functionality yet.");

    return 0;
}
