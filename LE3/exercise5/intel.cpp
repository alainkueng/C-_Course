//
// Created by Jonas on 22.10.2020.
//

#include "intel.h"
#include "playfield.h"
#include "vector"
#include <iostream>

using namespace std;

template <typename F>
intel<F>::intel(char playerS): playerSign(playerS) {}

//retuns a vector of all possible columns, from left to right
// if column full adds -1 to vector
template <typename F>
vector<int> intel<F>::possibleStonePosition(const F &pf) {
    vector<int> pos;
    for(int x=0; x<pf.width; x++){
        if (pf.stoneat(x, 0) != pf.none){
            pos.push_back(-1);
        }
        else{
            int y=0;
            while(pf.stoneat(x, y+1) == pf.none && y+1 < pf.height) {
                y++;
            }
            pos.push_back(y);
        }
    }
    return pos;
}

template <typename F>
int intel<F>::sum_direction(char pS, int hOrg, int wOrg, int hDir, int wDir, const F &pf) {
    int h = hOrg + hDir;
    int w = wOrg + wDir;
    int sum = 0;

    while (h< pf.height && h>= 0 && w < pf.width && w >= 0){

        if(pS == pf.stoneat(w, h)){
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

//return the column nr where inserting the stone results in winning the game
//-1 if no possible pos to win the game
template <typename F>
int intel<F>::canWin(const F &pf) {
    vector<int> pos = possibleStonePosition(pf);

    int x = 0;
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); ++it, x++) {
        if (*it != -1) {
            if (sum_direction(playerSign, *it, x,  1, 0, pf) >= 3) {
                return x;
            }
                //check horizontal
            else if (sum_direction(playerSign, *it, x,  0, 1, pf) + sum_direction(playerSign, *it,  x,0, -1, pf) >= 3) {
                return x;
            }
                //check to top left and button right
            else if (sum_direction(playerSign, *it,  x, -1, -1, pf) + sum_direction(playerSign,  *it, x,1, 1, pf) >= 3) {
                return x;
            }
                //check to top right and button left
            else if (sum_direction(playerSign,  *it, x, -1, 1, pf) + sum_direction(playerSign,  *it,x, 1, -1, pf) >= 3) {
                return x;
            }
        }
    }
    return -1;
}


//return the column nr where if the enemy inserts the stone results in winning the game
//-1 if no possible pos to win the game
template <typename F>
int intel<F>::otherPlayerCanWin(const F &pf){
    char otherPlayerSign;
    if(playerSign == pf.player1){
        otherPlayerSign = pf.player2;
    }
    else{
        otherPlayerSign = pf.player1;
    }
    vector<int> pos = possibleStonePosition(pf);
    int x = 0;
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); ++it, x++) {
        if (*it != -1) {
            if (sum_direction(otherPlayerSign, *it, x, 1, 0, pf) >= 3) {
                return x;
            }
                //check horizontal
            else if (sum_direction(otherPlayerSign,  *it, x,  0, 1, pf) + sum_direction(otherPlayerSign,  *it, x, 0, -1, pf) >= 3) {
                return x;
            }
                //check to top left and bottom right
            else if (sum_direction(otherPlayerSign, *it,  x,-1, -1, pf) + sum_direction(otherPlayerSign,  *it, x, 1, 1, pf) >= 3) {
                return x;
            }
                //check to top right and bottom left
            else if (sum_direction(otherPlayerSign, *it, x, -1, 1, pf) + sum_direction(otherPlayerSign, *it, x, 1, -1, pf) >= 3) {
                return x;
            }
        }

    }
    return -1;
}


template <typename F>
int intel<F>::maximizeConnectedStones(const F &pf){

    vector<int> pos = possibleStonePosition(pf);
    int max = -1;
    int maxPos;
    int x = 0;
    int sum[4];
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {

        if (*it != -1) {
            sum[0] = sum_direction(playerSign, *it, x, 1, 0, pf);
            sum[1] = sum_direction(playerSign,  *it, x, 0, 1, pf) + sum_direction(playerSign,  *it, x, 0, -1, pf) ;
            sum[2] = sum_direction(playerSign,  *it, x, -1, -1, pf) + sum_direction(playerSign,  *it, x,1, 1, pf);
            sum[3] = sum_direction(playerSign,  *it, x, -1, 1, pf) + sum_direction(playerSign,  *it, x, 1, -1, pf);

            int maxSum = -1;
            for (int i=0; i<4; i++){
                if(sum[i] > maxSum){ maxSum = sum[i];}
            }
            if(maxSum > max){
                max = maxSum;
                maxPos = x;
            }
        }
        x = x+1;
    }
    return maxPos;

}
