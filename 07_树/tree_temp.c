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

int arr[7] = {8, 1, 2, -1, 5, 6, -1, 1, 2};
int position = 1;

void insert_tree(Node *node)
{
    int left = arr[position];
    int right = arr[position + 1];

    if (position > sizeof(arr)) {
        return;
    }

    position += 2;
    if (left != -1) {
        Node *temp = malloc(sizeof(int));
        node->data = left;
        node->left = NULL;
        node->right = NULL;
        node->left = temp;
    }

    if (right != -1) {
        Node *temp = malloc(sizeof(int));
        node->data = right;
        node->left = NULL;
        node->right = NULL;
        node->right = temp;
    }

    if (left != -1) {
        insert_tree(node->left);
    }

    if (right != -1) {
        insert_tree(node->right);
    }

}

int main(void)
{
    int arr[7] = {8, 1, 2, -1, 5, 6, -1, 1, 2};
    Node *node = malloc(sizeof(int));
    node->data = arr[0];
    node->left = NULL;
    node->right = NULL;

    for (int i = 1; i < sizeof(arr); i += 2) {


    }
}