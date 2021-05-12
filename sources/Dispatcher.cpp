//
// Created by amit on 01/05/2021.
//

#include "Dispatcher.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    Dispatcher::Dispatcher(Board& board, City city) : Player(board, city){}

    Dispatcher::Dispatcher(Dispatcher& p) : Player(p){}

    Dispatcher& Dispatcher::fly_direct(City c) {
        if(c == _city){
            throw invalid_argument("Cant fly from city to itself.");
        }
        if(_board.get_research_centers().find(c) != _board.get_research_centers().end()){
            // If there is a research center.
            if(_board.get_research_centers().find(_city)->second){
                this->_city = c;
                return *this;
            }
            // If there isn't a research center, play by everybody rules.
            for(size_t i=0;i<_cards.size(); ++i){
                if(_cards.at(i) == c){
                    _city = c;
                    _cards.erase(_cards.begin()+(long)i);
                    return *this;
                }
            }
            throw invalid_argument("City card dont exist in your hand.");
        }
        throw invalid_argument("City is not in the list.");
    }

    string Dispatcher::role(){
        return "Dispatcher";
    }

    Dispatcher::~Dispatcher() {
    }

}
