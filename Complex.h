//
// Created by ash on 16.05.23.
//

#ifndef GRAPHICS_COMPLEX_H
#define GRAPHICS_COMPLEX_H

#include <cmath>

struct Complex {
    double a, b;

    Complex operator+(Complex &s) const;

    Complex operator*(Complex &s) const;

    double len() const;

};


#endif //GRAPHICS_COMPLEX_H
