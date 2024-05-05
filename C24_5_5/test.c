#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void move(char* str) {
    while (*str) {
        *str = *(str + 1);
        str++;
    }
}
#include <stdlib.h>
char* compressString(char* param) {
    // write code here
    char* zip;
    zip = (char*)calloc(50000, sizeof(char));
    int cnt = 0;
    int i = 0;
    zip[i] = *param;
    while (*param) {
        if (zip[i] != *param) {
            i++;
            if (cnt != 1) {
                zip[i] = cnt + 48;
                i++;
            }
            zip[i] = *param;
            cnt = 0;
        }
        if (zip[i] == *param) {
            cnt++;
            param++;
        }
    }
    if (cnt != 1) {
        i++;
        zip[i] = cnt + 48;
    }
    return zip;
}
char* formatString(char* str, char* arg, int argLen) {
    // write code here
    char* cp = str;
    int cnt = 0;
    while (*cp) {
        if (*cp == '%' && *(cp + 1) == 's') {
            cnt++;
        }
        cp++;
    }
    cp = str;
    while (*cp) {
        if (*cp == '%' && *(cp + 1) == 's') {
            *cp = *arg;
            move(cp + 1);
            arg++;
        }
        cp++;
    }
    return strcat(str, arg);
}

int main() {
    char str[20] = "A%sC%sE";
    char arg[20] = { 'B','D','F',0 };
    formatString(str, arg, strlen(arg));
    return 0;
}