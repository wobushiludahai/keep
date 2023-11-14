/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
// @lc code=end

