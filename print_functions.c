#include "main.h"

int num_length(int num) {
    int length = 0;
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

void int_to_str(int num, char *str) {
    int length = num_length(num);

    if (num < 0) {
        str[0] = '-';
        num = -num;
        length++;
    }

    for (int i = length - 1; i >= 0; i--) {
        str[i] = '0' + num % 10;
        num /= 10;
    }

    str[length] = '\0';
}

int print_char(char c) {
    write(1, &c, 1);
    return 1;
}

int print_str(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        write(1, &str[len], 1);
        len++;
    }
    return len;
}

int print_int(int num)
{
    char num_str[20];
    int_to_str(num, num_str);

    int len = 0;
    while (num_str[len] != '\0') {
        write(1, &num_str[len], 1);
        len++;
    }

    return len;
}
