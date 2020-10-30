

#ifndef EXERCISE3_PVECTOR_H
#define EXERCISE3_PVECTOR_H

#include <iostream>
#include <fstream>
#include "vector"
#include "persistence_traits.h"
#include "persistence_traits.cpp"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pvector {
private:
    string filename;
    vector<T> v;
    typedef P persister;
    typedef typename vector<T>::iterator iterator;

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


