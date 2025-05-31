#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// โครงสร้างข้อมูลสำหรับเก็บคำและหมายเลขบรรทัด
struct HashEntry {
    string word;
    vector<int> lineNumbers;
};

int hashFunction(const string& key) {
    long long sum = 0;
    for (char c : key) {
        sum += (int)c;
    }
    return (sum * sum) % 1001; // ตารางขนาด 1001
}

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<HashEntry> hashTable(1001, {"", {}}); // ตารางแฮชขนาด 1001
    int collisionCount = 0;
    int lineNumber = 1;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            // ทำความสะอาดคำ
            string cleanWord;
            for (char c : word) {
                if (isalnum(c)) {
                    cleanWord += tolower(c);
                }
            }
            if (cleanWord.empty()) continue;

            // คำนวณตำแหน่งแฮช
            int index = hashFunction(cleanWord);
            int originalIndex = index;

            // หาอินเด็กซ์ที่เหมาะสม (Linear Probing)
            while (!hashTable[index].word.empty() && hashTable[index].word != cleanWord) {
                collisionCount++;
                index = (index + 1) % 1001; // Linear Probing
                if (index == originalIndex) {
                    cerr << "Hash table is full!" << endl;
                    return 1;
                }
            }

            // เพิ่มคำหรืออัปเดตหมายเลขบรรทัด
            if (hashTable[index].word.empty()) {
                hashTable[index].word = cleanWord;
            }
            hashTable[index].lineNumbers.push_back(lineNumber);
        }
        lineNumber++;
    }
    inputFile.close();

    // แสดงตารางแฮช
    cout << "Index\tWord\t\tLine Numbers" << endl;
    for (int i = 0; i < hashTable.size(); ++i) {
        if (!hashTable[i].word.empty()) {
            cout << i << "\t" << hashTable[i].word << "\t\t";
            for (int num : hashTable[i].lineNumbers) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    cout << "Total collisions: " << collisionCount << endl;

// การค้นหา
string searchWord;
while (true) {
    cout << "Enter search word : ";
    cin >> searchWord;
    if (searchWord == "quit") break;

    // ทำความสะอาดคำ
    transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);

    int index = hashFunction(searchWord);
    int originalIndex = index;
    bool found = false;

    // ค้นหาด้วย Linear Probing
    while (!hashTable[index].word.empty()) {
        if (hashTable[index].word == searchWord) {
            // คำที่ค้นหาเจอ
            cout << "Found at line numbers: ";
            for (int num : hashTable[index].lineNumbers) {
                cout << num << " ";
            }
            cout << endl;
            found = true;
            break;
        } else {
            // คำที่เกิด Collision
            cout << "Collision: " << hashTable[index].word << endl;
        }
        index = (index + 1) % 1001; // Linear Probing
        if (index == originalIndex) break;
    }

    if (!found) {
        cout << "Word not found." << endl;
    }
}


    return 0;
}
