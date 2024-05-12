#include "file_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int isNull(void* p) {
    return p == NULL;
}

int file_len(FILE* fd) {
    if(isNull(fd)) {
        // file isnt open
        fprintf(stderr, "file isnt open\n");
        return -1;
    }
    fseek(fd, 0, SEEK_END);
    int size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    return size;
}

char* file_to_string(FILE* fd)
{
    if(isNull(fd)) {
        fprintf(stderr, "file isnt open\n");
        return "";
    }
    int len = file_len(fd);
    char* str = (char*)malloc(sizeof(char)*len);
    if (isNull(str)) {
        fprintf(stderr, "cant allocate memory\n");
        return "";
    }
    fgets(str, len, fd);
    return str;
}

void create_absolute_path(const char *root, const char *file, char* dest)
{
    strcpy(dest, root);
    strcat(dest, file);
}
