
#pragma once

#include "var.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

inline var file_new(char filename[]) {
    var_file* f = calloc(1, sizeof(var_file) + strlen(filename) + 1);
    strcpy(f->name, filename);
    f->fd = -1;
    return VAR_FILE(f);
}

inline void file_free(var file) {
    free(file.data.file);
}
