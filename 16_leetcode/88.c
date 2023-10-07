// URL https://leetcode.cn/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

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

        p--;
    }
}