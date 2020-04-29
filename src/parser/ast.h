
#pragma once

#include "../var/var.h"

#define AST_PFX(NAME) AST_##NAME

typedef enum {
    AST_PFX(VAR),
    AST_PFX(LOAD),
    AST_PFX(UOP),
    AST_PFX(BOP),
    AST_PFX(FUNCTION),
    AST_PFX(CALL)
    AST_PFX(IF),
} ast_type;

typedef struct _ast_stmt ast_stmt;

#define AST_LOAD_PFX(NAME) AST_LOAD_##NAME

typedef enum {
    AST_LOAD_PFX(ARG),
    AST_LOAD_PFX(LOCAL)
} ast_load_type;

typedef struct {
    ast_load_type type;
    int8_t idx;
    var *name;
} ast_load;

#define AST_UOP_PFX(NAME) AST_UOP_##NAME

typedef enum {
    AST_UOP_PFX(PUSH),
} ast_uop_type;

typedef struct {
    ast_uop_type type;
    ast_stmt *right;
} ast_uop;

#define AST_BOP_PFX(NAME) AST_BOP_##NAME

typedef enum {
    AST_BOP_PFX(INTADD),
    AST_BOP_PFX(INTSUB),
    AST_BOP_PFX(FILEWRITE)
} ast_bop_type;

typedef struct {
    ast_bop_type type;
    ast_stmt *left, *right;
} ast_bop;

typedef struct _ast_var_list {
    ast_var *value;
    struct _ast_var_list *next;
} ast_var_list;

typedef struct {
    size_t num_args;
    ast_var *target;
    ast_var_list *args;
} ast_call;

typedef struct _ast_if {
    ast_stmt *cond, *body;
    struct _ast_if *next;
} ast_if;

typedef struct _ast_fuction ast_function;

typedef struct _ast_stmt {
    ast_type type;
    union {
        ast_var *value;
        ast_load *load;
        ast_bop *bop;
        ast_uop *uop;
        ast_function *fn;
        ast_call *call;
        ast_if *if_stmt;
    } stmt;
    struct _ast_stmt *next;
} ast_stmt;

typedef struct _ast_fuction {
    size_t num_args, num_locals;
    var_hash *sym_table;
    ast_stmt *stmt;
} ast_function;
