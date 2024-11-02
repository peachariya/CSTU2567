#include "BST.h"
#include <fstream>
#include <algorithm>
// ขออนุญาตเขียนอธิบายนะคะเพราะจะกลับมาทวนแล้วลืมมม
// ตัวสร้างคลาส BST ที่กำหนดค่า root เป็น nullptr
BST::BST() : root(nullptr) {}

// แสดงข้อมูลของพนักงาน
void BST::printEmployee(Employee* emp) {
    cout << "ID:" << emp->ID << ", Salary:" << emp->salary << ", Age:" << emp->age << endl;
}

// เพิ่ม Node ลงใน BST โดยเรียกฟังก์ชันช่วย addNodeHelper
void BST::addNode(Employee* e) {
    addNodeHelper(root, e);
}

// ฟังก์ชันช่วยในการเพิ่ม Node ลงใน BST ตามค่า ID
void BST::addNodeHelper(Node*& node, Employee* e) {
    if (!node) {                  // ถ้า Node ปัจจุบันว่าง
        node = new Node(e);       // สร้าง Node ใหม่และกำหนดค่า
    } else if (e->ID < node->emp->ID) {  // ถ้า ID น้อยกว่า Node ปัจจุบัน
        addNodeHelper(node->left, e);    // ไปทางซ้าย
    } else {                             // ถ้า ID มากกว่า Node ปัจจุบัน
        addNodeHelper(node->right, e);   // ไปทางขวา
    }
}

// อ่านข้อมูลพนักงานจากไฟล์ และเพิ่มลงใน vector employees
void BST::read_employees(const string& filename) {
    ifstream file(filename); // เปิดไฟล์
    int id, salary, age;
    while (file >> id >> salary >> age) { // อ่านข้อมูลแต่ละบรรทัด
        employees.push_back(Employee(id, age, salary)); // เพิ่มข้อมูลลงใน vector
    }
}

// สร้างต้นไม้ BST โดยใช้ข้อมูลใน vector employees
void BST::build_tree_index() {
    for (auto& emp : employees) { // วนลูปใน employees
        addNode(&emp);            // เพิ่มแต่ละพนักงานเข้าใน BST
    }
}

// ลบ Node ที่มี ID ตรงกับที่กำหนดโดยเรียกฟังก์ชันช่วย deleteNodeHelper
void BST::deleteIndex(int ID) {
    deleteNodeHelper(root, ID);
}

// ฟังก์ชันช่วยในการลบ Node
void BST::deleteNodeHelper(Node*& node, int ID) {
    if (!node) return; // ถ้า Node ว่าง ออกจากฟังก์ชัน
    if (ID < node->emp->ID) {
        deleteNodeHelper(node->left, ID); // ไปทางซ้าย
    } else if (ID > node->emp->ID) {
        deleteNodeHelper(node->right, ID); // ไปทางขวา
    } else {
        Node* temp = node; // เก็บ Node ปัจจุบันไว้ชั่วคราว
        if (!node->left) { // ถ้าไม่มีลูกซ้าย
            node = node->right; // เชื่อมโยงกับลูกขวา
        } else if (!node->right) { // ถ้าไม่มีลูกขวา
            node = node->left; // เชื่อมโยงกับลูกซ้าย
        } else { // มีลูกทั้งสองข้าง
            Node* succ = node->right; // หา Node ที่มีค่าใกล้เคียง
            while (succ->left) succ = succ->left;
            node->emp = succ->emp;
            deleteNodeHelper(node->right, succ->emp->ID);
        }
        delete temp; // ลบ Node
    }
}

// คำนวณความสูงของต้นไม้ BST โดยเรียกฟังก์ชันช่วย getHeightHelper
int BST::getHeight() {
    return getHeightHelper(root);
}

// ฟังก์ชันช่วยในการหาความสูงของต้นไม้
int BST::getHeightHelper(Node* node) {
    if (!node) return 0;
    return 1 + max(getHeightHelper(node->left), getHeightHelper(node->right));
}

// ลบ Node ทั้งหมดใน BST และทำให้ root เป็น nullptr
void BST::removeAllIndices() {
    clearTree(root);
    root = nullptr;
}

// ฟังก์ชันช่วยในการลบ Node ทั้งหมด
void BST::clearTree(Node*& node) {
    if (!node) return;
    clearTree(node->left);   // ลบ Node ซ้าย
    clearTree(node->right);  // ลบ Node ขวา
    delete node;             // ลบ Node ปัจจุบัน
    node = nullptr;          // ตั้งค่าเป็น nullptr
}

// สลับลำดับข้อมูลพนักงานใน vector employees แบบสุ่ม
void BST::shuffleData() {
    random_shuffle(employees.begin(), employees.end());
    cout << "Shuffling Done." << endl;
}

// เรียงลำดับพนักงานตาม ID โดยการเดินแบบ InOrder
void BST::inOrder() {
    inOrderHelper(root);
}

// ฟังก์ชันช่วยในการเรียงลำดับแบบ InOrder
void BST::inOrderHelper(Node* node) {
    if (!node) return;
    inOrderHelper(node->left);
    printEmployee(node->emp);
    inOrderHelper(node->right);
}
