
#pragma once

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "var.h"
#include "string.h"

var* file_open(char filename[]);

inline void file_free(var* file) {
#if TYPECHECK
    assert(file->type == VAR_PFX(FILE));
#endif
    close(file->data.file->fd);
    free(file->data.file);
    var_free(file);
}

var* file_read_to_string(var* file);
