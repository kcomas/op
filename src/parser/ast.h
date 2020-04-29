
#pragma once

#include "../var/var.h"

#define AST_PFX(NAME) AST_##NAME

typedef enum {
    AST_PFX(ARG),
    AST_PFX(LOCAL),
    AST_PFX(VAR),
    AST_PFX(FUNCTION),
    AST_PFX(IF),
    AST_PFX(CALL)
} ast_type;

#define AST_BOP_PFX(NAME) AST_BOP_##NAME

typedef enum {
    AST_BOP_PFX(INTADD),
    AST_BOP_PFX(INTSUB),
    AST_BOP_PFX(FILEWRITE)
} ast_bop_type;

#define AST_UOP_PFX(NAME) AST_UOP_##NAME

typedef enum {
    AST_UOP_PFX(PUSH)
} ast_uop_type;

typedef struct _ast_stmt ast_stmt;

typedef struct {
    ast_uop_type type;
    ast_stmt *right;
} ast_uop;

typedef struct {
    ast_var **target;
} ast_call;

typedef struct {
    ast_bop_type type;
    ast_stmt *left, *right;
} ast_bop;

typedef struct {
    ast_stmt *else_stmt;
    struct {
        ast_stmt *cond, *body, *next;
    } cond_stmt;
} ast_if;

typedef struct _ast_fuction ast_function;

typedef struct _ast_stmt {
    ast_type type;
    union {
        ast_var **value;
        ast_function *fn_stmt;
        ast_if *if_stmt;
        ast_bop *bop_stmt;
        ast_uop *uop_stmt;
        ast_call *call;
    } stmt;
    struct _ast_stmt* next;
} ast_stmt;

typedef struct _ast_fuction {
    var_hash *arg_tbl, *local_tbl;
    ast_stmt *stmt;
} ast_function;
