#include <stdio.h>

int main (void){
    int x, y;
    scanf("%d%d", &x, &y);
    if(y==8)
    {
        if(x==5){
            printf("@@@@");
        }else{
            printf("####");
        }
        printf("$$$$");
        printf("&&&&");
    }
}
