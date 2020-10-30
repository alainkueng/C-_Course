//
// Created by Janosch Baltensperger on 09.10.20.
//

#ifndef EXERCISE4_HUMAN_H
#define EXERCISE4_HUMAN_H

#include <iostream>
#include "playfield.h"

using namespace std;

template<typename F>
class human {
public:
    int play(const F &field);
};

#endif //EXERCISE4_HUMAN_H
