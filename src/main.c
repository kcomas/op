
#include "var/var.h"
#include "var/file.h"
#include "var/string.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    var file = file_open(argv[1]);
    printf("Using: ");
    printf("%s\n", file.data.file->name);
    var string = file_read(file);
    string_print(string);
    putchar('\n');
    file_free(file);
    string_free(string);
    return 0;
}
