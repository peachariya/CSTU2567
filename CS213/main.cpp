#include <iostream>
#include "BST.h"
using namespace std;

// ฟังก์ชันหลักในการทดสอบการทำงานของโปรแกรม
int main() {
    BST bst;
    bst.read_employees("Employees-Ordered.txt"); // อ่านข้อมูลพนักงานจากไฟล์

    bst.build_tree_index(); // สร้าง BST จากข้อมูลพนักงาน
    cout << "The height of BST: " << bst.getHeight() << endl; // แสดงความสูงของ BST
    bst.removeAllIndices(); // ลบ Node ทั้งหมด

    int sN = 5; // จำนวนรอบการสุ่มข้อมูล
    cout << "... Try shuffling a number of times ..." << endl;

    // ลูปเพื่อสลับข้อมูลและสร้าง BST ใหม่
    for (int i = 0; i < sN; i++) {
        cout << "#" << i + 1 << " shuffle ..." << endl;
        bst.shuffleData(); // สลับลำดับข้อมูล
        bst.build_tree_index(); // สร้าง BST ใหม่
        cout << "The height of BST: " << bst.getHeight() << endl; // แสดงความสูงของ BST
        bst.removeAllIndices(); // ลบ Node ทั้งหมด
    }

    bst.build_tree_index(); // สร้าง BST สุดท้าย
    bst.inOrder(); // เรียง

    bst.build_tree_index();
    bst.inOrder();

    return 0;
}