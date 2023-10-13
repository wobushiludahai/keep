/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start


int climbStairs(int n){
    int testbuf[100] = {0};
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    testbuf[1] = 1;
    testbuf[2] = 2;

    int ret = 0;
    for (int i = 3; i <= n; i++) {
        ret = testbuf[i-1] + testbuf[i-2];
        testbuf[i] = ret;
    }


    return ret;
}
// @lc code=end

