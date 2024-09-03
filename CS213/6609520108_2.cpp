#include <iostream>
using namespace std;
int squareArea(int w){
 int result;
 static int callCount = 0;
 callCount++;
 cout << "Call count: " << callCount << endl;
 result = w*w;
 return result;
}
int main(int argc, char **argv){
 cout << squareArea(5) << endl;
 cout << squareArea(6) << endl;
 cout << squareArea(7) << endl;
 return 0;
}