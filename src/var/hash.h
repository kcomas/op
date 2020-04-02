
#pragma once

#include "var.h"
#include "string.h"

inline var* hash_new(size_t size) {
    var_hash* h = calloc(1, sizeof(var_hash) + sizeof(bucket) * size);
    h->size = size;
    return VAR_HASH(h);
}

void hash_free(var* hash);

#define HASH_GROWTH 2

var* hash_clone_resize(size_t new_size, var* hash);

void hash_insert(var* string, var* value, var** hash);
