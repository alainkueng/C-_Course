//
// Created by Janosch Baltensperger on 23.10.20.
//

#ifndef EXERCISE2_PSET_H
#define EXERCISE2_PSET_H

#include <iostream>
#include <fstream>
#include "set"
#include "persistence_traits.h"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pset {
private:
    string filename;
    set<T> s;
    typedef P persister;
    typedef typename set<T>::iterator iterator;

public:
    pset() {};

    pset(string fname) : filename(fname) {
        read_set();
    }

    ~pset() {
        write_set();
    }

    void read_set();

    void write_set();

    void insert(T elem);

    void print_set();

    bool in_set(T elem);

    void add_filename(string fname) {
        filename = fname;
    }
};


#endif //EXERCISE2_PSET_H
