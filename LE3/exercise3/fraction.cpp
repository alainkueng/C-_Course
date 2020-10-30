//
// Created by Janosch Baltensperger on 07.10.20.
//

#include "fraction.h"

int fraction::get_counter() { return cntr; }

void fraction::set_counter(int c) { cntr = c; }

int fraction::get_denominator() { return denom; }

void fraction::set_denominator(int d) { denom = d; }

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
