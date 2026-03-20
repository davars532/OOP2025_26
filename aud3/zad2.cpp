//
// Created by David Arsov on 11.3.26.
//

#include <iostream>

using namespace std;

// Да се напише класа Date во која ќе се чуваат ден, месец и година (цели броеви).



class Date {
private:
    int day, month, year;

public:
    Date(int _day, int _month, int _year) {
        day = _day;
        month = _month;
        year = _year;
    }

    Date() {

    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }
};

int compareDates(Date d1, Date d2) {
    if (d1.getYear() != d2.getYear()) {
        return d1.getYear() - d2.getYear();
    }

    if (d1.getMonth() != d2.getMonth()) {
        return d1.getMonth() - d2.getMonth();
    }

    return d1.getDay() - d2.getDay();
    // 10 03 2026
    // 07 03 2026
}
// Да се напише класа Employee во која се чува име на вработениот (не повеќе од 20 знаци),
// плата и датум на раѓање (објект од класата Date).

class Employee {
private:
    char name[20];
    int salary;
    Date dateOfBirth;

public:
    Employee(char * _name, int _salary, Date _dateOfBirth) {
        strcpy(name, _name);
        salary = _salary;
        dateOfBirth = _dateOfBirth;
    }

    Employee() {

    }

    int getSalary() {
        return salary;
    }

    Date getDateOfBirth() {
        return dateOfBirth;
    }

    void print() {
        cout << "Ime: " << name << endl << "Salary: " << salary << endl;
    }
};

class Company {
private:
    char name[50];
    Date dateEstablished;
    Employee employees[100];
    int numEmployee;

public:
    Company(char* _name, Date _dateEstablished, Employee* _employees, int _numEmployees) {
        strcpy(name, _name);
        dateEstablished = _dateEstablished;

        for (int i = 0; i < _numEmployees; i++) {
            employees[i] = _employees[i];
        }

        numEmployee = _numEmployees;
    }

    Company(char* _name, Date _dateEstablished) {
        strcpy(name, _name);
        dateEstablished = _dateEstablished;

        numEmployee = 0;
    }

    void addEmployee(Employee e) {
        if (numEmployee != 100) {
            employees[numEmployee] = e;
            numEmployee++;
        } else {
            cout << "Nizata so vraboteni e polna";
        }
    }

    Employee getEmployeeWithLargestSalary() {
        Employee maxSalary = employees[0];

        for (int i = 0; i < numEmployee; i++) {
            if (employees[i].getSalary() > maxSalary.getSalary()) {
                maxSalary = employees[i];
            }
        }

        return maxSalary;
    }

    Employee getYoungestEmployee() {
        Employee youngest = employees[0];

        for (int i = 0; i < numEmployee; i++) {
            Date db1 = youngest.getDateOfBirth();
            Date db2 = employees[i].getDateOfBirth();

            if (compareDates(db1, db2) < 1) {
                youngest = employees[i];
            }
        }

        return youngest;
    }

    void print() {
        cout << "Ime na kompanija: " << name << endl;
        cout << "Broj na vraboteni: " << numEmployee << endl;

        cout << "Najmlad vraboten: " << endl;
        getYoungestEmployee().print();

        cout << "Najplaten vraboten: " << endl;
        getEmployeeWithLargestSalary().print();
    }

};



int main() {

    Date d1(10, 3, 2010);
    Date d2(2, 3, 2020);
    Date d3(3, 4, 2030);
    Date d4(4, 5, 2030);

    Employee employee1("Test Emp1", 30000, d1);
    Employee employee2("Test Emp2", 30000, d2);
    Employee employee3("Test Emp3", 30000, d3);

    Company c("Test Company", d4);

    c.addEmployee(employee1);
    c.addEmployee(employee2);

    employee1.print();
    employee2.print();

    c.print();

}