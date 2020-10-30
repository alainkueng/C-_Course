//
// Created by Jonas on 22.10.2020.
//

#ifndef EX4_GAMEINTELLIGENCE_H
#define EX4_GAMEINTELLIGENCE_H


#include "vector"
using namespace std;

template<typename F>
struct intel {

private:
    char playerSign;
    int sum_direction(char pS, int hOrg, int wOrg, int hDir, int wDir,  const F &playfield);
    vector<int> possibleStonePosition(const F &playfield);

public:
    intel(char playerS);
    int canWin(const F &field);
    int otherPlayerCanWin(const F &field);
    int maximizeConnectedStones(const F &field);
};


#endif//EX4_GAMEINTELLIGENCE_H
