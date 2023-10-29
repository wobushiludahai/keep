/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start


int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
            max = count > max ? count : max;
        }
        else {
            count = 0;
        }
    }
    return max;
}
// @lc code=end

