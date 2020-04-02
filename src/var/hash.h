
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

var* _hash_clone_resize(size_t new_size, var* hash, bool clone);

inline var* hash_clone_resize(size_t new_size, var* hash) {
    return _hash_clone_resize(new_size, hash, true);
}

void _hash_insert(var* key, var* value, var** hash, bool clone);

inline void hash_insert(var* key, var* value, var** hash) {
    _hash_insert(key, value, hash, false);
}

var* hash_get(var* key, var* hash);
