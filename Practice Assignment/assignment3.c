#include<stdio.h>
#include<strings.h>
struct product{
    int code;
    char name[10];
    int price;
};

void getdata(struct product * ptr){
    printf("Enter the code,price,name of product :");
    scanf("%d",&ptr->code);
    scanf(" %d",&ptr->price);
    scanf("%s",&ptr->name);

}

void putdata(struct product * ptr){
    printf("The name of product is %s \n",ptr->name);
    printf("The code of product is %d \n",ptr->code);
    printf("The price of product is %d \n",ptr->price);
}
int main(){
    int p;
    printf("How many products do you want to add to cart :");
    scanf("%d",&p);
    struct product data[p];
    for(int i=0;i<p;i++){
        getdata(&data[i]);
    }
    for(int i=0;i<p;i++){
        putdata(&data[i]);
    }


    return 0;
}