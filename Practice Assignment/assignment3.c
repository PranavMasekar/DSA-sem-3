#include <stdio.h>
#include <string.h>
struct Product
{
    char code[10];
    char name[20];
    int price;
} product[4];

struct BillGenerator
{
    char name[10];
    int quantity;
    int price;
} Bill[100];

void setdata()
{
    strcpy(product[0].code, "101");
    strcpy(product[0].name, "Laptop");
    product[0].price = 35000;

    strcpy(product[1].code, "202");
    strcpy(product[1].name, "Mobile");
    product[1].price = 20000;

    strcpy(product[2].code, "303");
    strcpy(product[2].name, "ipad");
    product[2].price = 60000;

    strcpy(product[3].code, "404");
    strcpy(product[3].name, "Alexa");
    product[3].price = 15000;
}
int main()
{
    char cont = 'y', counter = 0;
    int finalprice = 0;
    setdata();
    printf("\nWelcome to the shop\n\nWhat do you want to buy?\n\n");
    while (cont == 'y')
    {
        printf("Sr.No\tName\tCode\tprice\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d.\t%s\t%s\tRs.%d\n", i + 1, product[i].name, product[i].code, product[i].price);
        }
        int choice, quantity;
        scanf("%d", &choice);
        printf("Enter the quantity you want : ");
        scanf("%d", &quantity);
        switch (choice)
        {
        case 1:
            strcpy(Bill[counter].name, product[0].name);
            Bill[counter].quantity = quantity;
            Bill[counter].price = product[0].price * quantity;
            break;
        case 2:
            strcpy(Bill[counter].name, product[1].name);
            Bill[counter].quantity = quantity;
            Bill[counter].price = product[1].price * quantity;
            break;
        case 3:
            strcpy(Bill[counter].name, product[2].name);
            Bill[counter].quantity = quantity;
            Bill[counter].price = product[2].price * quantity;
            break;
        case 4:
            strcpy(Bill[counter].name, product[3].name);
            Bill[counter].quantity = quantity;
            Bill[counter].price = product[3].price * quantity;
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to buy more things (y/n) : ");
        scanf(" %c", &cont);
        counter++;
    }
    printf("\nYour Bill is\n");
    printf("Sr.No.\tName\tQuantity\tPrice\n");
    for (int i = 0; i < counter; i++)
    {
        printf("%d\t%s\t%d\t\t%d\n", i + 1, Bill[i].name, Bill[i].quantity, Bill[i].price);
        finalprice += Bill[i].price;
    }
    printf("Final Bill : %d", finalprice);
}