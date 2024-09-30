#include <iostream>  // นำเข้าไลบรารีสำหรับการป้อนและแสดงผลข้อมูล
#include <fstream>   // นำเข้าไลบรารีสำหรับการอ่านและเขียนไฟล์
#include <sstream>   // นำเข้าไลบรารีสำหรับการจัดการกับสตริงและสตรีม
#include "mlist.h"   // นำเข้าไฟล์ header ที่กำหนดโครงสร้างของ Messenger และ MessengerList

using namespace std; // ใช้ namespace std เพื่อไม่ต้องพิมพ์ std:: ทุกครั้ง

int main() {
    MessengerList list; // สร้างออบเจ็กต์ MessengerList เพื่อเก็บข้อมูลผู้ส่งสาร
    ifstream file("messenger.txt"); // เปิดไฟล์ messenger.txt เพื่ออ่านข้อมูล
    string line; // สร้างตัวแปรสำหรับเก็บแต่ละบรรทัดที่อ่านจากไฟล์

    // โหลดข้อมูลผู้ส่งสารจากไฟล์และเพิ่มเข้าไปในรายการ
    cout << "Loading data from file 'messenger.txt'" << endl; // แสดงข้อความโหลดข้อมูล
    cout << "ID    NAME  SEX EXPERIENCE" << endl; // แสดงหัวตาราง
    cout << "===================================" << endl;

    int id = 1; // ตั้งค่า ID เริ่มต้นเป็น 1
    while (getline(file, line)) { // อ่านข้อมูลทีละบรรทัดจากไฟล์จนกว่าจะหมด
        stringstream ss(line); // สร้าง stringstream จากบรรทัดที่อ่านได้
        string name; // ตัวแปรเก็บชื่อ
        char sex; // ตัวแปรเก็บเพศ
        int expr; // ตัวแปรเก็บประสบการณ์

        getline(ss, name, ','); // แยกชื่อออกจากบรรทัดโดยใช้จุลภาคเป็นตัวแบ่ง
        ss >> sex; // อ่านเพศ
        ss.ignore(1, ','); // ข้ามจุลภาคถัดไป
        ss >> expr; // อ่านประสบการณ์

        // แสดงข้อมูลที่โหลดมา
        cout << id << "    " << name << "   " << sex << "   " << expr << endl;

        Messenger m(name, sex, expr); // สร้างออบเจ็กต์ Messenger ใหม่
        list.addMessenger(m); // เพิ่มผู้ส่งสารลงใน MessengerList
        id++; // เพิ่ม ID ขึ้น 1
    }
    cout << "===================================" << endl; // แสดงเส้นขีดแบ่ง

    file.close(); // ปิดไฟล์หลังจากอ่านเสร็จ

    // แสดงรายชื่อผู้ส่งสารในวงกลมก่อนเริ่มกระบวนการคัดเลือก
    cout << "Persons left in circle: "; 
    list.printMessengerList(); // แสดงรายชื่อผู้ส่งสารทั้งหมด
    cout << "===================================" << endl;

    // รับค่าจากผู้ใช้สำหรับหมายเลขขั้นตอน
    int step; 
    cout << "Select number: "; 
    cin >> step; // รับหมายเลขจากผู้ใช้
    cout << "Press any key..." << endl; // แสดงข้อความให้กดปุ่มใด ๆ

    // ทำการคัดเลือกและแสดงผลตามที่กำหนดในไฟล์
    Messenger badNewsBearer = list.findBadNewsBearer(step); // ค้นหาผู้ส่งข่าวร้ายตามหมายเลขที่ผู้ใช้เลือก

    // แสดงผลลัพธ์สุดท้าย
    cout << "===================================" << endl; 
    cout << badNewsBearer.getName() << " is the bad news bearer !!" << endl; // แสดงชื่อของผู้ส่งข่าวร้าย

    return 0; // คืนค่า 0 หมายถึงโปรแกรมทำงานเสร็จเรียบร้อย
}
