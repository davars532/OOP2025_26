//
// Created by David Arsov on 4.3.26.
//

#include <iostream>

using namespace std;

// Да се напише класа која опишува една e-mail порака. Во класата треба да се
// имплементира метод за прикажување на целокупната порака на екран. Потоа да
// се напише главна програма во која се внесуваат параметрите на пораката, се
// инстанцира објект од оваа класа и се печати на екран неговата содржина. За
// проверување на валидноста на e-mail пораката (постоење на знакот @ во адресата)
// да се напише соодветна функција.

class Email {
private:
    char to[100];
    char from[100];
    char subject[100];
    char body[1000];

public:
    Email(char* _to, char* _from, char* _subject, char* _body) {
        strncpy(to, _to, 99);
        to[99] = '\0';
        strncpy(from, _from, 99);
        from[99] = '\0';
        strncpy(subject, _subject, 99);
        subject[99] = '\0';
        strncpy(body, _body, 999);
        body[999] = '\0';
    }

    void print() {
        cout << "To: " << to << endl;
        cout << "From: " << from << endl;
        cout << "Subject: " << subject << endl;
        cout << body << endl;
    }
};

//tets@to@.com

bool checkMail(char* mail) {
    int count = 0;
    for (int i = 0; i < strlen(mail); i++) {
        if (mail[i] == '@') {
            count++;
        }
    }

    if (count == 1) {
        return true;
    } else {
        return false;
    }

    // return count == 1;
}

int main() {
    char to[100];
    char from[100];
    char subject[100];
    char body[1000];

    cin >> to >> from;
    cin.ignore();
    cin.getline(subject, 100);
    cin.getline(body, 1000);

    if (checkMail(to) == true && checkMail(from) == true) {
        Email email(to, from, subject, body);
        email.print();
    } else {
        cout << "Vnesovte nevalidna adresa";
    }



    return 0;
}