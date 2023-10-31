/*
 * @lc app=leetcode.cn id=448 lang=c
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    char test_buf[100001] = {0};

    for (int i = 0; i < numsSize; i++) {
        test_buf[nums[i]] = 1;
    }

    *returnSize = 0;

    for (int i = 1; i <= numsSize; i++) {
        if (test_buf[i] == 0) {
            nums[*returnSize] = i;
            *returnSize = *returnSize + 1;
        }
    }

    return nums;
}
// @lc code=end

