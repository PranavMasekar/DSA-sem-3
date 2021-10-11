#include<stdio.h>

int addition(int p,int q){
    return p+q;
}
int substract(int p ,int q){
    return p-q;
}
int multiplication(int p,int q){
    return p*q;
}
float division(int p,int q){
    float x= (float)p/q;
    return x;
}

int main(){
    int r=1;
   while(r){
    printf("Enter the two numbers ");
    int x,y;
    scanf("%d %d",&x,&y);
    printf("\n1:Addition");
    printf("\n2:substraction");
    printf("\n3:multiplication");
    printf("\n4:division\n");
    int a;
    printf("Enter the choice ");
    scanf("%d",&a);

    switch(a){
        case 1: 
                printf("The addition of two numbers is %d",addition(x,y));
                break;
        case 2: 
                printf("The substraction of two numbers is %d",substract(x,y));
                break;
        case 3: 
                printf("The multiplication of two numbers is %d",multiplication(x,y));
                break;
        case 4: 
                printf("The division of two numbers is %.3f",division(x,y));
                break;
        default :
                printf("Wrong choice");
                break;
    }
    printf("\nDo you want to enter another pair 1 or 0 ");
    
    scanf("%d",&r);
   }
    return 0;
}