
#include "var/var.h"
#include "var/string.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    var filestring = string_from_c(argv[1]);
    printf("Using: ");
    string_print(filestring);
    putchar('\n');
    string_free(filestring);
    return 0;
}
