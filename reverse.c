#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

//Justin Dowty help me work through pointers.
int main(int argc, char *argv[]) {
    char **buffer = malloc(sizeof(char**));
    int size = read_file(argv[1], buffer);
    reverse(*buffer, size);
    write_file(argv[2], *buffer, size);

    return 0;
}