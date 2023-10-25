/*
 * @lc app=leetcode.cn id=345 lang=c
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start

bool isVowels(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }

    return false;
}


char * reverseVowels(char * s){
    int len = strlen(s);

    for (int i = 0, j = len - 1; i < j;) {
        if (isVowels(s[i]) == false) {
            i++;
            continue;
        }

        if (isVowels(s[j]) == false) {
            j--;
            continue;
        }

        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }

    return s;
}
// @lc code=end

