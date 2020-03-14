
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define VAR_PFX(NAME) VAR_##NAME

#define VAR_NEW(TYPE, DATA) (var) { .type = VAR_PFX(TYPE), .data = DATA }

#define VAR_STRING(DATA) VAR_NEW(STRING, { .string = DATA })

typedef enum {
    VAR_PFX(UNKNOWN),
    VAR_PFX(NULL),
    VAR_PFX(INT),
    VAR_PFX(FLOAT),
    VAR_PFX(STRING),
    VAR_PFX(ARRAY),
    VAR_PFX(HASH),
    VAR_PFX(FILE),
    VAR_PFX(THREAD),
    VAR_PFX(FUNCTION),
    VAR_PFX(MODULE)
} var_type;

typedef struct {
    size_t size, len;
    uint8_t data[];
} var_string;

typedef struct {
    var_type type;
    union {
        int64_t i;
        double f;
        var_string* string;
        int file;
    } data;
} var;
