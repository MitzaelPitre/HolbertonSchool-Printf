#include "main.h"

int num_length(int num) 
{
    int length = 0;
    if (num == 0) {
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

    if (num < 0) {
        str[0] = '-';
        num = -num;
        length++;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        str[i] = '0' + num % 10;
        num /= 10;
    }

    str[length] = '\0';
}
