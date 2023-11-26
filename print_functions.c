#include "main.h"

int num_length(int num)
{
    int length = 0;

    if (num == 0)
    {
        return 1;
    }

    while (num != 0)
    {
        num /= 10;
        length++;
    }

    return length;
}

void int_to_str(int num, char *str)
{
    int length = num_length(num);
    int i = length - 1;

    while (i >= 0)
    {
        str[i] = '0' + (num % 10);
        num /= 10;
        i--;
    }
}
