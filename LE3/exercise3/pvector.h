//
// Created by Janosch Baltensperger on 07.10.20.
//

#ifndef EXERCISE3_PVECTOR_H
#define EXERCISE3_PVECTOR_H

#include <iostream>
#include <fstream>
#include "vector"

using namespace std;

template<typename T>
class pvector {
protected:
    string filename;
    vector<T> v;

public:
    pvector(string fname) : filename(fname) {
        read_vector();
    }

    ~pvector() {
        write_vector();
    }

    void push_back(const T &el);

    void pop_back();

    void read_vector();

    int size();

    T at(int pos);

    void write_vector();

    void print_vector();
};


#endif //EXERCISE3_PVECTOR_H
