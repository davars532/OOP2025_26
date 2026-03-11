//
// Created by David Arsov on 25.2.26.
//

#include <complex>
#include <iostream>

using namespace std;

// Од стандарден влез се читаат податоци за непознат број студенти (не повеќе од 100). Податоците се внесуваат така што во секој ред се состои од:

/*името
презимето
бројот на индекс (формат xxyzzzz)
четири броја (поени од секоја задача)*/

struct Student {
    char name[50];
    char surname[50];
    char indeks[8];
    int point[4];
    int totalPoints;

    void print() {
        cout << name << " " << surname << " " << indeks << endl;
    }

    int getTotalPoints() {
        return point[0] + point[1] + point[2] + point[3];
    }

    void printList() {
        // презиме, име, број на индекс, вкупен број на бодови
        cout << surname << " " << name << " " << indeks << " " << totalPoints << endl;
        // cout << surname << " " << name << " " << indeks << " " << getTotalPoints() << endl;
    }
};

void normalize(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    str[0] = toupper(str[0]);
}

void read(Student &s) {
    cin >> s.name >> s.surname >> s.indeks;
    cin >> s.point[0] >> s.point[1] >> s.point[2] >> s.point[3];
    s.totalPoints = s.point[0] + s.point[1] + s.point[2] + s.point[3];

    normalize(s.name);
    normalize(s.surname);
}

//tEsT Student 2211000 1 2 3 4


int main() {
    Student students[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        read(students[i]);
        students[i].print();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (students[j].totalPoints > students[j + 1].totalPoints) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        students[i].printList();
    }

    return 0;
}

