#include <stdio.h>
int SIZE = 7;
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void bubblesort(int *arr, int n)
{
    int sorted = 0;
    
    for (int i = 0; i < n; i++) //For number of passes
    {
        sorted = 1;
        for (int j = 0; j < n - 1 - i; j++) //For number of comparison
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                sorted = 0;
            }
        }
        if (sorted)
        { //Making bubble sort adaptive
            return;
        }
    }
}
void getdata(int *ptr)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter the element %d :", i + 1);
        scanf("%d", &ptr[i]);
    }
}

void display(int *ptr, int size)
{
    printf("\n {");
    int i = 0;
    for (i = 0; i < size - 1; i++)
    {
        printf("%d,", ptr[i]);
    }
    printf("%d", ptr[i]);
    printf("}\n");
}

void Uni(int *p, int *q)
{
    int x = 2 * SIZE;
    int arr[x];
    int temp = 0;

    int i, j, k = 0;
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = p[i];
        k++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        temp = 0;
        for (int j = 0; j < SIZE; j++)
        {

            if (q[i] == p[j])
            {
                break;
            }
            temp++;
        }
        if (temp == SIZE)
        {
            arr[k] = q[i];
            k++;
        }
    }
    
    display(arr, k);
}

void intersection(int *p, int *q)
{
    int ans[SIZE];
    int k = 0;
    int element;
    for (int i = 0; i < SIZE; i++)
    {
        element = p[i];
        for (int j = 0; j < SIZE; j++)
        {
            if (element == q[j])
            {
                ans[k] = element;
                k++;
            }
        }
    }
    display(ans, k);
}

int difference(int *p, int *q)
{
    int count = 0;
    int size = 0;
    int temp[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (p[i] != q[j])
            {
                count++;
            }
        }
        if (count == SIZE)
        {
            temp[size] = p[i];
            size++;
        }
    }
    display(temp, size);
}

void symmetric(int *p, int *q)
{
    int count = 0;
    int size = 0;
    int temp[2 * SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (p[i] != q[j])
            {
                count++;
            }
        }
        if (count == SIZE)
        {
            temp[size] = p[i];
            size++;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (q[i] != p[j])
            {
                count++;
            }
        }
        if (count == SIZE)
        {
            temp[size] = q[i];
            size++;
        }
    }
    for (int i = size; i < 2 * SIZE; i++)
    {
        temp[i] = 0;
    }
    display(temp, size);
}
int main()
{
    int r = 1;
    int arr1[SIZE], arr2[SIZE];
    printf("Enter the First Set :\n");
    getdata(arr1);
    printf("Enter the Second Set :\n");
    getdata(arr2);
    bubblesort(arr1, SIZE);
    bubblesort(arr2, SIZE);
    display(arr1, SIZE);
    display(arr2, SIZE);

    while (r)
    {
        printf("\nEnter the choice :\n");
        printf(" 1:Union Of Sets\n 2:Intersection of sets \n 3:Difference(A-B)\n 4:Difference(B-A)\n 5:Symmetric Difference in Sets\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Uni(arr1, arr2);
            break;
        case 2:
            intersection(arr1, arr2);
            break;
        case 3:
            difference(arr1, arr2);
            break;
        case 4:
            difference(arr2,arr1);
            break;
        case 5:
            symmetric(arr1, arr2);
            break;
        default :
            printf("Wrong choice");
            break;
        }

        printf("Do you want to perform another operation (1) or (0)");
        scanf("%d", &r);
    }

    // Uni(arr1,arr2);
    // intersection(arr1,arr2);
    // difference(arr1, arr2);
    // symmetric(arr1, arr2);
    return 0;
}