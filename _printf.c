#include "main.h"

int print_char(char c);
int print_str(char *str);
int print_int(int num);

int _printf(const char *format, ...)
{
	va_list Mylist;
	int p_char = 0;

	va_start(Mylist, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				p_char += print_char(va_arg(Mylist, int));
			}
			else if (*format == 's')
			{
				p_char += print_str(va_arg(Mylist, char*));
			}
			else if (*format == 'd' || *format == 'i')
			{
				p_char += print_int(va_arg(Mylist, int));
			}
			else
			{
				write(1, format, 1);
				p_char++;
			}
		}
		else
		{
			write(1, format, 1);
			p_char++;
		}

		format++;
	}

	va_end(Mylist);
	return (p_char);
}
