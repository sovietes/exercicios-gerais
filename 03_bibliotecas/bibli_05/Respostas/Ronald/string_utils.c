#include "./string_utils.h"

int string_length(char *str) {
    if(str[0] == '\0') {
        return 1;
    } else {
        return 1 + string_length(str+1);
    }
}

void string_copy(char *src, char *dest) {
    int i, sizeStr;
    sizeStr = string_length(src) - 1;
    for(i = 0; i <= sizeStr; i++) {
        dest[i] = src[i];
    }
}

void string_upper(char *str) {
    int i, sizeStr;
    sizeStr = string_length(str) - 2;
    for(i = 0; i < sizeStr; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] + ('Z' - 'z');
        }
    }
}

void string_lower(char *str) {
    int i, sizeStr;
    sizeStr = string_length(str) - 1;
    for(i = 0; i < sizeStr; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('z' - 'Z');
        }
    }
}

void string_reverse(char *str) {
    int i, j;

    char sizeStr = string_length(str) - 2;
    char strCopy[sizeStr];
    string_copy(str, strCopy);

    for(i = 0, j = sizeStr - 1; i < sizeStr; i++, j--) {
        str[i] = strCopy[j];
    }
}
