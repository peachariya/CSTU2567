#ifndef MLIST_H  // ตรวจสอบว่าไฟล์นี้ถูกสร้างขึ้นหรือยัง ถ้ายังไม่ถูกสร้างจะทำการสร้างขึ้น
#define MLIST_H

#include "messenger.h"  // รวมไฟล์ header ของ Messenger ที่ต้องการใช้ในคลาสนี้

// ประกาศคลาส Node ซึ่งใช้สำหรับสร้างโหนดในลิสต์
class Node {
public:
    Messenger messenger;  // ตัวแปรเก็บอ็อบเจ็กต์ Messenger
    Node* next;  // ตัวชี้ไปยังโหนดถัดไป

    // คอนสตรัคเตอร์สำหรับ Node ที่รับ Messenger และกำหนด next เป็น nullptr
    Node(Messenger m) : messenger(m), next(nullptr) {}
};

// ประกาศคลาส MessengerList ซึ่งใช้สำหรับจัดการลิสต์ของ Messenger
class MessengerList {
private:
    Node* head;  // ตัวชี้ไปยังหัวของลิสต์

public:
    MessengerList();  // คอนสตรัคเตอร์สำหรับสร้างลิสต์
    ~MessengerList();  // ดีสตรัคเตอร์สำหรับทำความสะอาดลิสต์
    void addMessenger(Messenger m);  // ฟังก์ชันสำหรับเพิ่ม Messenger ลงในลิสต์
    void deleteMessenger(int id);  // ฟังก์ชันสำหรับลบ Messenger ตาม id ที่กำหนด
    void printMessengerList();  // ฟังก์ชันสำหรับพิมพ์ลิสต์ของ Messenger
    Messenger findBadNewsBearer(int step);  // ฟังก์ชันสำหรับค้นหา Messenger ที่เป็นผู้ส่งข่าวร้าย
};

#endif  // สิ้นสุดการตรวจสอบว่าไฟล์นี้ถูกสร้างขึ้นหรือยัง
