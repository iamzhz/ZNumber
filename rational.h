#ifndef _Z_NUMBER_RATIONAL_H_
#define _Z_NUMBER_RATIONAL_H_

#include <string>

class Z_rational { // rational number
    public:
    // x / y
    int x;
    int y;
    // c string form (update when call .to_c_str())
    char c_str[20];
    // set value
    void setNumber(int x, int y);
    Z_rational operator=(const int & n);
    Z_rational operator=(const Z_rational & o);
    Z_rational();
    Z_rational(int n);
    Z_rational(int x, int y);
    // convert to string
    std::string to_string();
    const char * to_c_str();
    // compute
    Z_rational abs() const;
    Z_rational opposite() const;
    Z_rational reciprocal() const;
    int reduce(Z_rational o, int & x0, int & x1) const;  // reduction of fractions to a common denominator
    Z_rational operator-() const; // opposite
    Z_rational operator+(const Z_rational & o) const;
    Z_rational operator-(const Z_rational o) const;
    Z_rational operator*(const Z_rational o) const;
    Z_rational operator/(const Z_rational o) const;
    // compare
    bool operator==(const Z_rational & o) const;
    bool operator>(const Z_rational & o)  const;
    bool operator>=(const Z_rational & o) const;
    bool operator<(const Z_rational & o)  const;
    bool operator<=(const Z_rational & o) const;
    bool operator!=(const Z_rational & o) const;
};

#endif