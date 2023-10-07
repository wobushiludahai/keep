#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p = m + n - 1;
    int p1 = m - 1;
    int p2 = n - 1;

    while (p >= 0) {
        if (p2 < 0 || (p1 >= 0 && nums1[p1] > nums2[p2])) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }

        // if (p1 < 0 || (nums1[p1] <= nums2[p2])) {
        //     nums1[p] = nums2[p2];
        //     p2--;
        // }

        p--;
    }
}

int main(void)
{
    int testbuf[6] = {1, 2, 3, 0, 0, 0};
    int testbuf2[3] = {2, 5, 6};
    merge(testbuf, 3, 3, testbuf2, 3, 3);
    for (int i = 0; i < 6; i++) {
        printf("%d \r\n", testbuf[i]);
    }

    return 0;
}
