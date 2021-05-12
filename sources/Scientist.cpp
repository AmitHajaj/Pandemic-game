//
// Created by amit on 01/05/2021.
//

#include "Scientist.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    Scientist::Scientist(Scientist& p) : Player(p){
        this->_num_of_cards_to_find_cure = p._num_of_cards_to_find_cure;
    }

    Scientist::Scientist(Board& board, City city, int n): Player(board, city){
        this->_num_of_cards_to_find_cure = n;
    }

    Scientist& Scientist::discover_cure(Color c) {
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()){
            //If there is a research center here.
            if(_board.get_research_centers().find(_city)->second){
                if(_board.get_cures().find(c) != _board.get_cures().end()){
                    //If there is already a cure;
                    if(_board.get_cures().find(c)->second){
                        return *this;
                    }
                    if(_num_of_cards_to_find_cure == 0){
                        _board.set_cure(c);
                    }
                    //check n cards
                    vector<size_t> indexes;
                    int counter=0;
                    for(size_t i=0; i<_cards.size() && counter<= this->_num_of_cards_to_find_cure; ++i){
                        if(_board.get_colors()[_cards.at(i)] == c){
                            counter++;
                            indexes.push_back(i);
                        }
                    }
                    if(indexes.size() < this->_num_of_cards_to_find_cure){
                        throw invalid_argument("Not enough cards to discover");
                    }

                    int cnt = 0;
                    vector<City>::iterator it;
                    it = _cards.begin();

                    for(size_t i=0; i<indexes.size(); ++i){
                        _cards[indexes.at(i)] = _cards.back();
                        _cards.pop_back();
                    }
                    _board.set_cure(c);
                    return *this;
                }

                throw invalid_argument("No such disease color.");
            }

            throw invalid_argument("No research center");
        }
            throw invalid_argument("City not exist");

    }


    string Scientist::role(){
        return "Scientist";
    }

    Scientist::~Scientist() {
    }

}