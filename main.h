#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
int handle_format(char *format, va_list *args);
int _printf(char *format, ...);


#endif
