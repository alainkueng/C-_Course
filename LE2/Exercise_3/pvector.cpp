#include "pvector.h"

template<typename T>
void pvector<T>::push_back(const T &el) {
    v.push_back(el);
}

template<typename T>
void pvector<T>::pop_back() {
    v.pop_back();
}

template<typename T>
T pvector<T>::at(int pos) {
    return v.at(pos);
}

template<typename T>
int pvector<T>::size() {
    return v.size();
}

template<typename T>
void pvector<T>::write_vector() {
    ofstream ofs(filename);
    for (const T &elem : v) {
        ofs << elem << endl;
    }
}

template<typename T>
void pvector<T>::print_vector() {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' ';
    }
    cout << endl;
}

template<typename T>
void pvector<T>::read_vector() {
    ifstream ifs(filename);

    if (!ifs.is_open()) {
        cout << "invalid file" << endl;
        return;
    }

    for (;;) {
        T x;
        ifs >> x;
        if (!ifs.good()) {
            break;
        } else {
            v.push_back(x);
        }
    }
}