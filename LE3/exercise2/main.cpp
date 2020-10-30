#include "pvector.h"
#include "pvector.cpp"
#include "pset.h"
#include "pset.cpp"

using namespace std;

int main() {
    pvector<double> pv1("pv-double.txt");
    pv1.print_vector();
    pv1.push_back(2.1);
    pv1.print_vector();

    pset<int> ps1("ps-int.txt");
    ps1.print_set();
    ps1.insert(8);
    ps1.print_set();
}
