
#pragma once

#include "var.h"

inline var* hash_new(size_t size) {
    var_hash* h = calloc(1, sizeof(var_hash) + sizeof(bucket) * size);
    h->size = size;
    return VAR_HASH(h);
}

inline void hash_free(var* hash) {
#if TYPECHECK
    assert(hash->type == VAR_PFX(HASH));
#endif
    free(hash->data.hash);
    var_free(hash);
}

#define HASH_GROWTH 2

void hash_insert(var* string, var* value, var** hash);
