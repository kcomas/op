
#pragma once

#include "var.h"

#define ERROR_UPDATE(ERROR, TYPE) (ERROR->data.error = ERROR_PFX(TYPE))

inline void error_free(var* error) {
#if TYPECHECK
    assert(error->type == VAR_PFX(ERROR));
#endif
    var_free(error);
}
