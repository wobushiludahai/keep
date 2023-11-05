/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
int lengthOfLastWord(char* s) {
    int len = strlen(s);

    int i = len - 1;
    for (; i >= 0; i--) {
        if (s[i] != ' ') {
            break;
        }
    }

    int j = i;
    for (; j >= 0; j--) {
        if (s[j] == ' ') {
            break;
        }
    }

    return i - j;
}
// @lc code=end

