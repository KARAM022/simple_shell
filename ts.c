
#include "shell.h"

void freearr(char **ar) {
    int k;
    for (k = 0; ar[k] != NULL; k++) {
        free(ar[k]);
        ar[k] = NULL;
    }
    free(ar);
}

void printerror(const char *name, const char *cmd, int idx) {
    const char *index;
    char idx_str[20];  

    _itoa(idx, idx_str, 10);
    index = idx_str;

    PRINT_ERROR(name, index, cmd);
}

char *_itoa(int num, char *str, int base) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int remainder = num % base;
        str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
        num = num / base;
    }

    if (isNegative && base == 10) {
        str[i++] = '-';
    }

    str[i] = '\0';
    reverse(str, i);

    return str;
}
    void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

