#include <unistd.h>

/**
 * _putchar - prints a character on the terminal
 * @c: character to be printed
 *
 * Return: on success 1.
 * On error, -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
