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
			count += handle_format(format + i, &args);
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	return count;
}
int handle_format(char *format, va_list *args)
{
	return (0);
}
