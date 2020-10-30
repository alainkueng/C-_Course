//
// Created by Janosch Baltensperger on 09.10.20.
//

#include "rpn.h"

template<typename T>
void rpn<T>::read_input(pvector<T> &pv) {
    char op;
    while (cin.good() && op != 'q') {
        T number;
        cout << "command: ";
        getline(cin, input_line);
        istringstream iss(input_line);
        while (iss.good() && iss >> op) {
            switch (op) {
                case 'n':
                    iss >> number;
                    pv.push_back(number);
                    continue;
                case 'd':
                    if (pv.size() > 0) { pv.pop_back(); }
                    else { cout << "cannot delete"; }
                    continue;
                case 'q':
                    break;
                case '+':
                    add(pv);
                    continue;
                case '-':
                    subtract(pv);
                    continue;
                case '*':
                    multiply(pv);
                    continue;
                case '/':
                    divide(pv);
                    continue;
                case 'm':
                    mymin(pv);
                    continue;
                default:
                    cout << "invalid input" << endl;
                    break;
            }
        }
        pv.print_vector();
    }
}

template<typename T>
bool rpn<T>::has_valid_size(pvector<T> &pv) {
    if (pv.size() < 2) {
        cout << "invalid operation" << endl;
        return false;
    } else {
        return true;
    }
}

template<typename T>
void rpn<T>::mymin(pvector<T> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        T min_val = std::min(pv.at(pv.size() - 2), pv.at(pv.size() - 1));
        pv.pop_back();
        pv.pop_back();
        pv.push_back(min_val);
        return;
    }
}

//compiler cannot know at run-time, what mymin on complex type might have to be used
//thus specialization on member function needs to be inlined
//A function is an end-product that can be readily compiled into target code, so compilers hate to see potentially conflicting definitions

template<>
inline
void rpn<complex<int>>::mymin(pvector<complex<int>> &pv) {
    cout << "no order on complex numbers" << endl;
    return;
}

template<>
inline
void rpn<complex<double>>::mymin(pvector<complex<double>> &pv) {
    cout << "no order on complex numbers" << endl;
    return;
}

template<>
inline
void rpn<complex<float>>::mymin(pvector<complex<float>> &pv) {
    cout << "no order on complex numbers" << endl;
    return;
}

template<>
inline
void rpn<complex<long double>>::mymin(pvector<complex<long double>> &pv) {
    cout << "no order on complex numbers" << endl;
    return;
}

template<typename T>
void rpn<T>::add(pvector<T> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        T res = pv.at(pv.size() - 2) + pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
    }
}

template<typename T>
void rpn<T>::subtract(pvector<T> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        T res = pv.at(pv.size() - 2) - pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
        return;
    }
}

template<typename T>
void rpn<T>::multiply(pvector<T> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        T res = pv.at(pv.size() - 2) * pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
        return;
    }
}

template<typename T>
void rpn<T>::divide(pvector<T> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        T res = pv.at(pv.size() - 2) / pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
        return;
    }
}



/*template<typename C>
bool rpn<complex<C>>::has_valid_size(pvector<complex<C>> &pv) {
    if (pv.size() < 2) {
        cout << "invalid operation" << endl;
        return false;
    } else {
        return true;
    }
}

template<typename C>
void rpn<complex<C>>::mymin(pvector<complex<C>> &pv) {
    cout << "no order on complex numbers" << endl;
}

template<typename C>
void rpn<complex<C>>::add(pvector<complex<C>> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        complex<C> res = pv.at(pv.size() - 2) + pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
    }
}

template<typename C>
void rpn<complex<C>>::subtract(pvector<complex<C>> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        complex<C> res = pv.at(pv.size() - 2) - pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
        return;
    }
}

template<typename C>
void rpn<complex<C>>::mult(pvector<complex<C>> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        complex<C> res = pv.at(pv.size() - 2) * pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
        return;
    }
}

template<typename C>
void rpn<complex<C>>::divide(pvector<complex<C>> &pv) {
    if (!has_valid_size(pv)) {
        return;
    } else {
        complex<C> res = pv.at(pv.size() - 2) / pv.at(pv.size() - 1);
        pv.pop_back();
        pv.pop_back();
        pv.push_back(res);
        return;
    }
}*/

