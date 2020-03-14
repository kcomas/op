
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define VAR_PFX(NAME) VAR_##NAME

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
    var_type type;
    union {
        int64_t int;
        double float;
        uint8_t string[];
        int file;
    } data;
} var;
