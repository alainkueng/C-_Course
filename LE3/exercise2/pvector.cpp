
#include "pvector.h"

template<typename T, typename P>
void pvector<T,P>::write_vector() {
    ofstream ofs(filename);
    iterator fst = v.begin();
    iterator lst = v.end();
    while(fst!=lst) persister::write(ofs,*fst++);
}

template<typename T, typename P>
void pvector<T,P>::read_vector() {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "invalid file" << endl;
        return;
    }

    //read from ifs until end of file (eof)
    while(true) {
        T x;
        persister::read(ifs,x);
        if(ifs.eof()) {break;}
        v.push_back(x);
    }
}

template<typename T, typename P>
void pvector<T,P>::push_back(const T &el) {
    v.push_back(el);
}

template<typename T, typename P>
void pvector<T,P>::pop_back() {
    v.pop_back();
}

template<typename T, typename P>
T pvector<T,P>::at(int pos) {
    return v.at(pos);
}

template<typename T, typename P>
int pvector<T,P>::size() {
    return v.size();
}

template<typename T, typename P>
void pvector<T,P>::print_vector() {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' ';
    }
    cout << endl;
}


