/*
 * @lc app=leetcode.cn id=520 lang=c
 *
 * [520] 检测大写字母
 */

// @lc code=start
bool detectCapitalUse(char * word){
    int len = strlen(word);
    if (len == 1) return true;
    bool is_first_big = true;
    bool is_second_big = true;

    if (word[0] >= 'a' && word[0] <= 'z') {
        is_first_big = false;
    }

    if (word[1] >= 'a' && word[1] <= 'z') {
        is_second_big = false;
    }

    if (is_first_big == false && is_second_big == true) {
        return false;
    } else if (is_first_big == true && is_second_big == false) {
        for (int i = 2; i < len; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            }
        }
    } else if (is_first_big == true && is_second_big == true) {
        for (int i = 2; i < len; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                return false;
            }
        }
    } else if (is_first_big == false && is_second_big == false) {
        for (int i = 2; i < len; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            }
        }
    }

    return true;
}
// @lc code=end

