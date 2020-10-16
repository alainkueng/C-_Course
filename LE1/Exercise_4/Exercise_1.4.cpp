#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <regex>
#include <sstream>

void print(std::vector <double> const& a) {
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
    std::cout << '\n';
}



int main() {
    std::vector<double> inputs;
    std::regex numberRegex("([0-9]*[.]{0,1}[0-9]*)");
    std::cout << "Welcome to the RNP calculator\n";
    double a, b;
    while (true) {
        std::string command;
        std::cout << "Enter a command(Enter 'q' to terminate): ";
        std::cin >> command;
        if (command == "q") {
            std::cout << "Terminated calculator\n";
            break;

        }
        else if (command[0] == 'n') {
            std::string numbers = command.erase(0, 1);
            if (std::regex_match(numbers, numberRegex)) {
                std::stringstream doublevalue(numbers);
                double number;
                doublevalue >> number;
                inputs.push_back(number);
            }

        }
        else if (command == "d" && inputs.size() >= 1) {
            inputs.pop_back();

        }
        else if (command == "min" && inputs.size() >= 2) {
            b = inputs.back();
            inputs.pop_back();
            a = inputs.back();
            inputs.pop_back();
            if (b <= a) {
                inputs.push_back(b);
            }
            else {
                inputs.push_back(a);
            }

        }
        else if (command == "+" && inputs.size() >= 2) {
            b = inputs.back();
            inputs.pop_back();
            a = inputs.back();
            inputs.pop_back();

            inputs.push_back(a + b);

        }
        else if (command == "-" && inputs.size() >= 2) {
            b = inputs.back();
            inputs.pop_back();
            a = inputs.back();
            inputs.pop_back();

            inputs.push_back(a - b);

        }
        else if (command == "*" && inputs.size() >= 2) {
            b = inputs.back();
            inputs.pop_back();
            a = inputs.back();
            inputs.pop_back();

            inputs.push_back(a * b);

        }
        else if (command == "/" && inputs.size() >= 2) {
            b = inputs.back();
            inputs.pop_back();
            a = inputs.back();
            inputs.pop_back();

            if (b != 0) {
                inputs.push_back(a / b);
            }

        }
        else {
            std::cout << "No valid entry, try again \n";
        }

        print(inputs);
    }


}