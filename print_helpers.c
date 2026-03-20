#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to be printed
 *
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_int - writes the int digits to stdout
 * @d: decimal integer to be printed
 * @type: either d for decimal or upper or lower case x for hex
 *
 * Return: On success number of digits printed
 * On error, -1 is returned, and errno is set appropriately
 */
int print_int(long d, char type)
{
	int count = 0, base;
	char *digits;

	digits = type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	base = type == 'x' || type == 'X' ? 16 : type == 'o' ? 8 : 10;

	if (d < 0 && (type == 'u' || type == 'o' || base == 16))
		return (print_int(-d, type) + 1);
	else if (d < 0)
	{
		_putchar('-');
		return (print_int(-d, type) + 1);
	}
	else if (d < base)
	{
		return (_putchar(digits[d]));
	}
	else
	{
		count = print_int(d / base, type);
		return (count + print_int(d % base, type));
	}
}

/**
 * print_str - writes the chars of s to stdout
 * @s: string to be printed
 *
 * Return: On success number of digits printed
 * On error, -1 is returned, and errno is set appropriately
 */
int print_str(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (*s)
		count += _putchar(*s++);
	return (count);
}

/**
 * print_ptr - writes out pointer address
 * @address: address to be written
 *
 * Return: length of address
 */
int print_ptr(void *address)
{
	int count = 0;
	uintptr_t n = (uintptr_t)address;

	_putchar('0');
	_putchar('x');
	count += 2;
	count += print_int(n, 'x');
	return (count);
}

/**
 * handle_format - handles format string for _printf
 * @format: the format string including specifiers
 * @args: list of arguments corresponding to the specifiers in format
 *
 * Return: number of characters written
 */
int handle_format(char *format, va_list *args)
{
	int count = 0;

	switch (*format)
	{
		case 'd':
		case 'i':
			count += print_int(va_arg(*args, int), *format);
			break;
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			count += print_int(va_arg(*args, unsigned int), *format);
			break;
		case 'p':
			count += print_ptr(va_arg(*args, void *));
			break;
		case 's':
			count += print_str(va_arg(*args, char *));
			break;
		case 'c':
			count += _putchar(va_arg(*args, int));
			break;
		case '%':
			count += _putchar(*format);
			break;
		default:
			count += _putchar('%');
			count += _putchar(*format);
			break;
	}
	return (count);
}
