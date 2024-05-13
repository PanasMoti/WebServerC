#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/// @brief checks if the pointer points to null
/// @param p a generic pointer
/// @return 1 if p does points to null and 0 otherwise
int isNull(void* p);

/// @brief get the length of an open file
/// @param fd the file pointer
/// @return the length of the file
int file_len(FILE* fd);

/// @brief convert a file to a heap allocated string
/// @param fd the file pointer
/// @return a heap allocated string
/// @note dont forget to free it later
char* file_to_string(FILE* fd);

/// @brief combine a root path and the file path to make an absolute path of the file
/// @param root the absloute root directory  
/// @param file the relative file path
/// @param dest the destination that the new path will be stored at 
void create_absolute_path(const char* root, const char* file, char* dest);


/// @brief open a file and read all of into a string  
/// @param file the path to the file
/// @return pointer to a string or NULL on failure
/// @note remember to free it later
char* read_file(const char* file);


#endif // FILE_UTILS_H_