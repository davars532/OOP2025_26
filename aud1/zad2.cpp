//
// Created by David Arsov on 25.2.26.
//

#include <iostream>

using namespace std;

// Да се напише програма која ќе го пресметува векторскиот и скаларниот
// производ на два вектори. Векторите се претставени со координати во
// тродимензионален координатен систем. Скаларниот и векторскиот производ да се пресметуваат со посебни функции.
// За вектор да се дефинира посебна структура vector.

struct Vector {
    int x;
    int y;
    int z;

    void vnesi() {
        cin >> x >> y >> z;
    }

    void pecati() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    int skalraen(Vector v2) {
        return x * v2.x + y * v2.y + z * v2.z;
    }
};

int main() {

    Vector v1, v2;

    v1.vnesi();
    v2.vnesi();

    v1.pecati();
    v2.pecati();

    cout << v1.skalraen(v2) << endl;
    return 0;
}