#include <stdio.h>
int main (){
    int a = 5;
    a+= 3;
    printf ("a+= 3: %d\n",a);
    a-= 2;
    printf ("a-= 2: %d\n",a);
    a*= 2;
    printf ("a*= 2: %d\n",a);
    a/= 4;
    printf ("a/= 4 %d\n",a);
    a%= 3;
    printf ("a%%= 3 %d\n",a);

    return 0;
}