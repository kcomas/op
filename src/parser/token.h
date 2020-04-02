
#pragma once

#include <ctype.h>
#include "../var/var.h"
#include "../var/string.h"
#include "../var/error.h"

#define TOKEN_PFX(NAME) TOKEN_##NAME

typedef enum {
    TOKEN_PFX(NONE),
    TOKEN_PFX(VAR),
    TOKEN_PFX(INT),
    TOKEN_PFX(CHHAR),
    TOKEN_PFX(STRING),
    TOKEN_PFX(FILE),
    TOKEN_PFX(ASSIGN),
    TOKEN_PFX(CLONE),
    TOKEN_PFX(SELF),
    TOKEN_PFX(LBRACE),
    TOKEN_PFX(RBRACE),
    TOKEN_PFX(LBRACKET),
    TOKEN_PFX(RBRACKET),
    TOKEN_PFX(INTEQ),
    TOKEN_PFX(INTLESS),
    TOKEN_PFX(INTLESSEQ),
    TOKEN_PFX(INTADD),
    TOKEN_PFX(INTSUB),
    TOKEN_PFX(INTOR),
    TOKEN_PFX(FILEWRITE),
    TOKEN_PFX(IF),
    TOKEN_PFX(WHILE),
    TOKEN_PFX(END)
} token_type;

#define MAX_TOKEN_SIZE 200

typedef struct {
    token_type type;
    size_t char_idx, line_idx, pos, size, len;
    size_t fchar_idx, fline_idx, fpos;
    char data[];
} token;

inline token* token_new(size_t size) {
    token* t = calloc(1, sizeof(token) + size);
    t->size = size;
    t->fchar_idx = 1;
    t->fline_idx = 1;
    return t;
}

inline void token_free(token* t) {
    free(t);
}

bool tokenize_string_next(var string, token* t, var* error);

void print_token(token* t);
