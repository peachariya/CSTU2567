#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    int ID;
    int age;
    int salary;
    Employee(int id, int ag, int srl) : ID(id), age(ag), salary(srl) {}
};

struct Node {
    Employee* emp;
    Node* left;
    Node* right;
    Node(Employee* e) : emp(e), left(nullptr), right(nullptr) {}
};

class BST {
    vector<Employee> employees;
    Node* root;

public:
    BST();
    void printEmployee(Employee* emp);
    void addNode(Employee* e);
    void read_employees(const string& filename);
    void build_tree_index();
    void deleteIndex(int ID);
    int getHeight();
    void removeAllIndices();
    void shuffleData();
    void inOrder();

private:
    void addNodeHelper(Node*& node, Employee* e);
    void deleteNodeHelper(Node*& node, int ID);
    int getHeightHelper(Node* node);
    void inOrderHelper(Node* node);
    void clearTree(Node*& node);
};

#endif
