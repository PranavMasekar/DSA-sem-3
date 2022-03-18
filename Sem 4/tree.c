#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tree
{
    char val;
    struct tree *left;
    struct tree *right;
} TreeNode;

typedef struct node
{
    TreeNode *data;
    struct node *next;
} STACK;

STACK *top = NULL;

TreeNode *CreateNode(char c)
{
    TreeNode *newnode = (TreeNode *)malloc(sizeof(TreeNode));
    newnode->val = c;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void push(TreeNode *p)
{
    STACK *ptr = (STACK *)malloc(sizeof(STACK));
    ptr->data = p;
    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
}

TreeNode *pop()
{
    TreeNode *item;
    STACK *ptr = top;
    item = top->data;
    top = top->next;
    free(ptr);
    return item;
}

void Inorder(TreeNode *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%c ", root->val);
        Inorder(root->right);
    }
}

void Preorder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->val);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(TreeNode *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%c ", root->val);
    }
}

void PostFixExpression()
{
    char exp[20];
    printf("Enter the expression :");
    scanf("%s", exp);

    for (int i = 0; i < strlen(exp); i++)
    {
        TreeNode *current = CreateNode(exp[i]);
        if (isalpha(exp[i]))
        {
            push(current);
        }
        else
        {
            current->right = pop();
            current->left = pop();
            push(current);
        }
    }
    TreeNode *root = pop();
    while (1)
    {
        printf("Enter the choice for Tree Traversal i.e.\n(1)Inorder\n(2)Preorder\n(3)Postorder\n(4)Exit\n:");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            Inorder(root);
            printf("\n");
        }
        else if (choice == 2)
        {

            Preorder(root);
            printf("\n");
        }
        else if (choice == 3)
        {
            Postorder(root);
            printf("\n");
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {

            printf("Invalid Choice......");
        }
    }
}

void PreFixExpression()
{
    char exp[20];
    printf("Enter the expression :");
    scanf("%s", exp);
    // 	strrev(exp);
    for (int i = strlen(exp) - 1; i >= 0; i--)
    {
        TreeNode *current = CreateNode(exp[i]);
        if (isalpha(exp[i]))
        {
            push(current);
        }
        else
        {
            current->left = pop();
            current->right = pop();
            push(current);
        }
    }
    TreeNode *root = pop();
    while (1)
    {
        printf("Enter the choice for Tree Traversal i.e.\n(1)Inorder\n(2)Preorder\n(3)Postorder\n(4)Exit\n:");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            Inorder(root);
            printf("\n");
        }
        else if (choice == 2)
        {

            Preorder(root);
            printf("\n");
        }
        else if (choice == 3)
        {
            Postorder(root);
            printf("\n");
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {

            printf("Invalid Choice......");
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Select Input Expression Type\n(1)Prefix\n(2)Postfix\n(3)Exit\n: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            PreFixExpression();
        }
        else if (choice == 2)
        {
            PostFixExpression();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid Choice......");
        }
    }
    return 0;
}