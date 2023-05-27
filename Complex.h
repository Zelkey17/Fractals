//
// Created by ash on 16.05.23.
//

#ifndef GRAPHICS_COMPLEX_H
#define GRAPHICS_COMPLEX_H

#include <cmath>

struct Complex {
    double a, b;

    Complex operator+(Complex &s) const {
        return {a + s.a, b + s.b};
    }

    Complex operator*(Complex &s) const {
        return {a * s.a - b * s.b, a * s.b + b * s.a};
    }

    double len() const {
        return a * a + b * b;
    }

};


#endif //GRAPHICS_COMPLEX_H
