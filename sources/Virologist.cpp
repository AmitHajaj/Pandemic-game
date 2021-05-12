//
// Created by amit on 01/05/2021.
//

#include "Virologist.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    Virologist::Virologist(Board& board, City city) : Player(board, city){}

    Virologist::Virologist(Virologist& p) : Player(p){}

    Virologist& Virologist::treat(City c) {
        if(_board.is_clean()){
            throw exception();
        }

        for(size_t i=0;i<_cards.size(); i++){
            if(_cards.at(i) == c){
                //throw card
                _cards.erase(_cards.begin() + (int)i);
                bool flag = _board.get_cures().find(_board.get_colors().find(c)->second)->second;
                if(flag){
                    this->_board.set_level_to_zero(c);
                }
                else{
                    this->_board.decrease_level(c);
                }
                return *this;

            }
        }
        if(_city != c){
            throw exception();
        }
        if(_board.is_clean()){
            throw invalid_argument("Board is clean.");
        }

        bool flag = _board.get_cures().find(_board.get_colors().find(c)->second)->second;
        if(flag){
            this->_board.set_level_to_zero(c);
        }
        else{
            this->_board.decrease_level(c);
        }
        return *this;
    }

    string Virologist::role(){
        return "Virologist";
    }

    Virologist::~Virologist() {
    }

}
