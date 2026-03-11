//
// Created by David Arsov on 25.2.26.
//

#include <iostream>

using namespace std;

// Да се напише програма која од стандарден влез ќе чита податоци за
// држави и на екран ќе го отпечати името и презимето на претседателот
// на државата чиj што главен град има најмногу жители.
//
//

//

// Податоци за претседател:
//
// име
// презиме
// политичка партија.

// Податоци за држава:
//
// име
// претседател
// главен град
// број на жители.
// Податоци за град:
// име
// број на жители.

struct City {
    char name[50];
    int citizens;
};

struct President {
    char name[50];
    char surname[50];
    char party[50];
};

struct Country {
    char name[50];
    President president;
    City capital;
    int citzens;
};

void read(Country &c) {
    cin >> c.name >> c.president.name >> c.president.surname
    >> c.president.party >> c.capital.name >> c.capital.citizens >> c.citzens;
}


// Country1 N1 S1 P1 C1 1000 2000
// Country2 N2 S2 P2 C2 1500 2000
// Country3 N3 S3 P3 C2 1200 2000
// Country4 N4 S4 P4 C4 1500 2000


int main() {
    Country countries[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        read(countries[i]);
    }

    Country max = countries[0];

    for (int i = 0; i < n; i++) {
        if (countries[i].capital.citizens >= max.capital.citizens) {
            max = countries[i];
        }
    }

    cout << max.president.name << " " << max.president.surname << endl;

    return 0;
}