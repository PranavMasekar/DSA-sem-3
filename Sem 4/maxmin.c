#include <stdio.h>

int max, min;
int a[100];
void MaxMin(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            MaxMin(i, mid);
            max1 = max;
            min1 = min;
            MaxMin(mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}

void main()
{
    int i, arr;
    printf("\nEnter the size of array : ");
    scanf("%d", &arr);
    printf("Enter the numers in array : ");
    for (i = 1; i <= arr; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];
    MaxMin(1, arr);
    printf("Minimum in an array : %d\n", min);
    printf("Maximum in an array : %d\n", max);
}
