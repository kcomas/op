
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include "error.h"

#define VAR_PFX(NAME) VAR_##NAME

#define VAR_NEW(TYPE, DATA) (var) { .type = VAR_PFX(TYPE), .data = DATA }

#define VAR_ERROR(DATA) VAR_NEW(ERROR, { .error = ERROR_PFX(DATA) })

#define VAR_STRING(DATA) VAR_NEW(STRING, { .string = DATA })

#define VAR_FILE(DATA) VAR_NEW(FILE, { .file = DATA })

typedef enum {
    VAR_PFX(UNKNOWN),
    VAR_PFX(NULL),
    VAR_PFX(ERROR),
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
    struct stat buf;
    int fd;
    char name[];
} var_file;

typedef struct {
    var_type type;
    union {
        var_error error;
        int64_t i;
        double f;
        var_string* string;
        var_file* file;
    } data;
} var;
