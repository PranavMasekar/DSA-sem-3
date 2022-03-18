#include <stdio.h>
#include <stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *ptr)
{
    printf("Elements in the queue \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue()
{
    int val;
    printf("Enter the value \n");
    scanf("%d", &val);
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("The queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("The queue is Empty");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    // display(f);
    // enqueue(4);
    // enqueue(10);
    // enqueue(6);
    // display(f);
    // printf("Dequeuing the element from queue %d \n", dequeue());
    while (1)
    {
        int choice = 0;
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            printf("%d is removed from the queue \n", dequeue());
            break;
        case 3:
            display(f);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}