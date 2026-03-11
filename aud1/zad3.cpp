//
// Created by David Arsov on 25.2.26.
//

#include <iostream>

using namespace std;

struct ComplexNumber {
    float a;
    float b;

    ComplexNumber add(ComplexNumber c2) {
        ComplexNumber result;
        result.a = a + c2.a;
        result.b = b + c2.b;
        return result;

        // return {
        //     a + c2.a,
        //     b + c2.b
        // };
    }

    ComplexNumber subtract(ComplexNumber c2) {
        return {
            a - c2.a,
            b - c2.b
        };
    }

    ComplexNumber multiply(ComplexNumber c2) {
        return {
            a * c2.a - b * c2.b,
            b * c2.a + a * c2.b
        };
    }

    void pecati() {
        cout << a << " + " << b << " i" << endl;
    }
};

void vnesi(ComplexNumber &c) {
    cin >> c.a >> c.b;
}

int main() {
    ComplexNumber c1;
    ComplexNumber c2;

    vnesi(c1);
    vnesi(c2);

    ComplexNumber sum = c1.add(c2);
    ComplexNumber prod = c1.multiply(c2);
    ComplexNumber diff = c1.subtract(c2);

    sum.pecati();
    prod.pecati();
    diff.pecati();
}
