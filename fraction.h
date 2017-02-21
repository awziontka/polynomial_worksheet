#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using std::ostream;
#include <string>
using std::string;

class Fraction {
  long n, d;

  public:

    //constructors
    Fraction() : n(0), d(1) {}
    Fraction(long val) : n(val), d(1) {}
    Fraction(const Fraction& rhs) { *this = rhs; } //use the default operator=
    Fraction(long num, long denom);

    //arithmetic comparison operators
    bool operator==(Fraction rhs) const { return (*this - rhs).n == 0; }
    bool operator!=(Fraction rhs) const { return !(*this == rhs); }
    bool operator<(Fraction rhs) const { return (*this - rhs).n < 0; }
    bool operator<=(Fraction rhs) const { return *this == rhs || *this < rhs; }
    bool operator>(Fraction rhs) const { return !(*this <= rhs); }
    bool operator>=(Fraction rhs) const { return !(*this < rhs); }
    
    //comparison operators when the first term is a long
    //these use the comparison operators above and (implicitly) the long constructor
    friend bool operator==(long lhs, Fraction rhs) { return rhs == lhs; } 
    friend bool operator!=(long lhs, Fraction rhs) { return rhs != lhs; }
    friend bool operator<(long lhs, Fraction rhs) { return rhs >= lhs; }
    friend bool operator<=(long lhs, Fraction rhs) { return rhs > lhs; }
    friend bool operator>(long lhs, Fraction rhs) { return rhs <= lhs; }
    friend bool operator>=(long lhs, Fraction rhs) { return rhs < lhs; }

    //basic arithmetic operators
    Fraction operator+(Fraction rhs) const { return *this - -rhs; }
    Fraction operator-(Fraction rhs) const;
    Fraction operator*(Fraction rhs) const;
    Fraction operator/(Fraction rhs) const;

    //arithmetic operations when the lead term is a long
    //these use the arithmetic operators above and (implicitly) the long constructor
    friend Fraction operator+(long lhs, Fraction rhs) { return rhs + lhs; }
    friend Fraction operator-(long lhs, Fraction rhs) { return Fraction(lhs) - rhs; }
    friend Fraction operator*(long lhs, Fraction rhs) { return rhs * lhs; }
    friend Fraction operator/(long lhs, Fraction rhs) { return Fraction(lhs) / rhs; }
   
    //compound assignment operators
    Fraction operator+=(Fraction rhs) { return *this = *this + rhs; }
    Fraction operator-=(Fraction rhs) { return *this = *this - rhs; }
    Fraction operator*=(Fraction rhs) { return *this = *this * rhs; }
    Fraction operator/=(Fraction rhs) { return *this = *this / rhs; }
   
    //utilities relating to negatives
    Fraction operator-() const { return 0 - *this; }
    friend Fraction abs(Fraction f) { return (f < 0 ? -f : f); }

    //printing and string conversion utilities
    string toString() const;
    friend ostream& operator<<(ostream& out, Fraction rhs);
};

#endif

