/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
bool isValid(char * s){
    int len = strlen(s);
    char stack[10001];
    if (len % 2 == 1) {
        return false;
    }

    if (len == 0) {
        return true;
    }

    int top = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
            continue;
        }

        if (top == 0) {
            return false;
        }

        if (s[i] == ')' && stack[top - 1] == '(') {
            top--;
            continue;
        }

        if (s[i] == '}' && stack[top - 1] == '{') {
            top--;
            continue;
        }

        if (s[i] == ']' && stack[top - 1] == '[') {
            top--;
            continue;
        }

        return false;
    }

    if (top != 0) {
        return false;
    }

    return true;
}
// @lc code=end

