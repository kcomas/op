
#include "var/var.h"
#include "var/file.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    var file = file_open(argv[1]);
    printf("Using: ");
    printf("%s\n", file.data.file->name);
    file_free(file);
    return 0;
}
