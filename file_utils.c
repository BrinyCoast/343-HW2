#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>
#include <string.h>
int read_file(char* filename, char **buffer){
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;
    *buffer = malloc(size);
    if(buffer == NULL) {
        fprintf(stderr,"ERROR ALLOCATING MEMORY");
        return -1;
    }
        FILE *in;
        in = fopen(filename, "r");
    if(in == NULL){
        fprintf(stderr, "FILE NOT FOUND");
    }
        fread(*buffer, size, 1, in);
        return size;
}

int write_file(char* filename, char *buffer, int size){
    FILE *out;
    out = fopen(filename, "w");
    fwrite(buffer, size, 1, out);
    return size;
}

int reverse(char *buffer, int size){
    int start = 0;
    int end = size - 1;

    while(end > start){
        char temp = buffer[end];
        buffer[end] = buffer[start];
        buffer[start] = temp;
        end--;
        start++;
    }
    buffer[size] = '\0';
    return 1;
}
