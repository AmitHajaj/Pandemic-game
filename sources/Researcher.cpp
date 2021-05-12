//
// Created by amit on 01/05/2021.
//
#include "Researcher.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pandemic{

    Researcher::Researcher(Board& board, City city) : Player(board, city){}

    Researcher::Researcher(Researcher& p) : Player(p){}

    Researcher& Researcher::discover_cure(Color c) {
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()){
                if(_board.get_cures().find(c) != _board.get_cures().end()){
                    //If there is a cure already.
                    if(_board.get_cures().find(c)->second){
                        return *this;
                    }
                    //check 5 cards
                    vector<size_t> indexes;
                    int counter=0;
                    for(size_t i=0; i<_cards.size() && counter<=NUMBER_OF_CARDS_TO_FIND; ++i){
                        if(_board.get_colors()[_cards.at(i)] == c){
                            counter++;
                            indexes.push_back(i);
                        }
                    }
                    if(indexes.size() < NUMBER_OF_CARDS_TO_FIND){
                        throw invalid_argument("Not enough cards to discover cure.");
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

                throw invalid_argument("Not such disease.");
        }

        throw invalid_argument("City is not in the list.");

    }


    string Researcher::role(){
        return "Researcher";
    }

    Researcher::~Researcher() {
    }
}
