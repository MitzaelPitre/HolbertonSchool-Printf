#include "main.h"

/**
 * _putchar - Write Characters
 * @c: variable va_list
 * Return: Writed character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printc - Print character
 * @arg_list: variable va_list
 * Return: 1 (number of bytes)
 */

int printc(va_list arg_list)
{
	_putchar(va_arg(arg_list, int));
	return (1);
}

/**
 * print_string - Print string
 * @s: variable va_list
 * Return: nB (number of bytes) 7 (NULL)
 */

int print_string(va_list s)
{
	char *str = va_arg(s, char *);
	int nB;

	if (str == NULL)
	{
		write(1, "(null)", 7);
		return (7);
	}
	else
	{
		for (nB = 0; str[nB] != '\0'; nB++)
		{
			_putchar(str[nB]);
		}
	}
	return (nB);
}

/**
 * print_n - Print number
 * @n: variable va_list
 * Return: count (nB)
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
 * cmp_func - Main point
 * @a: character
 * Return: 0
 */

int (*cmp_func(const char a))(va_list)
{
	print_f printfArr[] = {
		{'c', printc},
		{'s', print_string},
		{'d', print_n},
		{'i', print_n},
		{'\0', NULL}};

	int k;

	for (k = 0; printfArr[k].p != '\0'; k++)
	{
		if (printfArr[k].p == a)
		{
			return (printfArr[k].func);
		}
	}

	return (NULL);
}
