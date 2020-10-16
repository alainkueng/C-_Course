
#include "rpn.h"

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
void rpn<T>::mult(pvector<T> &pv) {
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