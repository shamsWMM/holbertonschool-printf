#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
int print_int(long d);
int print_str(char *s);
int handle_format(char *format, va_list *args);
int _printf(char *format, ...);


#endif
