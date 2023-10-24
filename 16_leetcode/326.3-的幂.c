/*
 * @lc app=leetcode.cn id=326 lang=c
 *
 * [326] 3 的幂
 */

// @lc code=start


bool isPowerOfThree(int n){
    if (n == 1) {
        return true;
    }

    if (n <= 2) {
        return false;
    }

    while (n)
    {
        int i = n % 3;
        if (i != 0) {
            return false;
        }
        n = n / 3;
        if (n == 1) {
            return true;
        }
    }

    return true;
}
// @lc code=end

