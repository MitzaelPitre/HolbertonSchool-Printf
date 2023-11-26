#include "main.h"

int print_int(int num)
{
    char num_str[20];
    int num_len = 0;

    while (num != 0)
    {
        num_str[num_len++] = '0' + (num % 10);
        num /= 10;
    }

    for (int i = num_len - 1; i >= 0; i--)
    {
        write(1, &num_str[i], 1);
    }

    return num_len;
}
