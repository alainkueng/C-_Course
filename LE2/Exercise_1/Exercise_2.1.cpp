#include <iostream>
#include <fstream>
#include "vector"

using namespace std;

/*
- Implement the persistent vector data type.
    - Experiment with the persistent vector and use it in combination with different data types.
        What do you observe?
        --> the template tries to convert the data type, e.g. char to int not possible, floats to int get rounded
        Why do you observe that behavior?
        --> might convert to possible type, if not possible, omitted
        How can it be changed?
        -->
*/

template<typename T>
class pvector {
    string filename;
    vector<T> v;

public:
    pvector(string fname) : filename(fname) {
        readvector();
    }

    ~pvector() { writevector(); }

    void push_back(const T &el) {
        v.push_back(el);
        print_vector();
    }

    void pop_back() {
        v.pop_back();
        print_vector();
    }

    void readvector() {
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
        print_vector();
    }

    void writevector() {
        ofstream ofs(filename);
        for (const T &elem : v) {
            ofs << elem << endl;
        }
    }

    void print_vector() {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v.at(i) << ' ';
        }
        cout << endl;
    }
};

int main(int argc, char *argv[]) {
    pvector<int> pv1("pvector-int.txt");
    pvector<char> pv2("pvector-char.txt");

    pv1.push_back(6);
    pv2.push_back('f');

    return 0;
}