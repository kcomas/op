
#pragma once

#include "var.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

var open_file(var filename);

bool close_file(var filename);

var file_to_string(var fd);
