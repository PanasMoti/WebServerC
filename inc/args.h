#ifndef ARGS_H_
#define ARGS_H_

/*
    this file is for functions that deal mostly with the arguments given to the program
    aka argc and argv
*/


/// @brief printout the arguments giving to the program -- used for debugging
/// @param argc the amount of arguments
/// @param argv the arguments themselves
void log_args(int argc, char** argv);

/// @brief find last occurence of a char in a string
/// @return the position of the char
int find_last(const char* str, char ch);

/// @brief get the parent directory
/// @param path the path 
/// @param dest output
/// @snippet "/usr/bin/program" -> "/usr/bin" 
void get_parent_directory(const char* path, char* dest);


/// @brief get the root directory of from where the executable was called
/// @param path argv[0]
/// @param dest the output
void get_root_directory(const char* path, char* dest);

#endif // ARGS_H_