/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] x 的平方根
 */

// @lc code=start


int mySqrt(int x){
    long long i=1;
    while(i*i<=x){
        i++;
    }
    return i-1;
}
// @lc code=end

