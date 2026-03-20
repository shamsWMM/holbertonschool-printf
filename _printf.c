#include "main.h"

int _printf(char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	
	va_start(args, format);
	while(format && format[i])
	{
		if (format[i] == '%')
		{
			count += handle_format(format + i + 1, &args);
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * print_all - print all
 * @format: pattern of arguments
void print_all(const char * const format, ...)
{
va_list args;
char *separator = "";
unsigned int count, index = 0;
type_print tp[] = {
	{'c', print_char},
	{'s', print_string},
	{'i', print_int},
	{'f', print_float},
	{0, NULL}
};

va_start(args, format);
while (format && format[index])
{
	count = 0;
	while (tp[count].type)
	{
		if (format[index] == tp[count].type)
		{
			printf("%s", separator);
			tp[count].print_type(args);
			separator = ", ";
		}
		count++;
	}
	index++;
}
printf("\n");
va_end(args);
}
*/
