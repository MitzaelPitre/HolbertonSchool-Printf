#include "main.h"

int print_str(char *str)
{
    int str_len = 0;

    while (str[str_len] != '\0')
        str_len++;

    write(1, str, str_len);
    return str_len;
}
