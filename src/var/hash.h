
#pragma once

#include "var.h"

inline var* hash_new(size_t size) {
    var_hash* h = calloc(1, sizeof(var_hash) + sizeof(bucket) * size);
    h->size = size;
    return VAR_HASH(h);
}

void hash_free(var* hash);

#define HASH_GROWTH 2

void hash_insert(var* string, var* value, var** hash);
