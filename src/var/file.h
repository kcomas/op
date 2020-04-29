
#pragma once

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "var.h"
#include "string.h"

var *file_open(char filename[]);

var *file_read_to_string(var *file);
