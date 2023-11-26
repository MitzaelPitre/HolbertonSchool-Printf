#include "main.h"

#include "main.h"

int print_int(int num) {
    char num_str[20];
    int len = 0;

    for (int i = len - 1; i >= 0; i--) {
        write(1, &num_str[i], 1);
    }

    return len;
}
