#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_str(char *str);
int print_int(int num);
int num_length(int num);
void int_to_str(int num, char *str);

#endif 
