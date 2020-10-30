//
// Created by Janosch Baltensperger on 07.10.20.
//

#ifndef EXERCISE3_FRACTION_H
#define EXERCISE3_FRACTION_H

#include <iostream>
#include <fstream>
#include <numeric>

using namespace std;


class fraction {
private:
    int cntr;
    int denom;

public:
    fraction(int c=0, int d=1) : cntr(c), denom(d) {}
    int get_counter();
    int get_denominator();
    void set_counter(int c);
    void set_denominator(int d);
};

fraction operator*(fraction a, fraction b);
fraction operator/(fraction a, fraction b);
fraction operator-(fraction a, fraction b);
fraction operator+(fraction a, fraction b);
istream &operator>>(istream &is, fraction &f);
ostream &operator<<(ostream &os, fraction f);
void check_char(char ch, istream &is);


#endif //EXERCISE3_FRACTION_H
