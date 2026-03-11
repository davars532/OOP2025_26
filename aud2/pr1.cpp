//
// Created by David Arsov on 4.3.26.
//

#include <iostream>

using namespace std;

struct Student {
    char name[100];
    int age;
};

class StudentClass {
    private:
    char name[100];
    int age;
    public:
        StudentClass(char* _name, int _age) {
            strncpy(name, _name, 99);
            name[99] = '\0';

            age = _age;
        }

        int getAge() {
            return age;
        }

        char* getName() {
            return name;
        }

        void setAge(int _age) {
            age = _age;
        }

        void setName(char* _name) {
            strncpy(name, _name, 99);
            name[99] = '\0';
        }
};

int main() {

    Student student;
    cin >> student.name;
    cin >> student.age;

    char name[100];
    int age;

    cin >> name;
    cin >> age;

    StudentClass studentClass(name, age);

    cout << "Name: " << studentClass.getName() << endl;
    cout << "Age: " << studentClass.getAge() << endl;

    char newName[100] = "New Name";
    studentClass.setName(newName);
    studentClass.setAge(23);

    cout << "Name: " << studentClass.getName() << endl;
    cout << "Age: " << studentClass.getAge() << endl;

    return 0;
}