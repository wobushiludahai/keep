#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    char test_buf[10] = {0};

    for (int i = 0; i < numsSize; i++) {
        test_buf[nums[i]] = 1;
    }

    for (int i = 1; i <= numsSize; i++) {
        if (test_buf[i] == 0) {
            nums[*returnSize] = i;
            *returnSize = *returnSize + 1;
        }
    }

    if (*returnSize != 0) {
        return nums;
    }

    return NULL;
}

int main(void)
{
    int nums[] = {4,3,2,7,8,2,3,1};
    int returnSize = 0;

    findDisappearedNumbers(nums, 8, &returnSize);

    printf("%d\r\n", returnSize);

    return 0;
}
