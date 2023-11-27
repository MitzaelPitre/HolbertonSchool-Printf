#include "main.h"

/**
 * _putchar - Entry function. Write Characters
 * @c: variable va_list
 *
 * Return: Writed character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printc - Entry function. Print characters
 * @list: variable va_list
 *
 * Return: 1 (number of bytes)
 */

int printc(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string - Entry point. Print string
 * @s: variable va_list
 *
 * Return: b (number of bytes) 6 (NULL)
 */

int print_string(va_list s)
{
	char *str;
	int b;

	str = va_arg(s, char*);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (b = 0; str[b] != '\0'; b++)
		{
			_putchar(str[b]);
		}
	}
	return (b);
}

/**
 * print_n - Entry point. Print number
 * @n: Variable va_list
 *
 * Return: count (nbytes)
 */

int print_n(va_list n)
{
	long int number;
	int counter, aux_variable, base;

	counter = 0;
	number = va_arg(n, int);

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		counter++;
	}
	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		counter++;
	}
	if (number > 9)
	{
		base = 10;

		while (number / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			aux_variable = number / base;
			number = number % base;
			_putchar(aux_variable + 48);
			base = base / 10;
			counter++;
		}
	}
	return (counter);
}

/**
 * print_b - Entry point. Print binary representation of an unsigned int
 * @n: Variable va_list
 *
 * Return: count (number of bytes printed)
 */

int print_b(va_list n)
{
	unsigned int number = va_arg(n, unsigned int);
	int count = 0;

	if (number == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count += print_binary(number);
	}

	return (count);
}

int print_binary(unsigned int n)
{
	int count = 0;

	if (n == 0)
		return (0);

	count += print_binary(n / 2);
	_putchar((n % 2) + '0');
	return (count + 1);
}

/**
 * cmp_func - Entry point
 * @a: character
 * Return: 0
 */

int (*cmp_func(const char a))(va_list)
{
	print_f printf[] = {
		{'c', printc},
		{'s', print_string},
		{'d', print_n},
		{'i', print_n},
		{'b', print_b},
		{'\0', NULL}
	};

	int k;

	for (k = 0; printf[k].p != '\0'; k++)
	{
		if (printf[k].p == a)
		{
			return (printf[k].func);
		}
	}

	return (0);
}
