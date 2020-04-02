
#include "var.h"

extern inline var* var_new(var_type type, var_data data);

extern void hash_free(var* hash);

void var_free(var* v) {
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
