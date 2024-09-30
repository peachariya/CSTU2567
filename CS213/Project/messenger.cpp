#include "messenger.h"

int Messenger::nextID = 1;

Messenger::Messenger(string name, char sex, int expr) {
    this->id = nextID++; // ตั้งค่า ID ของ Messenger เป็นค่า nextID แล้วเพิ่มค่า nextID ขึ้น 1
    this->name = name;   // ตั้งค่า name ของ Messenger
    this->sex = sex;     // ตั้งค่า sex ของ Messenger
    this->expr = expr;   // ตั้งค่า expr (ประสบการณ์) ของ Messenger
}

string Messenger::getName() {
    return name; // คืนค่า name ของ Messenger
}

int Messenger::getID() {
    return id;   // คืนค่า id ของ Messenger
}

char Messenger::getSex() {
    return sex;  // คืนค่า sex ของ Messenger
}

int Messenger::getExpr() {
    return expr; // คืนค่า expr (ประสบการณ์) ของ Messenger
}
