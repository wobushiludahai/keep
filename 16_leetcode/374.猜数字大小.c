/*
 * @lc app=leetcode.cn id=374 lang=c
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    unsigned long long int left = 1;
    unsigned long long int right = n;
    unsigned long long int ret = (left + right) / 2;

	while (1) {
        unsigned long long int tmp = guess(ret);

        if (tmp == 0) {
            return ret;
        }

        if (tmp == -1) {
            right = ret - 1;
        }

        if (tmp == 1) {
            left = ret + 1;
        }

        ret = (left + right) / 2;
    }
}
// @lc code=end

