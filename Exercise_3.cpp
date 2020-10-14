#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>


std::set<std::string> readFile(const std::string& dict) {
    std::set<std::string> set;
    std::ifstream file;
    file.open(dict);
    if (file.fail()) {

    }
    else {
        std::string word;
        while (std::getline(file, word)) {
            set.insert(word);
        }
    }
    file.close();

    return set;
}

void checker(const std::set<std::string> dict, std::string textName) {
    std::ifstream file(textName);
    std::string word;
    if (file.fail()) {

    }
    else {
        while (file >> word) {
            if (dict.find(word) == dict.end()) {
                std::cout << word << '\n';
            }
        }
    }
}

int main(int argc, char* argv[]) {

    std::string dictionaryName = argv[1];
    std::string textName = argv[2];


    std::set<std::string> dict = readFile(dictionaryName);
    checker(dict, textName);


}