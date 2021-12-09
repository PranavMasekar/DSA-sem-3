#include <stdio.h>
#include <string.h>
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
        }
    }
    fclose(fp);
    for (int i = 0; i < n; i++)
    {
        printf("%s %f %d \n", commingdata.name, commingdata.avg, commingdata.highestscore);
    }
}

void search(int n)
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct player commingdata[n];
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
}


int main()
{
    struct player e[50];
    int n;
    printf("enter the total number of Players ");
    scanf("%d", &n);
    // acceptdata(e,n);
    // writetofile(e,n);
    // readfile(n);
    // search(n);
    // delete(e,n);
    return 0;
}