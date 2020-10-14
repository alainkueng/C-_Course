#include <iostream>
#include <vector>
#include <string>
#include <sstream>



class Fraction {
    int numerator;
    int denominatior;
public:
    Fraction(int n, int d) { numerator = n; denominatior = d; }
    Fraction() { numerator = 0; denominatior = 1; }

    int getNumerator() { return numerator; }
    int getDenominator() { return denominatior; }

    void setNumerator(int n) { numerator = n; }
    void setDenominator(int d) { denominatior = d; }

    friend Fraction operator+(Fraction a, Fraction b);
    friend Fraction operator-(Fraction a, Fraction b);
    friend Fraction operator*(Fraction a, Fraction b);
    friend Fraction operator/(Fraction a, Fraction b);

    friend std::ostream& operator << (std::ostream& os, Fraction f);
    friend std::istream& operator >> (std::istream& is, Fraction& f);

};

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

Fraction simplify(int a, int b) {
    int s = gcd(a, b);
    return Fraction(a / s, b / s);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

std::ostream& operator << (std::ostream& os, Fraction f) {
    os << f.getNumerator() << '/' << f.getDenominator();
    return os;
}

std::istream& operator >> (std::istream& is, Fraction& f) {
    std::string in;
    int d;
    int n;
    is >> in;
    std::stringstream intValue_N(in[0]);
    intValue_N >> n;
    std::stringstream intValue_D(in[2]);
    intValue_D >> d;
    f.setNumerator(n);
    f.setDenominator(d);
    return is;
}

Fraction operator + (Fraction a, Fraction b) {
    int lcmRes = lcm(a.denominatior, b.denominatior);

    return simplify((a.numerator * (lcmRes / a.denominatior) + (b.numerator) * (lcmRes / b.denominatior)), lcmRes);
}

Fraction operator - (Fraction a, Fraction b) {
    int lcmRes = lcm(a.denominatior, b.denominatior);

    return simplify((a.numerator * (lcmRes / a.denominatior) - (b.numerator) * (lcmRes / b.denominatior)), lcmRes);
}

Fraction operator*(Fraction a, Fraction b) {
    return simplify((a.numerator * b.numerator), (a.denominatior * b.denominatior));
}

Fraction operator/(Fraction a, Fraction b) {
    Fraction inverted_b(b.denominatior, b.numerator);
    if (inverted_b.denominatior != 0) {
        return a * inverted_b;
    }
    return a;
}


int main() {

    Fraction f(1, 3);
    Fraction g(1, 4);
    Fraction h(8, 3);

    Fraction res1 = f + g;

    std::cout << "1/3 + 1/4 is " << res1 << '\n';

    Fraction res2 = h - g;
    std::cout << "8/3 - 1/4 is " << res2 << '\n';

    Fraction res3 = g * f;
    std::cout << "1/4 * 1/3 is " << res3 << '\n';



    Fraction input1;
    Fraction input2;
    std::cout << "Enter first fraction (x/y): ";
    std::cin >> input1;
    std::cout << "Enter second fraction (x/y): ";
    std::cin >> input2;

    std::cout << "The division of these two fractions is " << input1 / input2;

}