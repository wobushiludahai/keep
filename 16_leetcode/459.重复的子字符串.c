/*
 * @lc app=leetcode.cn id=459 lang=c
 *
 * [459] 重复的子字符串
 */

// @lc code=start


bool repeatedSubstringPattern(char * s){
    int len = strlen(s);

    for (int i = 1; i * 2 <= len; i++) {
        if (len % i != 0) {
            continue;
        }

        int num = len / i;
        int match = true;
        for (int j = 0; j < i; j++) {
            for (int k = 1; k < num; k++) {
                if (s[j + k * i] != s[j]) {
                    match = false;
                    break;
                }
            }

            if (match == false) {
                break;
            }
        }

        if (match == true) {
            return true;
        }
    }

    return false;
}
// @lc code=end

