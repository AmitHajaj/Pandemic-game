//
// Created by amit on 01/05/2021.
//

#include "GeneSplicer.hpp"
#include "Board.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace pandemic{

    GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city){}

    GeneSplicer::GeneSplicer(GeneSplicer& p) : Player(p){}

    GeneSplicer& GeneSplicer::discover_cure(Color c) {
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()){
            if(_board.get_research_centers().find(_city)->second){
                if(_board.get_cures().find(c) != _board.get_cures().end()){
                    if(_board.get_cures().find(c)->second){
                        return *this;
                    }
                    //check if there are any(!) 5 cards.
                    vector<size_t> indexes;
                    int counter=0;
                    for(size_t i=0; i<_cards.size() && counter<=NUMBER_OF_CARDS_TO_FIND; ++i){
                        counter++;
                        indexes.push_back(i);
                    }
                    if(indexes.size() < NUMBER_OF_CARDS_TO_FIND){
                        throw invalid_argument("Not enough cards to discover.");
                    }
                    int cnt = 0;
                    vector<City>::iterator it;
                    it = _cards.begin();

                    for(size_t i=0; i<indexes.size(); ++i){
                        cout<<indexes.at(i)<<endl;
                    }
                    for(size_t i=0; i<indexes.size(); ++i){
                        _cards[indexes.at(i)] = _cards.back();
                        _cards.pop_back();
                    }
                    _board.set_cure(c);
                    return *this;
                }

                throw exception();

            }
            throw invalid_argument("City doesn't has a research center.");

        }
        throw invalid_argument("City is not in the list.");
    }

    string GeneSplicer::role(){
        return "GeneSplicer";
    }

    GeneSplicer::~GeneSplicer() {
    }

}
