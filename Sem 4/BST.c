
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
struct node *search(struct node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            printf(" key is present ");
        }
        else if (root->data > key)
        {
            search(root->left, key);
        }
        else
        {
            search(root->right, key);
        }
    }
    else
    {
        printf("key is not present");
    }
}
void printInorder(struct node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = newNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int maxDepth(struct node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
void print_level(struct node *tempo, int level)
{
    if (tempo == NULL)
    {
        return;
    }
    else if (level == 0)
    {
        printf("%d ", tempo->data);
    }
    else if (level > 0)
    {
        print_level(tempo->left, level - 1);
        print_level(tempo->right, level - 1);
    }
}
void lever_order_traversal(struct node *root)
{
    for (int level = 0; level <= maxDepth(root); level++)
    {
        print_level(root, level);
        printf("\n");
    }
}
void mirror(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct node *temp;
        mirror(node->left);
        mirror(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
//
int main()
{
    int rut;
    printf("ENter root value of tree ");
    scanf("%d", &rut);
    struct node *root = newNode(rut);
    int z, ok;
    printf("Number of nodes in tree :");
    scanf("%d", &z);
    for (int okk = 1; okk <= z; okk++)
    {
        printf("enter number ");
        scanf("%d", &ok);
        insert(root, ok);
    }
    int ch;
    do
    {
        printf("\n 1. insert ");
        printf("\n 2. delete ");
        printf("\n 3. searching element ");
        printf("\n 4. mirror img");
        printf("\n 5. display ");
        printf("\n 6. display level order");
        printf("\n 7. exit");
        int ch;
        printf("\n\tENTER YOUR CHOICE :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the number which you want to insert ");
            int kk;
            scanf("%d", &kk);
            insert(root, kk);
            break;
        }
        case 2:
        {
            int test;
            printf("Enter value ");
            scanf("%d", &test);
            deleteNode(root, test);
            break;
        }
        case 3:
        {
            int key;
            printf("Enter the number which you want to search ");
            scanf("%d", &key);
            search(root, key);
            break;
        }
        case 4:
        {
            mirror(root);
            printInorder(root);
            break;
        }
        case 5:
        {
            printInorder(root);
            break;
        }
        case 6:
        {
            lever_order_traversal(root);
            break;
        }
        }
    } while (ch != 6);
}
