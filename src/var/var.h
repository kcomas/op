
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "error.h"

#define VAR_PFX(NAME) VAR_##NAME

#define VAR_NEW(TYPE, DATA) (var) { .type = VAR_PFX(TYPE), .data = DATA }

#define VAR_ERROR(DATA) VAR_NEW(ERROR, { .error = ERROR_PFX(DATA) })

#define VAR_CHAR(DATA) VAR_NEW(CHAR, { .c = DATA })

#define VAR_STRING(DATA) VAR_NEW(STRING, { .string = DATA })

#define VAR_FILE(DATA) VAR_NEW(FILE, { .file = DATA })

#define VAR_HASH(DATA) VAR_NEW(HASH, { .hash = DATA })

typedef enum {
    VAR_PFX(NULL),
    VAR_PFX(UNKNOWN),
    VAR_PFX(ERROR),
    VAR_PFX(INT),
    VAR_PFX(FLOAT),
    VAR_PFX(CHAR),
    VAR_PFX(STRING),
    VAR_PFX(ARRAY),
    VAR_PFX(HASH),
    VAR_PFX(FILE),
    VAR_PFX(THREAD),
    VAR_PFX(FUNCTION),
    VAR_PFX(MODULE)
} var_type;

typedef struct {
    uint8_t data[4];
} var_char;

typedef struct {
    size_t size, len;
    uint8_t data[];
} var_string;

typedef struct {
    int fd;
    char name[];
} var_file;

typedef struct _var_hash var_hash;

typedef struct _var {
    var_type type;
    union {
        var_error error;
        int64_t i;
        double f;
        var_char c;
        var_string* string;
        var_file* file;
        var_hash* hash;
    } data;
} var;

typedef struct _bucket {
    var_string* key;
    var value;
    struct _bucket* next;
} bucket;

typedef struct _var_hash {
    size_t size, len;
    bucket* buckets[];
} var_hash;


