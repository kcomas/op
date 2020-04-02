
#include "hash.h"

extern inline var* hash_new(size_t size);

extern inline void hash_free(var* hash);

static inline bucket* bucket_new(var* key, var* value, bool clone) {
#if TYPECHECK
    assert(key->type == VAR_PFX(STRING));
#endif
    bucket* b = calloc(1, sizeof(bucket));
    b->key = string_clone_resize(key->data.string->len, key);
    if (clone) b->value = var_clone(value);
    else b->value = var_copy(value);
    return b;
}

static inline size_t hash_string(var* key) {
#if TYPECHECK
    assert(key->type == VAR_PFX(STRING));
#endif
    size_t hash = 0;
    for (size_t i = 0; i < key->data.string->len; i++)
        hash = key->data.string->data[i] + (hash << 6) + (hash << 16) - hash;
    return hash;
}

void hash_free(var* hash) {
#if TYPECHECK
    assert(hash->type == VAR_PFX(HASH));
#endif
    for (size_t i = 0; i < hash->data.hash->size; i++) {
        if (hash->data.hash->data[i] == NULL) continue;
        bucket* b = hash->data.hash->data[i];
        while (b != NULL) {
            bucket* tmp = NULL;
            b = b->next;
            var_free(tmp->key);
            var_free(tmp->value);
            free(tmp);
        }
    }
}

var* _hash_clone_resize(size_t new_size, var* hash, bool clone) {
#if TYPECHECK
    assert(hash->data.hash->size < new_size);
#endif
    var* new_hash = hash_new(new_size);
    for (size_t i = 0; i < hash->data.hash->size; i++) {
        if (hash->data.hash->data[i] == NULL) continue;
        bucket* b = hash->data.hash->data[i];
        while (b != NULL) {
            _hash_insert(b->key, b->value, &new_hash, clone);
            b = b->next;
        }
    }
    return new_hash;
}

extern inline var* hash_clone_resize(size_t new_size, var* hash);

void _hash_insert(var* key, var* value, var** hash, bool clone) {
#if TYPECHECK
        assert(key->type == VAR_PFX(STRING));
        assert((*hash)->type == VAR_PFX(HASH));
#endif
        bucket* b = bucket_new(key, value, clone);
        size_t pos = hash_string(key) % (*hash)->data.hash->size;
        if ((*hash)->data.hash->data[pos] == NULL) {
            (*hash)->data.hash->data[pos] = b;
        } else {
            bucket* current_bucket = (*hash)->data.hash->data[pos];
            while (current_bucket->next != NULL) current_bucket = current_bucket->next;
            current_bucket->next = b;
        }
        (*hash)->data.hash->len++;
        if ((*hash)->data.hash->len == (*hash)->data.hash->size) {
            var* tmp = *hash;
            *hash = _hash_clone_resize(tmp->data.hash->size * HASH_GROWTH, tmp, clone);
            var_free(tmp);
        }
}

extern inline void hash_insert(var* key, var* value, var** hash);

var* hash_get(var* key, var* hash) {
#if TYPECHECK
    assert(key->type == VAR_PFX(STRING));
#endif
    size_t pos = hash_string(key) % hash->data.hash->size;
    if (hash->data.hash->data[pos] == NULL) {
        return VAR_ERROR(INVALID_HASH_KEY);
    }
    bucket* b = hash->data.hash->data[pos];
    while (b != NULL) {
        if (string_cmp(key, b->key) == 0) {
            b->value->rc++;
            return b->value;
        }
        b = b->next;
    }
    return VAR_ERROR(INVALID_HASH_KEY);
}
