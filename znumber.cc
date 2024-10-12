#include <iostream>
#include <string>

class ZRationalNumber {
    private:
        long i0, i1; // i0 / i1

        std::string integer_to_string(long i) {
            std::string ret;
            int last;
            do {
                last = i % 10;
                ret = (char)(last + '0') + ret;
                i -= last;
                i /= 10;
            } while (i != 0);
            return ret;
        }
        long gcd(long a, long b) {
            long temp;
            while (b != 0) {
                temp = a;
                a = b;
                b = temp % b;
            }
            return a;
        }
        long lcm(long a, long b) {
            return a / this->gcd(a, b) * b;
        }
        void fraction_reduce() {
            long g = gcd(this->i0, this->i1);
            this->i0 /= g;
            this->i1 /= g;
        }
    public:
        ZRationalNumber(long i0) {
            this->i0 = i0;
            this->i1 = 1;
        }
        ZRationalNumber(long i0, long i1) {
            if (i1 == 0) std::cerr << "Dividend cannot be 0!\n";
            this->i0 = i0;
            this->i1 = i1;
            this->fraction_reduce();
        }
        std::string to_string() {
            if (this->i1 == 1) {
                return this->integer_to_string(this->i0);
            }
            // is fraction
            return this->integer_to_string(this->i0) + "/" + this->integer_to_string(this->i1);
        }
        /*ZRationalNumber operator+(ZRationalNumber & a) {
            int i0, i1;
            i1 = this->lcm(this->i1, a.i1);
            i0 = (i1 / this->i1) * this->i0  +  (i1 / a.i1) * a.i0;
            ZRationalNumber ret(i0, i1);
            return ret;
        }*/
};

int main(void) {
    while (1) {
    long i, j;
    std::cin >> i >> j;
    ZRationalNumber zrn(i, j);
    std::cout << zrn.to_string() << std::endl;
    }
    return 0;
}