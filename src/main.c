
#include "var/var.h"
#include "var/file.h"
#include "var/string.h"
#include "var/error.h"
#include "parser/token.h"

void check_error(var* error) {
    if (error->type == VAR_PFX(ERROR) && error->data.error != ERROR_PFX(OK)) {
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    var* error = VAR_ERROR(OK);
    var* file = file_open(argv[1]);
    check_error(file);
    printf("Using: %s\n", file->data.file->name);
    var* string = file_read_to_string(file);
    check_error(string);
    var_free(file);
    printf("%s", string->data.string->data);
    putchar('\n');
    token* t = token_new(MAX_TOKEN_SIZE);
    while (tokenize_string_next(*string, t, error)) print_token(t);
    check_error(error);
    var_free(error);
    token_free(t);
    var_free(string);
    return 0;
}
