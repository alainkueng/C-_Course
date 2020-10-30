

#ifndef EXERCISE2_PERSISTENCE_TRAITS_H
#define EXERCISE2_PERSISTENCE_TRAITS_H

#include "iostream"

using namespace std;

template<typename T>
struct persistence_traits {
    static void read(ifstream &ifs, T &elem);
    static void write(ofstream &ofs, const T &elem);
};


#endif //EXERCISE2_PERSISTENCE_TRAITS_H
