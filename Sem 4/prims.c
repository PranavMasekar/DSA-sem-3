#include <stdio.h>
#include <math.h>
#define MAX 20
#define INF 1e5+10
void Create_Graph(int a[20][20], int n){
    int v1, v2, f, c;
    printf("Enter 1 for unidirected graph else enter 0 : ");
    scanf("%d", &f);
    do
    {
        printf("Enter the Edges : ");
        scanf("%d%d", &v1, &v2);
        printf("Enter the weight of the edge :");
        int w;
        scanf("%d",&w);
        a[v1][v2] = w; 
        if(f == 1)
        {
            a[v2][v1] = w;
        }
        printf("Do you want to continue (0/1): ");
        scanf("%d",&c);
    } while (c == 1);   
}
void Display(int a[20][20], int n){
    printf("Adjencecy Matrix of a Graph : \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void MST(int a[20][20],int n){
    int no_Edges = 0,cost = 0;
    int x,y;
    int selected[20];
    for(int i = 0 ; i<n ; i++){
        selected[i] = 0;
    }
    selected[0] = 1;
    while(no_Edges<n-1){
        int i,j,min = INF;
        x = 0;
        y = 0;
        for(i=0;i<n;i++){
            if(selected[i]) {
                for(j=0;j<n;j++) {
                    if(!selected[j]&&a[i][j]) {
                        if(min>a[i][j]) {
                            min = a[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d \n",x,y,a[x][y]);
        selected[y] = 1;
        cost+=a[x][y];
        no_Edges++;
    }
    printf("MST Cost is : %d \n",cost);
}

int main() {
    int n;
    printf("Enter the No. of vertices : ");
    scanf("%d",&n);
    int a[20][20] = {0};
    Create_Graph(a, n);
    Display(a, n);
    MST(a,n);
    return 0;
}