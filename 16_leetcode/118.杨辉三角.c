/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int **ans = malloc(sizeof(int *) * numRows);
    *returnColumnSizes = malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        ans[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        if (i == 0) {
            ans[i][0] = 1;
            continue;
        }

        if (i == 1) {
            ans[i][0] = 1;
            ans[i][1] = 1;
            continue;
        }

        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j <= i-1; j++) {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
    }

    return ans;
}
// @lc code=end

