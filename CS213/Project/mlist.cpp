#include "mlist.h" // รวมไฟล์ header สำหรับคลาส MessengerList
#include <iostream> // รวมไฟล์สำหรับการใช้งาน input/output

using namespace std; // ใช้ namespace std เพื่อไม่ต้องเขียน std:: ทุกครั้ง

// คอนสตรัคเตอร์ของคลาส MessengerList
MessengerList::MessengerList() {
    head = nullptr; // กำหนดหัวของลิสต์เป็น nullptr (ลิสต์ว่าง)
}

// ดีสตรัคเตอร์ของคลาส MessengerList
MessengerList::~MessengerList() {
    Node* temp = head; // ตั้งค่าชั่วคราว temp เป็นหัวของลิสต์
    if (temp != nullptr) { // ตรวจสอบว่าลิสต์ไม่ว่าง
        Node* nextNode; // สร้างตัวแปรชั่วคราวสำหรับโหนดถัดไป
        while (temp->next != head) { // ลูปจนกว่าจะถึงจุดเริ่มต้นอีกครั้ง
            nextNode = temp->next; // เก็บโหนดถัดไป
            delete temp; // ลบโหนดปัจจุบัน
            temp = nextNode; // ย้ายไปยังโหนดถัดไป
        }
        delete temp; // ลบโหนดสุดท้าย (head)
    }
}

// ฟังก์ชันสำหรับเพิ่ม Messenger เข้าไปในลิสต์
void MessengerList::addMessenger(Messenger m) {
    Node* newNode = new Node(m); // สร้างโหนดใหม่
    if (head == nullptr) { // ถ้าลิสต์ว่าง
        head = newNode; // ตั้งค่า head เป็นโหนดใหม่
        head->next = head; // เชื่อมโยงโหนดกับตัวเอง (วงกลม)
    } else {
        Node* temp = head; // ตั้งค่า temp เป็น head
        while (temp->next != head) { // หาตำแหน่งสุดท้ายของลิสต์
            temp = temp->next; // ย้าย temp ไปยังโหนดถัดไป
        }
        temp->next = newNode; // เชื่อมโยงโหนดสุดท้ายกับโหนดใหม่
        newNode->next = head; // เชื่อมโยงโหนดใหม่กลับไปที่ head
    }
}

// ฟังก์ชันสำหรับลบ Messenger ตาม ID
void MessengerList::deleteMessenger(int id) {
    if (head == nullptr) return; // ถ้าลิสต์ว่าง ให้คืนค่า

    Node* current = head; // ตั้งค่า current เป็น head
    Node* prev = nullptr; // ตัวแปรสำหรับเก็บโหนดก่อนหน้า

    // ค้นหาโหนดที่มี ID ตรงกัน
    while (current->messenger.getID() != id) {
        prev = current; // อัพเดท prev เป็น current
        current = current->next; // ย้าย current ไปยังโหนดถัดไป
        if (current == head) return; // ถ้ากลับมาที่ head หมายความว่าไม่พบ
    }

    // กรณีถ้าเป็นโหนดแรกที่ต้องลบ
    if (current == head && current->next == head) {
        delete current; // ลบ current
        head = nullptr; // ตั้งค่า head เป็น nullptr (ลิสต์ว่าง)
    } else if (current == head) { // ถ้าเป็นโหนดแรก
        prev = head; // อัพเดท prev เป็น head
        while (prev->next != head) prev = prev->next; // หาหมายเลขก่อนหน้า head
        head = head->next; // ย้าย head ไปยังโหนดถัดไป
        prev->next = head; // เชื่อมโยงโหนดสุดท้ายกับ head ใหม่
        delete current; // ลบ current
    } else { // ถ้าลบโหนดอื่น
        prev->next = current->next; // เชื่อมโยงโหนดก่อนหน้ากับโหนดถัดไป
        delete current; // ลบ current
    }
}

// ฟังก์ชันสำหรับพิมพ์รายชื่อ Messenger ทั้งหมดในลิสต์
void MessengerList::printMessengerList() {
    if (head == nullptr) return; // ถ้าลิสต์ว่าง ให้คืนค่า

    Node* temp = head; // ตั้งค่า temp เป็น head
    do {
        cout << temp->messenger.getName() << " "; // พิมพ์ชื่อของ Messenger
        temp = temp->next; // ย้ายไปยังโหนดถัดไป
    } while (temp != head); // ทำซ้ำจนกว่าจะกลับมาที่ head
    cout << endl; // พิมพ์บรรทัดใหม่
}

// ฟังก์ชันสำหรับค้นหาผู้ถือข่าวร้ายตามลำดับขั้น
Messenger MessengerList::findBadNewsBearer(int step) {
    Node* current = head;

    while (current->next != current) {
        for (int i = 1; i < step; ++i) {
            current = current->next;
        }

        // Print the name of the messenger being removed
        cout << current->messenger.getName() << " is removed" << endl;
        
        // Store the ID of the messenger to be removed
        int id = current->messenger.getID();
        
        // Delete the messenger from the list
        deleteMessenger(id);

        // Print remaining messengers
        cout << "===================================" << endl;
        cout << "Persons left in circle: ";
        printMessengerList();
        cout << "===================================" << endl;

        // Reset current to the next node after deletion
        // This ensures we continue the counting correctly
        if (head != nullptr) { // Check if the list is not empty
            current = head; // Reset current to head for the next iteration
            for (int i = 1; i < step; ++i) {
                current = current->next;
            }
        }
    }
    
    return current->messenger; // Return the last remaining messenger
}

