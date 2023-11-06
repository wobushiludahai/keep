/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 */

// @lc code=start
unsigned long long int get_sum(unsigned long long num)
{
    unsigned long long int sum = 0;
    while (num) {
        sum += (num % 10) * (num % 10);
        num /= 10;
    }

    return sum;
}

bool isHappy(int n) {
    unsigned long long int num = n;

    while (1) {
        if (num == 1) {
            return true;
        }

        num = get_sum(num);
        if (num == 4) {
            return false;
        }

        if (num > 0xffffffff) {
            return false;
        }
    }
}
// @lc code=end

