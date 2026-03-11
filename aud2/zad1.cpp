//
// Created by David Arsov on 4.3.26.
//

#include <iostream>

using namespace std;

class Cuboid {

private:
    int a, b, c;

    public:
        Cuboid(int _a, int _b, int _c) {
            a = _a;
            b = _b;
            c = _c;
        }

        int volume() {
            return a * b * c;
        }

        int area() {
            return 2 * (a * b + b * c + a * c);
        }

        ~Cuboid() {
            cout << "Destructor" << endl;
        }
};

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    Cuboid cuboid(a, b, c);

    cout << "Volumen: " << cuboid.volume() << endl;
    cout << "Plostina: " << cuboid.area() << endl;

    {
        Cuboid c1(1, 2, 3);
    }
    return 0;
}