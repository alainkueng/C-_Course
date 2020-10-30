//
// Created by Janosch Baltensperger on 07.10.20.
//

#ifndef EXERCISE3_RPN_H
#define EXERCISE3_RPN_H


#include <iostream>
#include <fstream>
#include "pvector.h"
#include <map>
#include <complex>

using namespace std;

template<typename T>
class rpn {
private:
    bool has_valid_size(pvector<T> &pv);
    string input_line;

public:
    void read_input(pvector<T> &pv);

    void mymin(pvector<T> &pv);

    void add(pvector<T> &pv);

    void subtract(pvector<T> &pv);

    void multiply(pvector<T> &pv);

    void divide(pvector<T> &pv);
};

/*template<typename C>
class rpn<complex<C>> {
private:
    bool has_valid_size(pvector<complex<C>> &pv);

public:
    void mymin(pvector<complex<C>> &pv);

    void add(pvector<complex<C>> &pv);

    void subtract(pvector<complex<C>> &pv);

    void mult(pvector<complex<C>> &pv);

    void divide(pvector<complex<C>> &pv);
};*/

#endif //EXERCISE3_RPN_H
