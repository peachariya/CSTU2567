#ifndef MESSENGER_H
#define MESSENGER_H

#include <string>
using namespace std;

class Messenger {
private:
    static int nextID;
    int id;
    string name;
    char sex;
    int expr;

public:
    Messenger(string name, char sex, int expr);
    string getName();
    int getID();
    char getSex();
    int getExpr();
};

#endif
