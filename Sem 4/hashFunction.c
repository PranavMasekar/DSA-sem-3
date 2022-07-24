#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10
// SYITA130 - Ashish
// SYITA137 - Atharva
// SYITA140 - Vansh
struct abc
{
    char name[30];
    char ph[20];
    struct abc *next;
};
int hashcode(char name[]);
void insert(char name[], char ph[]);
void display();

struct abc *head[size], *p;

int main()
{
    char name[20], ph[20];
    int ch;
    do
    {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter Phone Number: ");
        scanf("%s", ph);
        printf("Enter your choice: ");
        scanf("%d", &ch);
        insert(name, ph);
    } while (ch == 1);

    display();
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        p = head[i];
        while (p != NULL)
        {
            printf("Name:%s\n Phone No:%s\n\n", p->name, p->ph);
            p = p->next;
            // printf("|%d",i);
        }
    }
}

void insert(char name[], char ph[])
{
    struct abc *temp;
    temp = (struct abc *)malloc(sizeof(struct abc));
    strcpy(temp->name, name);
    strcpy(temp->ph, ph);
    temp->next = NULL;
    int key = hashcode(name);
    int a = key % 10;
    if (head[a] == NULL)
        head[a] = temp;
    else
    {
        p = head[a];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int hashcode(char name[])
{
    int l = strlen(name);
    int n;
    printf("%d \n",n);
    for (int i = 0; i < n; i++)
    {
        n = n * 10 + (name[i] - 1);
    }
    return n;
}