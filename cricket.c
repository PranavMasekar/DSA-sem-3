#include <stdio.h>
#include <string.h>
// int n;
struct player
{
    char name[20], country[10];
    int category;
    int age, wick;
    int avg;
    int ODI, T20;
};
struct player p[5];
int player_count = 0;
void getdata(int pos[])
{
    char ch1;
    int i=0;
    do
    {
        printf("\nEnter the name of the player : ");
        scanf("%s", &p[player_count].name);
        printf("\nEnter the age of the player  : ");
        scanf("%d", &p[player_count].age);
        printf("\nEnter the Player Country : ");
        scanf("%s", &p[player_count].country);
        printf("\nEnter the category of the player\n1. Batsman\n2. Bowler\n3. Wicket Keeper\n4. All Rounder\n");
        scanf("%d", &p[player_count].category);
        printf("\nEnter the Number of International 20-20s played by the player : ");
        scanf("%d", &p[player_count].T20);
        printf("\nEnter the Number of ODI played by the player : ");
        scanf("%d", &p[player_count].ODI);
        printf("\nEnter the average batting score of the player : ");
        scanf("%d", &p[player_count].avg);
        printf("\nEnter the wickets taken by the player : ");
        scanf("%d", &p[player_count].wick);
        printf("\nDo you want to add more data (y/n)");
        scanf(" %c", &ch1);
        pos[i] = i;
        i++;
        player_count++;
    } while (ch1 == 'y');
}

void batsmenbycountry()
{
    char entry[10];
    printf("\nEnter the Country of the batsmen : ");
    scanf("%s", entry);
    for (int i = 0; i < player_count; i++)
    {
        if (!strcmp(p[i].country, entry))
        {
            if (p[i].category == 1 || p[i].category==4)
            {
                printf("%s belongs to %s \n", p[i].name, entry);
            }
        }
    }
}

void bowlerbycountry()
{
    char entry[10];
    printf("\nEnter the Country of the bowler : ");
    scanf("%s", entry);
    for (int i = 0; i < player_count; i++)
    {
        if (!strcmp(p[i].country, entry))
        {
            if (p[i].category == 2 || p[i].category==4)
            {
                printf("%s belongs to %s \n", p[i].name, entry);
            }
        }
    }
}
void HighestAge(){
    int max=p[0].age;
    char currentage[20];
    strcpy(currentage,p[0].name);
    for (int i = 1; i < player_count; i++)
    {
       if(p[i].age > max){
           max = p[i].age;
           strcpy(currentage,p[i].name);
       }
    }
    printf("%s has the highest age i.e. %d \n",currentage,max);

}
void highestwicket(){
    int max=p[0].wick;
    char currentbowlername[20];
    strcpy(currentbowlername,p[0].name);
    for (int i = 1; i < player_count; i++)
    {
       if(p[i].wick > max){
           max = p[i].wick;
           strcpy(currentbowlername,p[i].name);
       }
    }
    printf("%s has the most wickets i.e. %d \n",currentbowlername,max);

}
void swap(int *xp, int *yp, int pos[], int j)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    int t = pos[j];
    pos[j] = pos[j + 1];
    pos[j + 1] = t;
}

void sort(int pos[])
{

    for (int i = 0; i < player_count; i++)
        for (int j = 0; j < player_count; j++)
            if (p[j].avg < p[j + 1].avg)
                swap(&p[j].avg, &p[j + 1].avg, pos, j);
    printf("\n");
    for (int i = 0; i < player_count; i++)
        printf("%s from %s and his avg is %d\n", p[pos[i]].name, p[pos[i]].country, p[i].avg);
}

void putdata()
{
    for (int i = 0; i < player_count; i++)
    {
        printf("Name:- %s \t\t Age:- %d \t\t Country:- %s \t\tODI:- %d\t\tT20:- %d \t\t Avg:- %d\t\t Wick:- %d", p[i].name, p[i].age, p[i].country, p[i].ODI, p[i].T20, p[i].avg, p[i].wick);
        if (p[i].category == 1)
        {
            printf("\t\tcategory:- Batsmen \n");
        }
        if (p[i].category == 2)
        {
            printf("\t\tcategory:- Bowler \n");
        }
        if (p[i].category == 3)
        {
            printf("\t\tcategory:- Wicket keeper \n");
        }
        if (p[i].category == 4)
        {
            printf("\t\tcategory:- All rounder \n");
        }
    }
    printf("\n\n");
}

int main()
{
    int pos[player_count];
    getdata(pos);
    int r=1;
     while (r)
    {
        printf("\nEnter the choice :\n");
        printf(" 1:Number Of batsmen of particular country \n 2:Sort by Batting avg \n 3:Highest age\n 4:Bowlers of particular country \n 5:Max Wicket Taker\n 6:Display All data\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            batsmenbycountry();
            break;
        case 2:
            sort(pos);
            break;
        case 3:
            HighestAge();
            break;
        case 4:
            bowlerbycountry();
            break;
        case 5:
            highestwicket();
            break;
        case 6:
            putdata();
            break;
        default :
            printf("Wrong choice");
            break;
        }

        printf("Do you want to perform another operation (1) or (0)");
        scanf("%d", &r);
    }
    return 0;
}