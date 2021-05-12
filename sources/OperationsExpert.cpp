//
// Created by amit on 01/05/2021.
//

#include "OperationsExpert.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city){}

    OperationsExpert::OperationsExpert(OperationsExpert& p) : Player(p){}

    void OperationsExpert::build(){
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()){
            if(!_board.get_research_centers().find(_city)->second) {//If there isnt a center
                _board.add_research_center(this->_city);
                return;
            }
        }
        else{
            throw invalid_argument("City is not in the list.");
        }
    }


    string OperationsExpert::role(){
        return "OperationsExpert";
    }

    OperationsExpert::~OperationsExpert() {
    }

}
