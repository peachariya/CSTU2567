#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "mlist.h" // include header files for mlist and messenger 
#include "messenger.h"

using namespace std;

int main() {
    MessengerList messengerList;
    ifstream inputFile("messenger.txt");

    if (inputFile.is_open()) {
        string name, sexStr;
        int expr;

        while (getline(inputFile, name, ',')) {
            getline(inputFile, sexStr, ',');
            inputFile >> expr;
            inputFile.ignore();
            char sex = sexStr[0];
            Messenger* messenger = new Messenger(name, sex, expr);
            messengerList.addMessenger(messenger);
        }

        inputFile.close();
    } else {
        cout << "Error opening file 'messenger.txt'\n";
        return 1;
    }

    cout << "Loading data from file 'messenger.txt'\n";
    messengerList.printMessengerList();

    int removeNumber;
    cout << "Select number: ";
    cin >> removeNumber;

    for (int i = 0; i < removeNumber; ++i) {
        cout << "Press any key... ";
        cin.ignore();
        messengerList.deleteMessenger();
        cout << "Persons left in circle\n";
        messengerList.printMessengerList();
    }

    cout << "Press any key.......\n";
    cin.ignore();
    cout << messengerList.head->messenger->getName() << " is the bad news bearer!!\n";

    return 0;
}