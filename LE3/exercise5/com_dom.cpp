//
// Created by Janosch Baltensperger on 30.10.20.
//

using namespace std;

#include "iostream"
template<typename F>
struct com_Dominique {
    char player_id;

    // returns the column where the player decides to insert his
    // stone
    // F is the playfield which may be any playfield implementing
    // the stoneat method, if you expect a different class because
    // you need methods to verify whether the opponent can win,
    // copy the field into the class that you expect.
    int play(const F &field) {
        cout << "Dominiques computer is playing" << endl;
        int oponent_id = player_id == field.player1 ? field.player2 : field.player1;
        int last_valid_col = -1;
        for (int c = 0; c < field.width ; c++ ){
            int r = get_landing_row(field, c);
            if (r < 0) continue;

            last_valid_col = c;

            F sim_field = field;

            sim_field.rep[last_valid_col][r] = player_id;
            if (playerwins(player_id, sim_field)) {
                break;
            }

            sim_field.rep[last_valid_col][r] = oponent_id;
            if (playerwins(oponent_id, sim_field)) {
                break;
            }
        }
        return last_valid_col;
    }

    int get_landing_row(const F &field, int col) {
        for (int r = field.height - 1; r >=0; r--) {
            if (field.stoneat(col, r) == field.none) {
                return r;
            }
        }
        return -1;
    }

    // inspired by https://stackoverflow.com/a/38211417
    static bool playerwins(char player, const F &field) {
        // horizontalCheck
        for (int j = 0; j < field.height-3 ; j++ ){
            for (int i = 0; i < field.width; i++){
                if (field.stoneat(i, j) == player && field.stoneat(i, j+1) == player && field.stoneat(i, j+2) == player && field.stoneat(i, j+3) == player){
                    return true;
                }
            }
        }
        // verticalCheck
        for (int i = 0; i<field.width-3 ; i++ ){
            for (int j = 0; j<field.height; j++){
                if (field.stoneat(i, j) == player && field.stoneat(i+1, j) == player && field.stoneat(i+2, j) == player && field.stoneat(i+3, j) == player){
                    return true;
                }
            }
        }
        // ascendingDiagonalCheck
        for (int i=3; i<field.width; i++){
            for (int j=0; j<field.height-3; j++){
                if (field.stoneat(i, j) == player && field.stoneat(i-1, j+1) == player && field.stoneat(i-2, j+2) == player && field.stoneat(i-3, j+3) == player)
                    return true;
            }
        }

        // descendingDiagonalCheck
        for (int i=3; i<field.width; i++){
            for (int j=3; j<field.height; j++){
                if (field.stoneat(i, j) == player && field.stoneat(i-1, j-1) == player && field.stoneat(i-2, j-2) == player && field.stoneat(i-3, j-3) == player)
                    return true;
            }
        }
        return false;
    }
};