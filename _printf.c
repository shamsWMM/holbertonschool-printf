#include "main.h"

/**
 * _printf - write input to stdout
 * @format: string containing specifiers and chars to write
 *
 * Return: number of characters printed if successful, -1 if unsuccessful
 */
int _printf(char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format && format[i])
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
