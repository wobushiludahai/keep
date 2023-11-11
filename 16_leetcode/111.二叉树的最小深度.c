/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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
int getMinDepth(struct TreeNode* root, int depth)
{
    if (root == NULL) {
        return depth;
    }

    if (root->left == NULL && root->right == NULL) {
        return depth + 1;
    }

    int left = 0xfffffff;
    int right = 0xfffffff;
    if (root->left != NULL) {
        left = getMinDepth(root->left, depth + 1);
    }
    if (root->right != NULL) {
        right = getMinDepth(root->right, depth + 1);
    }

    return left < right ? left : right;
}

int minDepth(struct TreeNode* root) {
    return getMinDepth(root, 0);
}
// @lc code=end

