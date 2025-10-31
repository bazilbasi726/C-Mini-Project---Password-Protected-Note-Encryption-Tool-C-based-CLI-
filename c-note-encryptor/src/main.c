#include <stdio.h>
#include "encrypt.h"
#include "loglist.h"

static void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s (-e|-d) <input> <output>\n", program_name);
}

int main(int argc, char *argv[]) {
    const char *program_name = (argc > 0 && argv && argv[0]) ? argv[0] : "c-note-encryptor";

    print_usage(program_name);
    puts("Scaffold executable placeholder - no functionality yet.");

    return 0;
}
