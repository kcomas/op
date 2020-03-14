
#pragma once

#include "var.h"

var string_new(size_t size);

bool string_free(var string);

var string_from_c(const char* c_string);
