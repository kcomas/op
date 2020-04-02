
#pragma once

#include "var.h"

inline var* string_new(size_t size) {
    var_string* s = calloc(1, sizeof(var_string) + size + 1);
    s->size = size;
    return VAR_STRING(s);
}

var* string_from_c(const char* c_string);
