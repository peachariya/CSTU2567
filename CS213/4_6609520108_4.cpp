#include <iostream>
using namespace std;

void print(int data[], int size) {
 cout << "Print array" << endl;
 for (int i=0; i<size; i++) {
 cout << data[i] << ", ";
 }
 cout << endl;
 }
 void setZero(int* &a, int size) {
 for (int i=0; i<size; i++) {
 *a = 0;
 a++;
}
}
 void setVal(int a[], int size, int val) {
 for (int i=0; i<size; i++) {
 a[i] = val;
 }
}

 int main(int argc, char** argv) {
 const int MAX_SIZE = 5;

 int *arr = new int[MAX_SIZE];
 // int arr[MAX_SIZE];

 setVal(arr, MAX_SIZE, 12);
 print(arr, MAX_SIZE);

 setZero(arr, MAX_SIZE);
 print(arr, MAX_SIZE);

 return 0;
 }