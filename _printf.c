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
        return (-1);

    while (*format) {
        if (*format == '%') {
            format++;

            if (*format == 'c') {
                char c = va_arg(Mylist, int);
                p_char += print_char(c);
            } else if (*format == 's') {
                char *str = va_arg(Mylist, char*);
                p_char += print_str(str);
            } else if (*format == 'd' || *format == 'i') {
                int num = va_arg(Mylist, int);
                p_char += print_int(num);
            } else {
                write(1, format, 1);
                p_char++;
            }
        } else {
            write(1, format, 1);
            p_char++;
        }

        format++;
    }

    va_end(Mylist);
    return p_char;
}
