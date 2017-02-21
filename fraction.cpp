#include "fraction.h"

#include <cstdlib> //using abs
#include <ostream>
using std::ostream;
#include <stdexcept>
using std::runtime_error;
#include <string>
using std::to_string;
using std::string;

#include <iostream>
using std::cout;
using std::endl;

//recursive implementation of euclid's algorithm
long gcd(long a, long b) {
  a = abs(a);
  b = abs(b);
  if(a == 0 || b == 0 || a == b)
    return (a == 0 ? b : a);
  return (a > b ? gcd(a % b, b) : gcd(a, b % a));
}

Fraction::Fraction(long numer, long denom) {
  if(denom == 0)
      throw runtime_error("Divide by zero");
  long ndGCD = gcd(numer, denom);
  n = numer / ndGCD;
  d = denom / ndGCD;
}

Fraction Fraction::operator-(Fraction rhs) const {
  return Fraction(n * rhs.d - rhs.n * d, d * rhs.d);
}
Fraction Fraction::operator*(Fraction rhs) const {
  return Fraction(n * rhs.n, d * rhs.d);
}
Fraction Fraction::operator/(Fraction rhs) const {
  return Fraction(n * rhs.d, rhs.n * d);
}

string Fraction::toString() const {
  return to_string(n) + (d == 1 ? "" : "/" + to_string(d));
}
ostream& operator<<(ostream& out, Fraction rhs) {
  out << rhs.toString();
  return out;
}

