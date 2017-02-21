#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "fraction.h"

#include <ostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

struct Polynomial {
    // data members
    vector<Fraction> coefs;

    // methods
    Polynomial() = default;
    Polynomial(const vector<Fraction>& cfs);
    
    string poly_to_string() const;

    Fraction evaluate(Fraction x) const;

    Polynomial derivative() const;
    Polynomial integral() const;
    Fraction integral(Fraction lower, Fraction upper) const;
};

#endif
