
#include "string.h"

extern inline var* string_new(size_t size);

extern inline void string_free(var* string);

var* string_from_c(const char* c_string) {
    size_t size = strlen(c_string) + 1;
    var* s = string_new(size);
    s->data.string->len = size;
    memcpy(s->data.string->data, c_string, size);
    return s;
}
