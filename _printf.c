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
int handle_format(char *format, va_list *args)
{
	int index = 0;
	char *str;

	switch(*format)
	{
		case 'd':
			_putchar( '0' + va_arg(*args, int));
			break;
		case 's':
			str = va_arg(*args, char *);
			while(str[index])
			{
				_putchar(str[index]);
				index++;
			}
			break;
		/**case 'p':
			str = va_arg(*args, void *);
			break;
		*/
		default:
			_putchar(*format);
			break;
	
	}
	return (0);
}
