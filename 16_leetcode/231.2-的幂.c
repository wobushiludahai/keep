/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2 的幂
 */

// @lc code=start
bool isPowerOfTwo(int n){
    return n > 0 && !(n & (n - 1));
}
// @lc code=end

