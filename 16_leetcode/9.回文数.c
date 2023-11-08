/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start
bool isPalindrome(int x) {
    unsigned long long int tmp = 0;
    int bak = x;

    if (x < 0) {
        return false;
    }

    while (x != 0) {
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }

    if (bak == tmp) {
        return true;
    }

    return false;
}
// @lc code=end

