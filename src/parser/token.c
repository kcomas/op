
#include "token.h"

extern inline token* token_new(size_t len);

extern inline void token_free(token* t);

bool tokenize_string_next(var string, token* t);
