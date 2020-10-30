//
// Created by Janosch Baltensperger on 30.10.20.
//

#include "computer.h"
#include "intel.h"
#include <iostream>

using namespace std;

template <typename F>
computer<F>::computer(intel<F> intel): gameI(intel){}


template <typename F>
int computer<F>::play(const F &pf){
    cout << "My computer player plays" << endl;
    //if possible win the game
    int c = gameI.canWin(pf);
    if(c != -1){
        return c;
    }
    //try to keep the enemy from winning, by placing a stone at the pos where he could win
    //only possible if enemy doesnt have 2 pos where he can win, but then we should still take im 1 option
    c = gameI.otherPlayerCanWin(pf);
    if(c != -1){
        return c;
    }

    //else place the stone such that it forms the max nr of connected stones
    return gameI.maximizeConnectedStones(pf);
}