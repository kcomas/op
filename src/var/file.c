
#include "file.h"

var* file_open(char filename[]) {
    int fd = open(filename, O_RDWR | O_APPEND);
    if (fd == -1) return VAR_ERROR(FILE_NOT_FOUND);
    var_file* f = calloc(1, sizeof(var_file) + strlen(filename) + 1);
    f->fd = fd;
    strcpy(f->name, filename);
    return VAR_FILE(f);
}

extern inline void file_free(var* file);

var* file_read_to_string(var* file) {
#if TYPECHECK
    assert(file->type == VAR_PFX(FILE));
#endif
    struct stat buf;
    if (stat(file->data.file->name, &buf) == -1) return VAR_ERROR(CANNOT_READ_FILE);
    var* string = string_new(buf.st_size);
    string->data.string->len = buf.st_size;
    if (read(file->data.file->fd, string->data.string->data, buf.st_size) != buf.st_size) {
        string_free(string);
        return VAR_ERROR(CANNOT_READ_FILE);
    }
    return string;
}
