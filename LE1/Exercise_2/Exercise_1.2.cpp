#include <iostream>
#include <numeric>

using namespace std;

class fraction {
private:
    int cntr;
    int denom;

public:
    //constructor (not using short-hand notation)
    fraction(int c = 0, int d = 1) {
        cntr = c;
        denom = d;
    }

    int get_counter() {
        return cntr;
    }

    void set_counter(int c) {
        cntr = c;
    }

    int get_denominator() {
        return denom;
    }

    void set_denominator(int d) {
        denom = d;
    }
};

int gcd(int number1, int number2)
{
    int n1, n2;
    n1 = number1;
    n2 = number2;
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }

    cout << "HCF = " << n1;
    return n1;
}

fraction operator*(fraction a, fraction b) {
    //shorten fraction
    int f1 = gcd(a.get_counter(), b.get_denominator());
    int f2 = gcd(b.get_counter(), a.get_denominator());
    return fraction((a.get_counter() / f1) * (b.get_counter() / f2),
                    (a.get_denominator() / f2) * (b.get_denominator() / f1));
}

fraction operator/(fraction a, fraction b) {
    // using inverse fraction. again invokes operator*
    return a * fraction(b.get_denominator(), b.get_counter());
}

fraction operator+(fraction a, fraction b) {
    int denom = (a.get_denominator() * b.get_denominator()) / gcd(a.get_denominator(), b.get_denominator());
    int cntr1 = denom / a.get_denominator() * a.get_counter();
    int cntr2 = denom / b.get_denominator() * b.get_counter();

    return fraction(cntr1 + cntr2, denom);
}

fraction operator-(fraction a, fraction b) {
    int denom = (a.get_denominator() * b.get_denominator()) / gcd(a.get_denominator(), b.get_denominator());
    int cntr1 = denom / a.get_denominator() * a.get_counter();
    int cntr2 = denom / b.get_denominator() * b.get_counter();

    return fraction(cntr1 - cntr2, denom);
}

void check_char(char ch, istream &is) {
    char c;
    is >> c;
    if (c != ch) {
        is.putback(c);
        is.setstate(ios::badbit);
    }
}

ostream &operator<<(ostream &os, fraction f) {
    os << '(' << f.get_counter() << '/' << f.get_denominator() << ')';
    return os;
}

istream &operator>>(istream &is, fraction &f) {
    fraction g;
    int counter, denom;

    // extract each char from input stream, ensure correct format with check_char
    check_char('(', is);
    is >> counter;
    check_char('/', is);
    is >> denom;
    check_char(')', is);
    g.set_counter(counter);
    g.set_denominator(denom);

    if (is) f = g;

    return is;
}

int main() {
    fraction f1(2, 3);
    fraction f2(1, 3);

    cout << "f1: " << f1 << std::endl;
    cout << "f2: " << f2 << std::endl;

    fraction res1 = f1 * f2;
    cout << "f1 * f2 = " << res1 << endl;

    fraction res2 = f1 - f2;
    cout << "f1 - f2 = " << res2 << endl;

    fraction input1;
    fraction input2;

    cout << "Your first fraction: " << endl;
    cin >> input1;
    cout << input1 << endl;
    cout << "Your second fraction: " << endl;
    cin >> input2;
    cout << input2 << endl;

    cout << "operation (+,-,*,/) ?" << endl;
    string op;
    cin >> op;

    if (op == "*") {
        cout << input1 * input2;
    } else if (op == "/") {
        cout << input1 / input2;
    } else if (op == "-") {
        cout << input1 - input2;
    } else if (op == "+") {
        cout << input1 + input2;
    } else {
        cout << "invalid operation";
    }
    return 0;
}
