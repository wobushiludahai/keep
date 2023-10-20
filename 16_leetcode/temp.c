#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0


bool isValid(char * s){
    int len = strlen(s);
    char stack[len];
    if (len % 2 == 1) {
        return false;
    }

    if (len == 0) {
        return true;
    }

    int top = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
            continue;
        }

        if (s[i] == ')' && stack[top - 1] == '(') {
            top--;
            continue;
        }

        if (s[i] == '}' && stack[top - 1] == '{') {
            top--;
            continue;
        }

        if (s[i] == ']' && stack[top - 1] == '[') {
            top--;
            continue;
        }

        return false;
    }

    if (top != 0) {
        return false;
    }

    return true;
}

int main(void)
{
    printf("%d\r\n", isValid("){"));

    return 0;
}
