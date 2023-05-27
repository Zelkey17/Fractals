//
// Created by ash on 16.05.23.
//

#include "Complex.h"

Complex Complex::operator+(Complex &s) const {
    return {a + s.a, b + s.b};
}

Complex Complex::operator*(Complex &s) const {
    return {a * s.a - b * s.b, a * s.b + b * s.a};
}

double Complex::len() const {
    return a * a + b * b;
}
