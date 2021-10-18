#include <stdio.h>

int isprime(int c){
    int i, flag = 0;
    for (i = 2; i <= c / 2; ++i) {
    if (c % i == 0) {
      flag = 1;
      break;
    }
  }

  if (c == 1) {
    return 0;
  } 
  else {
    if (flag == 0)
      return 1;
    else
      return 0;
  }
}
void Prime(int p , int q){
    for(int i=p;i<=q;i++){
        int x = isprime(i);
        if(x){
            printf("%d \n" , i);
        }
    }

}
int main(){
    int a,b;
    printf("Enter the Range of numbers :");
    scanf("%d %d",&a,&b);
    Prime(a,b);
    return 0;
}