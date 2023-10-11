/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
int strStr(char * haystack, char * needle){
    int ret = -1;

    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int i, j;

    for (i = 0; i < len1; i++) {
        if (haystack[i] != needle[0]) {
            continue;
        }

        for (j = 1; j < len2; j++) {
            if (haystack[i+j] != needle[j]) {
                break;
            }
        }

        if (j == len2) {
            ret = i;
            break;
        }
    }

    return ret;
}
// @lc code=end

