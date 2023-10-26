/*
 * @lc app=leetcode.cn id=389 lang=c
 *
 * [389] 找不同
 */

// @lc code=start


char findTheDifference(char * s, char * t){
    int s_len = strlen(s);
    int t_len = strlen(t);
    int test_buf[2000] = {0};
    int j;

    for (int i = 0; i < t_len; i++) {
        for (j = 0; j < s_len; j++) {
            if (test_buf[j] == 1) {
                continue;
            }

            if (s[j] == t[i]) {
                test_buf[j] = 1;
                break;
            }
        }

        if (j == s_len) {
            return t[i];
        }
    }

    return 0;
}
// @lc code=end

