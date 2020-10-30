#include "human.h"
#include "playfield.h"
#include <iostream>
#include "human.cpp"
#include "computer.h"
#include "computer.cpp"
#include "intel.h"
#include "intel.cpp"
#include "com_dom.cpp"


using namespace std;

void print_playfield(playfield &pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            cout << pf.stoneat(w, h) << " ";
        }
        cout << endl;
    }
}

int sum_direction(int hOrg, int wOrg, int hDir, int wDir,  playfield &pf){
    int h = hOrg + hDir;
    int w = wOrg + wDir;
    int sum = 0;

    while (h< pf.height && h>= 0 && w < pf.width && w >= 0){

        if(pf.stoneat(wOrg, hOrg) == pf.stoneat(w, h)){
            sum = sum +1;
            h = h + hDir;
            w = w + wDir;
        }
        else{
            break;
        }
    }
    return sum;
}

bool boardFull(playfield &pf){
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            if (pf.stoneat(w,h) == pf.none){
                return false;
            }}}
    return true;
}

bool game_finished(int hOrg, int wOrg, playfield &pf){

    int h = hOrg;
    int w = wOrg;
    //check vertical
    if(sum_direction(h, w, 1, 0,  pf) >=3){
        return true;
    }
        //check horizontal
    else if(sum_direction(h, w, 0, 1,  pf) + sum_direction(h, w, 0, -1,  pf) >= 3){
        return true;
    }
        //check to top left and button right
    else if(sum_direction(h, w, -1, -1,  pf) + sum_direction(h, w, 1, 1,  pf) >= 3){
        return true;
    }
        //check to top right and button left
    else if(sum_direction(h, w, -1, 1,  pf) + sum_direction(h, w, 1, -1,  pf) >= 3){
        return true;
    }
    else{
        return false;
    }

}

int insert_stone(playfield &pf, int w, int playerNr) {
    if (pf.stoneat(w, 0) != pf.none){
        cout << "this column is already full pick a different one" << endl;
        return -1;}
    int h = 0;
    while(pf.stoneat(w, h+1) == pf.none && h+1 < playfield::height) {
        h++;
    }
    if (playerNr == 1){pf.rep[w][h] = pf.player1;}
    else {pf.rep[w][h] = pf.player2;}

    return h;

}

int main() {

    playfield pf;


    //human<playfield> player1;

    //my computer player
    intel<playfield> gI (pf.player1);
    computer<playfield> player1(gI);
    com_Dominique<playfield> player2 = {2};

    for (int h = 0; h < playfield::height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[w][h] = pf.none;}
    }

    print_playfield(pf);
    int turn = 0;
    for(;;) {
        int w;
        int h = -1;
        while (h < 0){
            if (turn == 0){
                w = player1.play(pf);
            }
            else{
                w = player2.play(pf);

            }
            h = insert_stone(pf, w, turn+1);
        }
        print_playfield(pf);
        if (game_finished(h, w,pf)){
            cout << "Game Finished player" << " "<< turn + 1 << " " << "won" << endl;
            break;
        }
        if (boardFull(pf)){
            cout << "Draw because board is full" << endl;
            break;
        }
        turn = (turn +1) % 2;
    }

    return 0;
}