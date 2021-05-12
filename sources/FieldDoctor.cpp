//
// Created by amit on 01/05/2021.
//

#include "FieldDoctor.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city){}

    FieldDoctor::FieldDoctor(FieldDoctor& p) : Player(p){}


    FieldDoctor& FieldDoctor::treat(City c) {
        try{
            if(_board.is_clean()){
                throw invalid_argument("Board is clean.");
            }
            if(_city == c){
                bool flag = _board.get_cures().find(_board.get_colors().find(c)->second)->second;
                if(flag){
                    this->_board.set_level_to_zero(c);
                }
                else{
                    this->_board.decrease_level(c);
                }
                return *this;
            }
            //Check if this city is a neighbor.
            for(size_t i=0;i<this->_board.get_neighbors(_city).size(); i++){
                if(_board.get_neighbors(_city).at(i) == c){
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
            throw invalid_argument("City is not a neighbor.");
        }
        catch (exception e){
            throw exception();
        }
    }

    string FieldDoctor::role(){
        return "FieldDoctor";
    }

    FieldDoctor::~FieldDoctor() {
    }

}
