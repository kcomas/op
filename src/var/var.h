
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#ifndef TYPECHECK
    #define TYPECHECK true
#endif

#define VAR_PFX(NAME) VAR_##NAME

#define ERROR_PFX(NAME) ERROR_##NAME

typedef union _var_data var_data;

#define VAR_NEW(TYPE, DATA) var_new(VAR_PFX(TYPE), (var_data) DATA)

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

typedef enum _var_error {
    ERROR_PFX(OK),
    ERROR_PFX(FILE_NOT_FOUND),
    ERROR_PFX(CANNOT_READ_FILE),
    ERROR_PFX(INVALID_TOKEN_FOUND),
    ERROR_PFX(MAX_TOKEN_LEN_EXCEEDED),
    ERROR_PFX(INVALID_BYTES_FOR_CHAR),
    ERROR_PFX(INVALID_HASH_KEY)
} var_error;

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

typedef union _var_data {
    var_error error;
    int64_t i;
    double f;
    var_char c;
    var_string* string;
    var_file* file;
    var_hash* hash;
} var_data;

typedef struct _var {
    var_type type;
    uint32_t rc;
    var_data data;
} var;

inline var* var_new(var_type type, var_data data) {
    var* v = calloc(1, sizeof(var));
    v->type = type;
    v->rc = 1;
    v->data = data;
    return v;
}

var* var_clone(var* v);

var* var_copy(var* v);

void var_free(var* v);

typedef struct _bucket {
    var* key;
    var* value;
    struct _bucket* next;
} bucket;

typedef struct _var_hash {
    size_t size, len;
    bucket* data[];
} var_hash;

