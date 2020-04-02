
#pragma once

#include "var.h"

#define ERROR_UPDATE(ERROR, TYPE) (ERROR->data.error = ERROR_PFX(TYPE))
