#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int climbStairs(int n){
    int testbuf[100] = {0};
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    testbuf[1] = 1;
    testbuf[2] = 2;

    int ret = 0;
    for (int i = 3; i <= n; i++) {
        ret = testbuf[i-1] + testbuf[i-2];
        testbuf[i] = ret;
    }


    return ret;
}

int main(void)
{
    printf("%d\r\n", climbStairs(45));

    return 0;
}
