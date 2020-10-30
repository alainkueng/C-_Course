
#include "pset.h"

template<typename T, typename P>
void pset<T,P>::read_set() {
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
        s.insert(x);
    }
};

template<typename T, typename P>
void pset<T,P>::write_set() {
    ofstream ofs(filename);
    iterator fst = s.begin();
    iterator lst = s.end();
    while(fst!=lst) persister::write(ofs,*fst++);
};

template<typename T, typename P>
void pset<T,P>::insert(T elem) {
    s.insert(elem);
}

template<typename T, typename P>
void pset<T,P>::print_set() {
    iterator fst = s.begin();
    iterator lst = s.end();
    while(fst!=lst) {
        cout << *fst << " ";
        fst++;
    }
    cout << endl;
};