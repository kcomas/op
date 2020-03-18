
#pragma once

#include "../var/var.h"
#include "../var/string.h"

#define TOKEN_PFX(NAME) TOKEN_##NAME

typedef enum {
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
    TOKEN_PFX(IF)
} token_type;

#define MAX_TOKEN_LEN 40

typedef struct {
    token_type type;
    char data[MAX_TOKEN_LEN];
} token;

bool tokenize_string(var string, token* t);
