#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

/**
 * handle_format - handles format string for _printf
 * @format: the format string including specifiers
 * @va_list: list of arguments corresponding to the specifiers in format
 *
 * Return: number of characters written
 */
int handle_format(char *format, va_list *args)
{
	int index = 0, count = 0;
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
