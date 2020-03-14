
#pragma once

#include "var.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

var file_open(char filename[]);

inline void file_free(var file) {
    close(file.data.file->fd);
    free(file.data.file);
}

var file_read(var file);
