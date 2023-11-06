#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

unsigned long long int get_sum(unsigned long long num)
{
    unsigned long long int sum = 0;
    while (num) {
        sum += (num % 10) * (num % 10);
        num /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    unsigned long long int num = n;

    while (1) {
        if (num == 1) {
            return true;
        }

        num = get_sum(num);
        if (num == 4) {
            return false;
        }

        printf("%d\n", num);

        if (num > 0xffffffff) {
            return false;
        }
    }
}

int main(void)
{
    isHappy(2);

    return 0;
}
