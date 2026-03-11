//
// Created by David Arsov on 4.3.26.
//

#include <iostream>
#include <cmath>

using namespace std;

// Да се напише класа за опишување на геометриско тело триаголник.
// Во класата да се напишат методи за пресметување на плоштината и
// периметарот на триаголникот.

// Потоа да се напише главна програма во која ќе се инстнацира еден
// објект од оваа класа со вредности за страните кои претходно ќе се
// прочитаат од стандарден влез. На овој објект да се повикат соодветните
// методи за пресметување на плоштината и периметарот.

class Triangle {
private:
    int a, b, c;

public:
    Triangle(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    int area() {
        int s = (a + b + c) / 2;
        int p = s * (s - a) * (s - b) * (s - c);
        return sqrt(p);
    }

    int perimeter() {
        return a + b + c;
    }

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    int getC() {
        return c;
    }

    void setA(int _a) {
        a = _a;
    }

    void setB(int _b) {
        b = _b;
    }

    void setC(int _c) {
        c = _c;
    }

};

// Потоа да се напише главна програма во која ќе се инстнацира еден
// објект од оваа класа со вредности за страните кои претходно ќе се
// прочитаат од стандарден влез. На овој објект да се повикат соодветните
// методи за пресметување на плоштината и периметарот.

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    Triangle t(a, b, c);

    cout << "A: " << t.getA() << endl;
    cout << "B: " << t.getB() << endl;
    cout << "C: " << t.getC() << endl;

    cout << t.area() << endl;
    cout << t.perimeter() << endl;

    t.setA(a + 1);
    t.setB(b + 1);
    t.setC(c + 1);

    cout << "A: " << t.getA() << endl;
    cout << "B: " << t.getB() << endl;
    cout << "C: " << t.getC() << endl;

    return 0;
}