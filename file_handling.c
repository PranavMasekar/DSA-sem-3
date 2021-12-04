#include <stdio.h>
#include <string.h>
struct player{
   char name[20];
   float avg;
   int highestscore;
};

void acceptdata(struct player e[],int n){
int i;
for (int i = 0; i <n; i++)
{
    printf("Enter the name,avg,highest score of the player \n");
    scanf(" %s %f %d",&e[i].name,&e[i].avg,&e[i].highestscore);
    
}
}
void writetofile(struct player e[],int n)
{
    FILE *fp;
    fp = fopen("data.txt", "a");
    if (fp == NULL)
    {  
        printf("Error");
        return ;
    }
    else{
        for (int i = 0; i <n; i++)
        {
            fprintf(fp,"%s %f %d",e[i].name,e[i].avg,e[i].highestscore);
            fputs("\n",fp);
            
        }
        
    }
    fclose(fp);
}

void readfile(int n){
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct player commingdata[n];
    if (fp == NULL)
    {  
        printf("Error");
        return ;
    }
    else{
        for (int i = 0; i <n; i++)
        {
            fscanf(fp,"%s %f %d",&commingdata[i].name,&commingdata[i].avg,&commingdata[i].highestscore);
            fputs("\n",fp);  
        }
        
    }
    fclose(fp);
    for(int i=0;i<n;i++){
        printf("%s has average score as %f and highest score is %d.\n",commingdata[i].name,commingdata[i].avg,commingdata[i].highestscore);
    }   
}

void search(int n){
    FILE *fp;
    fp = fopen("data.txt", "r");
    struct player commingdata[n];
    if (fp == NULL)
    {  
        printf("Error");
        return ;
    }
    else{
        for (int i = 0; i <n; i++)
        {
            fscanf(fp,"%s %f %d",&commingdata[i].name,&commingdata[i].avg,&commingdata[i].highestscore);
            fputs("\n",fp);  
        }
        
    }
    fclose(fp);
    char name[20];
    printf("Enter the name of player ");
    scanf("%s",name);
     for (int i = 0; i <n; i++)
        {
            if(strcmp(commingdata[i].name,name)==0){
                printf("%s has average score as %f and highest score is %d.\n",commingdata[i].name,commingdata[i].avg,commingdata[i].highestscore);
            }
        }
}

int main(){
    struct player e[50];
    int n;
    printf("enter the total number of Players ");
    scanf("%d",&n);
    // acceptdata(e,n);
    // writetofile(e,n);
    // readfile(n);
    search(n);
     return 0;
}