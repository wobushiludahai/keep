/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start
void reverse_str(char *src, char *dest, int len)
{
    printf("test len %d\n", len);
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - i - 1];
    }
}

char* reverseStr(char* s, int k) {
    char tmp_buf[10001] = {0};
    int len = strlen(s);
    int traverse = 0;
    strcpy(tmp_buf, s);

    while (1) {
        if (len <= 2 * k) {
            if (len < k) {
                reverse_str(tmp_buf + traverse, s + traverse, len);
            } else {
                reverse_str(tmp_buf + traverse, s + traverse, k);
            }

            break;
        }


        reverse_str(tmp_buf + traverse, s + traverse, k);
        traverse += (2 * k);
        len -= (2 * k);
    }

    return s;
}
// @lc code=end

