#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int printc(va_list list)
{
    _putchar(va_arg(list, int));
    return 1;
}

int print_string(va_list s)
{
    char *str = va_arg(s, char *);
    int k;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return 6;
    }
    else
    {
        for (k = 0; str[k] != '\0'; k++)
        {
            _putchar(str[k]);
        }
    }
    return k;
}

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
    return counter;
}

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
            return printfArr[k].func;
        }
    }

    return NULL;
}
