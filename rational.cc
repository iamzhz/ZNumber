#include "utils.h"
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


void Z_rational::setNumber(int x, int y) {
    int ratio = z_gcd(x, y);
    x /= ratio;
    y /= ratio;
    this->x = z_abs(x);
    this->y = z_abs(y);
    if (x * y < 0) { // (+, -) or (-, +)
        this->x = (-z_abs(x));
    }
}

Z_rational Z_rational::operator=(const int & n) {
    this->setNumber(n, 1);
    return *this;
}
Z_rational Z_rational::operator=(const Z_rational & o) {
    this->setNumber(o.x, o.y); 
    return *this;
}

Z_rational::Z_rational() { this->setNumber(0, 1); }
Z_rational::Z_rational(int n) { this->setNumber(n, 1); }
Z_rational::Z_rational(int x, int y) { this->setNumber(x, y); }

std::string Z_rational::to_string() {
    std::string s = std::to_string(this->x);
    if (this->y != 1) {
        s += "/";
        s += std::to_string(this->y);
    }
    return s;
}
const char * Z_rational::to_c_str() {
    std::string s = this->to_string();
    // generate c string and copy to `this->c_str`
    const char * P = s.c_str();
    char * Q = this->c_str;
    while (*P) {
        *Q = *P;
        P ++;
        Q ++;
    }
    *Q = '\0';
    return this->c_str;
}


Z_rational Z_rational::abs() const {
    Z_rational r;
    r.x = z_abs(this->x);
    r.y = this->y;
    return r;
}
Z_rational Z_rational::opposite() const {
    Z_rational r;
    r.setNumber(-(this->x), this->y);
    return r;
}

Z_rational Z_rational::reciprocal() const {
    Z_rational r(0);
    if (this->x == 0) {
        return r;
    }
    r.x = this->y;
    r.y = this->x;
    return r;
}

Z_rational Z_rational::operator-() const {
    return this->opposite();
}

Z_rational Z_rational::operator+(const Z_rational & o) const{
    Z_rational r;
    int x0, x1;
    int deno;
    deno = this->reduce(o, x0, x1);
    r.setNumber(x0 + x1, deno);
    return r;
}

Z_rational Z_rational::operator-(const Z_rational o) const {
    return this->operator+(o.opposite());
}

Z_rational Z_rational::operator*(const Z_rational o) const {
    Z_rational r;
    int x0 = this->x, y0 = this->y,
        x1 = o.x,     y1 = o.y;
    r.setNumber(x0 * x1, y0 * y1);
    return r;
}

Z_rational Z_rational::operator/(const Z_rational o) const {
    return this->operator*(o.reciprocal());
}




int Z_rational::reduce(Z_rational o, int & x0, int & x1) const {
    int deno = z_lcm(this->y, o.y); // `deno` means denominator
    int ratio0 = deno / this->y;
    int ratio1 = deno / o.y    ;
    x0 = (this->x) * ratio0;
    x1 = (o.x)     * ratio1;
    return deno;
}

#define Z_RADITIONAL_OPERATOR_COMPARE(op) \
bool Z_rational::operator op(const Z_rational & o) const { \
        int x0, x1; \
        this->reduce(o, x0, x1); \
        return x0 op x1; \
}
Z_RADITIONAL_OPERATOR_COMPARE(==);
Z_RADITIONAL_OPERATOR_COMPARE(>);
Z_RADITIONAL_OPERATOR_COMPARE(>=);
Z_RADITIONAL_OPERATOR_COMPARE(<);
Z_RADITIONAL_OPERATOR_COMPARE(<=);
Z_RADITIONAL_OPERATOR_COMPARE(!=);