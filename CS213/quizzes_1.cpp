#include <iostream>
using namespace std;
void func(int* arr){
    arr[3] = 5;
    arr= new int[5];
    for(int i=0;i<5;i++) arr[i] = 0;
}

int main(){

    int A[]={1,2,3,4,5};
    int* pt;

    pt= A;

   func(pt);

   A[1] = 1;

   return 0;

}