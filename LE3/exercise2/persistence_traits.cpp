

#include "persistence_traits.h"

template<typename T>
void persistence_traits<T>::read(ifstream &ifs, T &elem) {
        ifs >> elem;
}

template<typename T>
void persistence_traits<T>::write(ofstream &ofs, const T &elem) {
        ofs << elem << endl;
}
