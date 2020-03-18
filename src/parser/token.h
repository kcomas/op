
#pragma once

#include "../var/var.h"
#include "../var/string.h"

#define TOKEN_PFX(NAME) TOKEN_##NAME

typedef enum {
    TOKEN_PFX(NONE),
    TOKEN_PFX(VAR),
    TOKEN_PFX(INT),
    TOKEN_PFX(STRING),
    TOKEN_PFX(FILE),
    TOKEN_PFX(SELF),
    TOKEN_PFX(LBRACE),
    TOKEN_PFX(RBRACE),
    TOKEN_PFX(LBRACKET),
    TOKEN_PFX(RBRACKET),
    TOKEN_PFX(INTEQ),
    TOKEN_PFX(INTADD),
    TOKEN_PFX(INTSUB),
    TOKEN_PFX(FILEWRITE),
    TOKEN_PFX(IF),
    TOKEN_PFX(END)
} token_type;

#define MAX_TOKEN_LEN 40

typedef struct {
    token_type type;
    size_t char_idx, line_idx, start_pos, end_pos, max_len;
    char data[];
} token;

inline token* token_new(size_t len) {
    token* t = calloc(1, sizeof(token) + len);
    t->max_len = len;
    return t;
}

inline void token_free(token* t) {
    free(t);
}

bool tokenize_string_next(var string, token* t);
