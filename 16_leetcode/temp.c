#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

void preorder(struct TreeNode* root, int *res, int *returnSize)
{
    if (root == NULL) {
        return;
    }
    res[(*returnSize)++] = root->val;
    preorder(root->left, res, returnSize);
    preorder(root->right, res, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (root == NULL) {
        return res;
    }

    preorder(root, res, returnSize);

    return res;
}

int main(void)
{
    return 0;
}
