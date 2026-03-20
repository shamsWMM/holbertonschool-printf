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
 **
 * Return: On success number of digits printed
 * On error, -1 is returned, and errno is set appropriately
 */
int print_int(long d)
{
	int count = 0;
	char *digits = "0123456789";

	if (d < 0)
	{
		_putchar('-');
		return (print_int(-d) + 1);
	}
	else if (d < 10)
	{
		return (_putchar(digits[d]));
	}
	else
	{
		count = print_int(d / 10);
		return (count + print_int(d % 10));
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

int print_hex(uintptr_t n)
{
	char *hex = "0123456789abcdef";
	int count = 0;
	
	count++;
	if (n >= 16)
		print_hex(n / 16);
	_putchar(hex[n % 16]);
	return (count);
}

int print_ptr(void* address)
{
	int count = 0;
	uintptr_t n = (uintptr_t)address;

	_putchar('0');
	_putchar('x');
	count += 2;
	count += print_hex(n);
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
			count += print_int(va_arg(*args, int));
			break;
		case 's':
			count += print_str(va_arg(*args, char *));
			break;
		case 'p':
			count += print_ptr(va_arg(*args, void *));
			break;
		case 'c':
			count += _putchar(va_arg(*args, int));
			break;
	}
	return (count);
}
