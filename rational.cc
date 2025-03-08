#include "utils.h"
#include <string>

class Z_rational { // rational number
    public:
    // x / y
    int x;
    int y;
    void setNumber(int x, int y);
    Z_rational();
    Z_rational(int n);
    Z_rational(int x, int y);

    std::string to_string();
    const char * to_c_str();

    Z_rational abs();
    Z_rational opposite();
    Z_rational reciprocal();
    Z_rational operator-(); // opposite
    Z_rational operator+(Z_rational o);
    Z_rational operator-(Z_rational o);
    Z_rational operator*(Z_rational o);
    Z_rational operator/(Z_rational o);
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

Z_rational::Z_rational() {
    this->setNumber(0, 1);
}

Z_rational::Z_rational(int n) {
    this->setNumber(n, 1);
}

Z_rational::Z_rational(int x, int y) {
    this->setNumber(x, y);
}

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
    return s.c_str();
}


Z_rational Z_rational::abs() {
    Z_rational r;
    r.x = z_abs(this->x);
    r.y = this->y;
    return r;
}
Z_rational Z_rational::opposite() {
    Z_rational r;
    r.setNumber(-(this->x), this->y);
    return r;
}

Z_rational Z_rational::reciprocal() {
    Z_rational r(0);
    if (this->x == 0) {
        return r;
    }
    r.x = this->y;
    r.y = this->x;
    return r;
}

Z_rational Z_rational::operator-() {
    return this->opposite();
}

Z_rational Z_rational::operator+(Z_rational o) {
    Z_rational r;
    int x0 = this->x, y0 = this->y,
        x1 = o.x,     y1 = o.y;
    int y2 = z_lcm(y0, y1);
    int ratio0 = y2 / y0;
    int ratio1 = y2 / y1;
    r.setNumber((x0 * ratio0) + (x1 * ratio1), y2);
    return r;
}

Z_rational Z_rational::operator-(Z_rational o) {
    return this->operator+(o.opposite());
}

Z_rational Z_rational::operator*(Z_rational o) {
    Z_rational r;
    int x0 = this->x, y0 = this->y,
        x1 = o.x,     y1 = o.y;
    r.setNumber(x0 * x1, y0 * y1);
    return r;
}

Z_rational Z_rational::operator/(Z_rational o) {
    return this->operator*(o.reciprocal());
}