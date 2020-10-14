#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/** 
 * 
 * 
**/
void notInlineFunction(){
    for(int i = 0; i < 3; i++){
        std::cout << "This is a loop and wont be executed inline";
    }
}

int main(){
    notInlineFunction();
}