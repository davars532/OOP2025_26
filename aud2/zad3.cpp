//
// Created by David Arsov on 4.3.26.
//

#include <iostream>

using namespace std;

// Да се напише класа во која ќе се чуваат основни податоци за вработен:

// име
// плата
// работна позиција (работната позиција може да биде вработен, директор или шеф).

// Напишете главна програма во која се читаат од стандарден влез податоци
// за N вработени, а потоа се пачати листа на вработените сортирани според
// висината на платата во опаѓачки редослед.
//
enum Pozicija {
    Vraboten,
    Direktor,
    Sef
};
class Employee {
    char name[100];
    int salary;
    Pozicija rabotnaPozicija;

public:
    Employee(char *_name, int _salary, Pozicija _pozicija) {
        strncpy(name, _name, 99);
        name[99] = '\0';
        salary = _salary;
        rabotnaPozicija = _pozicija;
    }

    Employee() {
    }

    char *getName() {
        return name;
    }

    int getSalary() {
        return salary;
    }

    Pozicija getPozicija() {
        return rabotnaPozicija;
    }

    void setName(char *_name) {
        strncpy(name, _name, 99);
        name[99] = '\0';
    }

    void setSalary(int _salary) {
        salary = _salary;
    }

    void setPozicija(Pozicija _pozicija) {
        rabotnaPozicija = _pozicija;
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Pozicija: " << rabotnaPozicija << endl;
    }
};



// Напишете главна програма во која се читаат од стандарден влез податоци
// за N вработени, а потоа се пачати листа на вработените сортирани според
// висината на платата во опаѓачки редослед.

void sortVraboteni(Employee* vraboteni, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (vraboteni[j].getSalary() > vraboteni[j + 1].getSalary()) {
                Employee temp = vraboteni[j];
                vraboteni[j] = vraboteni[j + 1];
                vraboteni[j + 1] = temp;
            }
        }
    }
}

int main() {
    Employee vraboteni[100];

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        int salary;
        int pozicija;

        cin >> name >> salary >> pozicija;

        // Employee v(name, salary, (Pozicija) pozicija);

        Employee v;
        v.setName(name);
        v.setSalary(salary);
        v.setPozicija((Pozicija) pozicija);
        vraboteni[i] = v;
    }

    sortVraboteni(vraboteni, n);

    for (int i = 0; i < n; i++) {
        vraboteni[i].print();
        // cout << "Name: " << vraboteni[i].getName() << endl;
        // cout << "Salary: " << vraboteni[i].getSalary() << endl;
        // cout << "Pozicija: " << vraboteni[i].getPozicija() << endl;
    }
    return 0;
}