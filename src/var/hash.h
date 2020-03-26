
#pragma once

#include "var.h"

inline var hash_new(size_t size) {
    var_hash* h = calloc(1, sizeof(var_hash) + sizeof(var_link) * size);
    h->size = size;
    return VAR_HASH(h);
}

inline void hash_free(var hash) {
    free(var.data.hash);
}
