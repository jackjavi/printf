#include "main.h"
/**
* print_hex - prints an unsigned int character in hexa-decimal format
* @n: unsigned integer to be printed
* @c: flag to determine case i.e
*	1 => upper
*	0 => lower
* Return: count of digits printed
*/

int print_hex(unsigned int n, unsigned int c)
{
	char diff;
	unsigned int a[8];
	int count;
	unsigned int i, m, sum;

	m = 268435456;  /*i.e 16 ^ 7*/
	if (c)
	{
		diff = 'A' - ':';
	}
	else
	{
		diff = 'a' - ':';
	}
	a[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0, count = 0; i < 8; i++)
	{
		sum += a[i];

		if (sum || i == 7)
		{
			if (a[i] < 10)
			{
				_putchar('0' + a[i]);
			}
			else
			{
				_putchar('0' + diff + a[i]);
			}
			count++;
		}
	}
	return (count);
}


/**
* print_x - prints a passed unsigned int in lowercase hex notation
* @x: the unsigned int to be printed
* Return: count of digits printed
*/

int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}


/**
* print_X - prints a passed unsigned int in UPPERCASE hex notation
* @X: unsigned int to be printed
* Return: count of digits printed
*/

int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}


/**
* _pow - calculates and returns exponent of number
* @base: exponent's base
* @exp: exponent of number
* Return: base to the power of exp (base ^ exp)
*/

static unsigned long _pow(unsigned int base, unsigned int exp)
{
	unsigned int x;
	unsigned long answer = base;

	for (x = 1; x < exp; x++)
	{
		answer *= base;
	}
	return (answer);
}


/**
* print_p - prints address
* @p: address to print
* Return: count of characters printed
*/

int print_p(va_list p)
{
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	int count = 0;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _pow(16, 15);
	a[0] = (n / m);
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
			{
				_putchar('0' + ('a' - ':') + a[i]);
				count++;
			}
		}
	}
	return (count);
}
