#include <stdio.h>

int main()
{
    char name[20];
    printf("Enter the string ");
    scanf("%s", &name);
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] = name[i] - 32;
        }
        else if(name[i] >= 'A' && name[i] <= 'Z'){
            name[i] = name[i]+ 32;
        }
    }
    printf("%s", name);
    return 0;
}