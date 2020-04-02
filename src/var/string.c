
#include "string.h"

extern inline var* string_new(size_t size);

static inline var* string_copy(size_t size, size_t len, const uint8_t* buf) {
    var* s = string_new(size);
    s->data.string->len = len;
    memcpy(s->data.string->data, buf, len);
    return s;
}

var* string_from_c(const char* c_string) {
    size_t len = strlen(c_string);
    return string_copy(len, len, (uint8_t*) c_string);
}

var* string_clone_resize(size_t new_size, var* string) {
#if TYPECHECK
    assert(string->type == VAR_PFX(STRING));
#endif
    return string_copy(new_size, string->data.string->len, string->data.string->data);
}
