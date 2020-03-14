
#include "file.h"

var file_open(char filename[]) {
    int fd = open(filename, O_RDWR);
    if (fd == -1) return VAR_ERROR(FILE_NOT_FOUND);
    var_file* f = calloc(1, sizeof(var_file) + strlen(filename) + 1);
    f->fd = fd;
    strcpy(f->name, filename);
    return VAR_FILE(f);
}

extern inline void file_free(var file);
