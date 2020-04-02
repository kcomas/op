
#pragma once

#include "var.h"

inline var* string_new(size_t size) {
    var_string* s = calloc(1, sizeof(var_string) + size + 1);
    s->size = size;
    return VAR_STRING(s);
}

inline void string_free(var* string) {
#if TYPECHECK
    assert(string->type == VAR_PFX(STRING));
#endif
    free(string->data.string);
    var_free(string);
}

var* string_from_c(const char* c_string);
