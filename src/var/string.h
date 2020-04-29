
#pragma once

#include "var.h"

inline var *string_new(size_t size) {
    var_string *s = calloc(1, sizeof(var_string) + size + 1);
    s->size = size + 1;
    return VAR_STRING(s);
}

var *string_from_c(const char *c_string);

var *string_clone_resize(size_t new_size, var *string);

inline int string_cmp(var *sa, var *sb) {
#if TYPECHECK
    assert(sa->type == VAR_PFX(STRING));
    assert(sb->type == VAR_PFX(STRING));
#endif
    return strcmp((char*) sa->data.string->data, (char*) sb->data.string->data);

}
