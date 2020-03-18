
#include "var/var.h"
#include "var/file.h"
#include "var/string.h"
#include "parser/token.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    var error = VAR_ERROR(OK);
    var file = file_open(argv[1]);
    printf("Using: ");
    printf("%s\n", file.data.file->name);
    var string = file_read(file);
    file_free(file);
    string_print(string);
    putchar('\n');
    token* t = token_new(MAX_TOKEN_SIZE);
    while (tokenize_string_next(string, t, &error)) print_token(t);
    token_free(t);
    string_free(string);
    return 0;
}
