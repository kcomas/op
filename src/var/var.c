
#include "var.h"

extern inline var* var_new(var_type type, var_data data);

extern void hash_free(var* hash);

extern var* hash_clone_resize(size_t new_size, var* hash);

var* var_clone(var* v) {
    switch (v->type) {
        case VAR_PFX(HASH):
            return hash_clone_resize(v->data.hash->size, v);
        default:
            return var_new(v->type, v->data);
    }
}

var* var_copy(var* v) {
    switch (v->type) {
        case VAR_PFX(INT):
        case VAR_PFX(FLOAT):
        case VAR_PFX(CHAR):
            return var_new(v->type, v->data);
        default:
            return v;
    }
}

void var_free(var* v) {
    switch (v->type) {
        case VAR_PFX(INT):
        case VAR_PFX(FLOAT):
        case VAR_PFX(CHAR):
            free(v);
            return;
        default:
            break;
    }
    if (--v->rc > 0) return;
    switch (v->type) {
        case VAR_PFX(STRING):
            free(v->data.string);
            break;
        case VAR_PFX(HASH):
            hash_free(v);
            break;
        case VAR_PFX(FILE):
            close(v->data.file->fd);
            free(v->data.file);
            break;
            default:
                break;
    }
    free(v);
}
