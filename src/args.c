#include "args.h"
#include <stdio.h>
#include <string.h>

void log_args(int argc, char** argv) {
    for(int i = 0; i < argc; i++) {
        printf("ARG[%d]:\t\"%s\"\n",i,argv[i]);
    }
}

int find_last(const char* str, char ch) {
    int len = strlen(str);
    while (str[--len] != ch);
    return len;
}


void get_parent_directory(const char* path, char* dest) {
    int pos = find_last(path, '/');
    if(pos <= 0) {
        dest = "";
    } else {
        strncpy(dest,path,pos);
        dest[pos] = '\0';
    }
}


void get_root_directory(const char* path, char* dest) {
    get_parent_directory(path, dest);
    get_parent_directory(dest, dest);
}