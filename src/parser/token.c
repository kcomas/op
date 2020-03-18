
#include "token.h"

extern inline token* token_new(size_t len);

extern inline void token_free(token* t);

static void finc(token* t) {
    t->fchar_idx++;
    t->fpos++;
}

static void fline(token* t) {
    t->fchar_idx = 1;
    t->fpos++;
    t->fline_idx++;
}

static void token_set_char(char c, token* t) {
    t->data[t->len++] = c;
}

static bool token_check_len(token* t, var* error) {
    if (t->len >= t->size) {
        *error = VAR_ERROR(MAX_TOKEN_LEN_EXCEEDED);
        return false;
    }
    return true;
}

static bool parse_var(var string, token* t, var* error) {
    char c = string.data.string->data[t->fpos];
    while (isalpha(c) || isdigit(c)) {
        token_set_char(c, t);
        finc(t);
        if (!token_check_len(t, error)) return false;
        c = string.data.string->data[t->fpos];
    }
    t->type = TOKEN_PFX(VAR);
    return true;
}

static bool parse_int(var string, token* t, var* error) {
    char c = string.data.string->data[t->fpos];
    while (isdigit(c)) {
        token_set_char(c, t);
        finc(t);
        if (!token_check_len(t, error)) return false;
        c = string.data.string->data[t->fpos];
        if (isalpha(c)) return parse_var(string, t, error);
    }
    t->type = TOKEN_PFX(INT);
    return true;
}

static bool next_until(var string, char stop, token *t, var* error) {
    char c = string.data.string->data[t->fpos];
    while (c != stop) {
        token_set_char(c, t);
        finc(t);
        if (!token_check_len(t, error)) return false;
        c = string.data.string->data[t->fpos];
    }
    return true;
}

static bool single_char(char c, token_type type, token* t) {
    token_set_char(c, t);
    finc(t);
    t->type = type;
    return true;
}

bool tokenize_string_next(var string, token* t, var* error) {
    t->char_idx = t->fchar_idx;
    t->line_idx = t->fline_idx;
    t->pos = t->fpos;
    t->len = 0;
    if (t->fpos >= string.data.string->len) return false;
    char c = string.data.string->data[t->fpos];
    while (c == ' ' || c == '\t') c = string.data.string->data[++t->fpos];
    if (isalpha(c)) return parse_var(string, t, error);
    if (isdigit(c)) return parse_int(string, t, error);
    switch (c) {
        case '\n':
            token_set_char(c, t);
            fline(t);
            t->type = TOKEN_PFX(END);
            return true;
        case ';': return single_char(c, TOKEN_PFX(END), t);
        case '"':
            finc(t);
            if (!next_until(string, '"', t, error)) return false;
            finc(t);
            t->type = TOKEN_PFX(STRING);
            return true;
        case '\'':
            finc(t);
            if (!next_until(string, '\'', t, error)) return false;
            finc(t);
            t->type = TOKEN_PFX(FILE);
            return true;
        case ':': return single_char(c, TOKEN_PFX(ASSIGN), t);
        case '$': return single_char(c, TOKEN_PFX(SELF), t);
        case '(': return single_char(c, TOKEN_PFX(LBRACE), t);
        case ')': return single_char(c, TOKEN_PFX(RBRACE), t);
        case '{': return single_char(c, TOKEN_PFX(RBRACKET), t);
        case '}': return single_char(c, TOKEN_PFX(LBRACKET), t);
        case '=': return single_char(c, TOKEN_PFX(INTEQ), t);
        case '+': return single_char(c, TOKEN_PFX(INTADD), t);
        case '-': return single_char(c, TOKEN_PFX(INTSUB), t);
        case '^':
            token_set_char(c, t);
            finc(t);
            c = string.data.string->data[t->fpos];
            switch (c) {
                case '>': return single_char(c, TOKEN_PFX(FILEWRITE), t);
                default:
                    *error = VAR_ERROR(INVALID_TOKEN_FOUND);
                    return false;
            }
        case '?': return single_char(c, TOKEN_PFX(INTSUB), t);
        default:
            *error = VAR_ERROR(INVALID_TOKEN_FOUND);
            return false;
    }
}

void print_token(token* t) {
    printf("char %lu, line %lu, ", t->char_idx, t->line_idx);
    for (size_t i = 0; i < t->len; i++) putchar(t->data[i]);
    putchar('\n');
}
