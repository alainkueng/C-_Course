//
// Created by Janosch Baltensperger on 30.10.20.
//

#ifndef EX4_CPLAYER_H
#define EX4_CPLAYER_H
#include "intel.h"

template<typename F>
struct computer{

    intel<F> gameI;
    // returns the column where the human decides to insert his
    // stone
    // F is the playfield which may be any playfield implementing
    // the stoneat method, if you expect a different class because
    // you need methods to verify whether the opponent can win,
    // copy the field into the class that you expect.
public:
    computer(intel<F> intel);
    int play(const F &field);
};




#endif//EX4_CPLAYER_H
