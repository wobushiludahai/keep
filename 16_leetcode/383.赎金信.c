/*
 * @lc app=leetcode.cn id=383 lang=c
 *
 * [383] 赎金信
 */

// @lc code=start
bool canConstruct(char * ransomNote, char * magazine){
    int ransomNoteLen = strlen(ransomNote);
    int magazineLen = strlen(magazine);
    for (int i = 0; i < ransomNoteLen; i++) {
        char target = ransomNote[i];
        int j;
        for (j = 0; j < magazineLen; j++) {
            if (target == magazine[j]) {
                magazine[j] = ' ';
                break;
            }
        }

        if (j == magazineLen) {
            return false;
        }
    }

    return true;
}
// @lc code=end

