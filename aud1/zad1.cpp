//
// Created by David Arsov on 25.2.26.
//

#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    void vnesi() {
        cin >> day >> month >> year;
    }

    void pecati() {
        cout << day << "/" << month << "/" << year << endl;
    }

    int sporedi(Date d2) {

        // 25 2 2026 d1
        // 26 3 2026 d2
        if (year > d2.year) {
            return 1;
        } else if (year < d2.year) {
            return -1;
        } else {
            if (month > d2.month) {
                return 1;
            } else if (month < d2.month) {
                return -1;
            } else {
                if (day > d2.day) {
                    return 1;
                } else if (day == d2.day) {
                    return 0;
                } else {
                    return -1;
                }
            }
        }
    }

    int sporedi2(Date d2) {
        // 25 2 2025
        // 26 2 2026

        if (d2.year != year) {
            return year - d2.year;
        }

        if (d2.month != month) {
            return month - d2.month;
        }

        return day - d2.day;
    }

    int denovi() {
        int denovi = day;
        denovi += month * 30;
        denovi += year * 365;
        return denovi;
    }
};

void vnesiDatum(Date &d) {
    cin >> d.day >> d.month >> d.year;

    cout << "Od funkcija: " << endl;
    cout << d.day << "/" << d.month << "/" << d.year << endl;

}

// Да се напише програма која ќе споредува два датуми (ден, месец, година)
// и ќе ја пресмета разликата во денови од едниот до другиот датум.
// Пресметките да се реализираат
// во посебни функции. За датумот да се дефинира посебна структура date.

int main() {
    Date datum1;
    Date datum2;
    Date datum3;

    cin >> datum1.day >> datum1.month >> datum1.year;
    cout << datum1.day << "/" << datum1.month << "/" << datum1.year << endl;

    vnesiDatum(datum2);
    cout << datum2.day << "/" << datum2.month << "/" << datum2.year << endl;

    if (datum1.sporedi(datum2) > 0) {
        cout << datum1.denovi() - datum2.denovi() << endl;
    } else {
        cout << datum2.denovi() - datum1.denovi() << endl;
    }
}