#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(int argc, char** argv){
 string filename = "my_activities.txt";
 ofstream fout(filename.c_str(), ios::out);
 if (!fout) {
 cerr << "Error: open file for output failed!" << endl;
 abort(); // in <cstdlib> header
 }
 fout << "My_yesterday_activities:" << endl;
 fout << "9:00AM,Had_breakfast_(Boiled_eggs)." << endl;
 fout << "1:30PM,Took_CS348_Class." << endl;
 fout << "5:00PM,Read_books_with_friends." << endl;
 fout.close();
 return 0;
}