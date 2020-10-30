#include <iostream>
#include <fstream>
#include <istream>
#include<set>

#include "pset.h"
#include "pset.cpp"
#include "persistence_traits.h"
#include "persistence_traits.cpp"

using namespace std;

/*
Build command:
g++ -std=c++17 main.cpp -o main
run command with input and output file specified:
 ./main "text.txt" "dict.txt"
*/

int main(int argc, char *argv[]) {

    std::ifstream text("../text.txt");

    //pset<string> dictionary (argv[2]);
    pset<string> dictionary("../dict.txt");
    std::ofstream updatedText("../updated.txt");
    string word;

    /* could be extended if wanted*/
    set<string> symbols = {".", ",", "?", "!"};
    string input;

    if (text.is_open()) {
        while (text >> word) {
            /*if last character is a symbol we remove it for special cases like the end of the sentence.
             * word.back returns a pointer to the last char of the string.*/
            string punc;
            if (symbols.count(&word.back()) != 0) {
                auto pos = symbols.find(&word.back());
                string punc = *pos;
                word.pop_back();
            }

            /*check if word is not a symbol and not in dictionary */
            if (symbols.count(word) == 0 && !dictionary.in_set(word)) {
                std::cout << word << " " << "is not in the dictionary, would you like to add it? [Y,N]" << std::endl;
                cin >> input;
                if (input == "Y" or input == "y") {
                    dictionary.insert(word);
                    updatedText << word.append(punc) + " ";
                } else {
                    cout << "Would you like to correct the word? [corrected word, N] " << endl;
                    cin >> input;
                    if (input != "N" and input != "n") {
                        updatedText << input.append(punc) + " ";
                    } else {
                        updatedText << word.append(punc) + " ";
                    }
                }
            } else {
                updatedText << word + " ";
            }
        }
    } else std::cout << "cant open text file" << std::endl;

    text.close();
    updatedText.close();

    return 0;
}
