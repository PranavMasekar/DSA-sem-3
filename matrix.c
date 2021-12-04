#include <stdio.h>
int size;
int i=1;
int j=1;

void getmatrix(int (*arr)[size], int size){
    printf("Enter the values in matrix %d\n",j);
    j++;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void display(int (*arr)[size], int size)
{
    printf("\nShowing the matrix %d \n",i);
    i++;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void addition(int (*arr1)[size],int (*arr2)[size], int size,int (*arr3)[size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
        
    }
}

void substract(int (*arr1)[size],int (*arr2)[size], int size,int (*arr3)[size]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
        
    }
}

int main()
{
    printf("Enter the size of array - ");
    scanf("%d", &size);
    int mat1[size][size];
    int mat2[size][size];
    int mat3[size][size];

    getmatrix(mat1,size);
    getmatrix(mat2,size);

    display(mat1,size);
    display(mat2,size);

    // addition(mat1,mat2,size,mat3);
    // printf("\n*****Addition of two matrices is**** \n");
    substract(mat1,mat2,size,mat3);
    printf("\n*****Substraction of two matrices is**** \n");
    display(mat3,size);
    return 0;
}