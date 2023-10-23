/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 0;
    int i;
    for (i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
            carry = 1;
        } else {
            digits[i]++;
            carry = 0;
            break;
        }
    }

    if (carry == 1 && i == -1) {
        *returnSize = digitsSize + 1;
        int *ret = (int *)malloc(sizeof(int) * (*returnSize));
        ret[0] = 1;
        memcpy(ret + 1, digits, sizeof(int) * digitsSize);
        return ret;
    }

    *returnSize = digitsSize;
    return digits;
}
// @lc code=end

