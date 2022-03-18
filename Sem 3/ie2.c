#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *InsertAtEnd(struct node *head, int n)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}
struct node *deleteatindex( struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p = p->next = q->next;
    free(q);
    return head;
}
void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
 int main()
{
    struct node *head = NULL;
    int a;
    int k, modified_K;
    for (int i = 0; i <10; i++)
    {
        scanf("%d",&a);
        head = InsertAtEnd(head, a);
    }
    scanf("%d",&k);
    if(k>10){
        k=k-10;
        modified_K=10-k;
    }
    else{
        modified_K=10-k;
    }
    deleteatindex( head,modified_K);
    display( head);
     return 0;
}