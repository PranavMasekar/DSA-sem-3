#include <stdio.h>
#include <string.h>
int n;
struct player
{
    char name[20];
    float avg;
    int highestscore;
};

void acceptdata(struct player e[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name,avg,highest score of the player \n");
        scanf(" %s %f %d", &e[i].name, &e[i].avg, &e[i].highestscore);
    }
    n++;
}
void writetofile(struct player e[], int n)
{
    FILE *fp;
    fp = fopen("data.txt", "a");
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%s %f %d", e[i].name, e[i].avg, e[i].highestscore);
            fputs("\n", fp);
        }
    }
    fclose(fp);
}

void readfile(int n)
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct player commingdata;
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s %f %d", &commingdata.name, &commingdata.avg, &commingdata.highestscore);
            fputs("\n", fp);
            printf("%s %f %d \n", commingdata.name, commingdata.avg, commingdata.highestscore);
        }
    }
    fclose(fp);
}

void search(int n)
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct player commingdata[10];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s %f %d", &commingdata[i].name, &commingdata[i].avg, &commingdata[i].highestscore);
            fputs("\n", fp);
        }
    }
    fclose(fp);
    char name[20];
    printf("Enter the name of player ");
    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(commingdata[i].name, name) == 0)
        {
            printf("%s %f %d.\n", commingdata[i].name, commingdata[i].avg, commingdata[i].highestscore);
        }
    }
}

void delete ()
{
	int i,j;
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct player commingdata[50];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {	i=0;
        while(fscanf(fp, "%s %f %d", &commingdata[i].name, &commingdata[i].avg, &commingdata[i].highestscore)!=EOF)
        {
            i++;
        }
    }
    fclose(fp);
    
    for (j = 0; j < i; j++){
    	printf("\n%s %f %d\n",commingdata[j].name, commingdata[j].avg, commingdata[j].highestscore);
	}
    
    
    char name[20];
    printf("Enter the name of player ");
    scanf("%s", name);
    FILE *f2;
    f2 = fopen("data.txt", "w");
    if (f2 == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (j = 0; j < i; j++){
            if (strcmp(commingdata[j].name, name) == 0)
            {
                continue;
            }
            else
            {
                fprintf(f2, "%s %f %d", commingdata[j].name, commingdata[j].avg, commingdata[j].highestscore);
                fputs("\n", f2);
            } 
        }

    }
    fclose(f2);
    n--;
}


int main()
{
    struct player e[50];
    int r = 1;
    printf("enter the total number of Players ");
    scanf("%d", &n);
    while (r)
    {
        printf("\nEnter the choice :\n");
        printf(" 1:Accept the data\n 2:Write to the file\n 3:Read the file\n 4:Search in the file\n 5:Delete from the file\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            acceptdata(e,n);
            break;
        case 2:
            writetofile(e,n);
            break;
        case 3:
            readfile(n);
            break;
        case 4:
            search(n);
            break;
        case 5:
            delete(e,n);
            break;
        default :
            printf("Wrong choice");
            break;
        }

        printf("Do you want to perform another operation (1) or (0)");
        scanf("%d", &r);
    }
    // acceptdata(e,n);
    // writetofile(e,n);
    // readfile(n);
    // search(n);
    
    return 0;
}