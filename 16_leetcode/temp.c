#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int **ans = malloc(sizeof(int *) * numRows);

    for (int i = 0; i < numRows; i++) {
        ans[i] = malloc(sizeof(int) * (i + 1));
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

    // returnColumnSizes = ans;
    return ans;
}

int main(void)
{
    int numRows = 5;
    int *test_return = NULL;
    generate(5, &numRows, &test_return);

    return 0;
}
