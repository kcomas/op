
#pragma once

#define ERROR_PFX(NAME) ERROR_##NAME

typedef enum {
    ERROR_PFX(FILE_NOT_FOUND),
    ERROR_PFX(CANNOT_READ_FILE)
} var_error;
