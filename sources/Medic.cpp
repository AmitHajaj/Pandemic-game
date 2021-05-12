//
// Created by amit on 01/05/2021.
//

#include "Medic.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    Medic::Medic(Board& board, City city) : Player(board, city){}

    Medic::Medic(Medic& p) : Player(p){}

    Medic& Medic::treat(City c) {
        if(_city != c){
            throw invalid_argument("Not the right card.");
        }
        if(_board.is_clean()){
            throw invalid_argument("Board is clean.");
        }

        if(this->_board[c] == 0){
            throw invalid_argument("City is clean.");
        }
        this->_board.set_level_to_zero(c);
        return *this;
    }

    string Medic::role(){
        return "Medic";
    }

    Medic::~Medic() {
    }
}
