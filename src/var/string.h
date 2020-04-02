
#pragma once

#include "var.h"

inline var* string_new(size_t size) {
    var_string* s = calloc(1, sizeof(var_string) + size + 1);
    s->size = size + 1;
    return VAR_STRING(s);
}

var* string_from_c(const char* c_string);

var* string_clone_resize(size_t new_size, var* string);
