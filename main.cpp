#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    Student(int studentId, string studentName, float studentGpa) {
        id = studentId;
        name = studentName;
        gpa = studentGpa;
    }

    void display() const {
        cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
    }

    void saveToFile() const {
        ofstream outFile("student_database.txt", ios::app);
        if (outFile.is_open()) {
            outFile << id << "," << name << "," << gpa << endl;
            outFile.close();
        }
    }
};

void showMenu() {
    cout << "\n--- Student Database CLI ---" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float gpa;

            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> ws; // clear buffer
            getline(cin, name);
            cout << "Enter Student GPA: ";
            cin >> gpa;

            Student student(id, name, gpa);
            student.saveToFile();
            cout << "Student added successfully and saved to file!" << endl;

        } else if (choice == 2) {
            ifstream inFile("student_database.txt");
            string line;
            cout << "\n--- Saved Students ---" << endl;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        }

    } while (choice != 3);

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
