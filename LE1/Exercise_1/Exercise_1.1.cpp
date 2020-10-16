#include <iostream>
#include <fstream>

using namespace std;

/* Exercise 1.1
Implement a program that converts Unix style text files to MSDOS
style text files and vice-versa
• Unix uses ‘\n’ as line separators
• MSDOS uses ‘\r’ followed by ‘\n’ as line separators
• How do you deal with incorrectly formatted Unix text files?
 */

/*
g++ main.cpp -o main
./main "input.txt" "output.txt"
*/

int main(int argc, char *argv[]) {
    //argc: number of command line arguments
    cout << "Hello, World!" << endl;

    ifstream ifs(argv[1]); //input file stream
    ofstream ofs(argv[2]); //output file stream
    char c;

    // is_open() => returns whether the stream is currently associated to a file, exits for "corrupt" files
    if (ifs.is_open()) {
        for (;;) {
            //get() extracts characters from the stream
            if (ifs.get(c)) {
                if (c == '\n') {
                    cout << "converting line break.." << endl;
                    ofs << "\r\n";
                } else {
                    ofs << c;
                }
            } else {
                break;
            }
        }
    } else cout << "cant open input file" << endl;

    return 0;
}
