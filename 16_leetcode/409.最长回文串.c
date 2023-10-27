/*
 * @lc app=leetcode.cn id=409 lang=c
 *
 * [409] 最长回文串
 */

// @lc code=start


int longestPalindrome(char * s){
    int testbuf[257] = {0};
    int len = strlen(s);
    int max = 0;

    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        testbuf[s[i]]++;
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (testbuf[i] % 2 == 0) {
            max += testbuf[i];
            continue;
        }

        if (testbuf[i] > 2) {
            max += testbuf[i] - 1;
        }
    }

    for (int i = 'A'; i <= 'Z'; i++) {
        if (testbuf[i] % 2 == 0) {
            max += testbuf[i];
            continue;
        }

        if (testbuf[i] > 2) {
            max += testbuf[i] - 1;
        }
    }

    if (max == len) {
        return max;
    }

    return max + 1;
}
// @lc code=end

