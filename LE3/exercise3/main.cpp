/*
Upgrade your RPN calculator:
Make sure your RPN calculator runs fine with complex numbers
 - Which challenge(s) did you face? How did you solve them?
 - Note: It is sufficient to use only concepts we had discussed so far in the lecture!
*/

/*
 Challenges:
 - basic operations are implemented for complex numbers!
 - serializer << and dezerializders >> are provided by std:complex<T>
 - You can use that only if you specialize the entire class. You can't specialize just one member function of the class.
 => use further template specialization for mymin function (inline)
 => another way: use inheritance and override mymin function
 */

#include <complex>
#include "pvector.h"
#include "pvector.cpp"
#include "rpn.h"
#include "rpn.cpp"

using namespace std;


int main() {
    pvector<complex<double>> pv1("pv-complex.txt");
    rpn<complex<double>> cc1;

    cc1.read_input(pv1);
    pv1.print_vector();
}
