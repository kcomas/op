
#pragma once

#define ERROR_PFX(NAME) ERROR_##NAME

typedef enum {
    ERROR_PFX(FILE_NOT_FOUND)
} var_error;
