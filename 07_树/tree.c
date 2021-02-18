#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef struct tree
{
    Node *root;
} Tree;


// 先序遍历
void preorder(Node *node)
{
    if (node != NULL) {
        printf("%d\n", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// 中序遍历
void inorder(Node *node)
{
    if (node != NULL) {
        inorder(node->left);
        printf("%d\n", node->data);
        inorder(node->right);
    }
}

// 后序遍历
void postorder(Node *node)
{
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\n", node->data);
    }
}

// BST 二叉搜索树 左》根》右    中序遍历都是从小往大增加 
// 6 3 8 2 5 1 7

void insert(Tree *tree, int value)
{
    Node *node = malloc(sizeof(int));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    if (tree->root == NULL) {
        tree->root = node;
    } else {
        Node *temp = tree->root;
        while (temp != NULL) {
            if (value < temp->data) {
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = node;
                    return;
                } else {
                    temp = temp->right;
                }
            }
        }
        
    }
}

int get_height(Node *node)
{
    if (node == NULL) {
        return 0;
    } else {
        int left_h = get_height(node->left);
        int right_h = get_height(node->right);
        int max = (left_h > right_h) > left_h : right_h;
        return max + 1;
    }
}

int get_maxnum(Node *node) {
    if (node == NULL) {
        return -1;
    } else {
        int m1 = get_maxnum(node->left);
        int m2 = get_maxnum(node->right);
        int m3 = node->data;
        int max = m1;
        if (m2 > max) { max = m2; }
        if (m3 > max) { max = m3; }
        return max;
    }
}

int main(void)
{
    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    Tree tree;
    tree.root = NULL;

    for (int i= 0; i < 7; i++) {
        insert(&tree, arr[i]);
    }

    preorder(tree.root);
    inorder(tree.root); 
}