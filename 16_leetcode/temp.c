#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0


bool repeatedSubstringPattern(char * s){
    int len = strlen(s);

    for (int i = 1; i * 2 <= len; i++) {
        if (len % i != 0) {
            continue;
        }

        int num = len / i;
        int match = true;
        for (int j = 0; j < i; j++) {
            for (int k = 1; k < num; k++) {
                if (s[j + k * i] != s[j]) {
                    match = false;
                    break;
                }
            }

            if (match == false) {
                break;
            }
        }

        if (match == true) {
            return true;
        }
    }

    return false;
}

int main(void)
{
    char test_buf[] = "abac";
    printf("%d\r\n", repeatedSubstringPattern(test_buf));

    return 0;
}
