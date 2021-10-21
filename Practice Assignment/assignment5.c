#include<stdio.h>
#include<string.h>
int calclength(char *s){
    int c=0;
    while (s[c] != '\0')
    c++;
    return c;
}

void reverse(char *s , int size){
    char rev[size];
    int end = size-1;
    int i;
    for( i=0;i<size;i++){
        rev[end] = s[i];
        end--;
    }
    rev[i]='\0';
    printf("The reversed string is %s\n",rev);
}

void compare(char *s , char *p){
    int flag = 1;
    int s1 = calclength(s);
    int s2 = calclength(p);
    if (s1 == s2)
    {
        for (int i = 0; i < s1; i++)
        {
            if (s[i] != p[i])
            {
                flag = 0;
                break;
            }
        }
    }
    else
        flag = 0;

    if(flag==1) printf("Strings are equal \n");
    else{
        printf("Strings are not equal \n");
    }
}

int main(){
    printf("Enter the string ");
    char str[20],com[20];
    scanf("%s",&str);

    int size = calclength(str);
    printf("The size of the string is %d \n",size);

    reverse(str,size);

    printf("Enter the string to compare ");
    scanf("%s",&com);

    compare(str,com);
    return 0;
}