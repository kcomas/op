
#pragma once

#include "var.h"

inline var string_new(size_t size) {
    var_string* s = calloc(1, sizeof(var_string) + size);
    s->size = size;
    return VAR_STRING(s);
}

inline void string_free(var string) {
    free(string.data.string);
}

var string_from_c(const char* c_string);
