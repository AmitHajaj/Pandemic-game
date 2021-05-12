//
// Created by amit on 01/05/2021.
//
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Player.hpp"

namespace pandemic{
    Player::Player(Board& b, City c) : _board(b){
        this->_board = b;
        this->_city = c;
    }

    Player::Player(Player& p) : _board(p._board){
        this->_board = p._board;
        this->_cards = p._cards;
        this->_city = p._city;
    }

    City Player::get_city(){
        return this->_city;
    }
    Player& Player::drive(City c){
        if(c == _city){
            throw invalid_argument("Cant drive from city to itself.");
        }
        for(size_t i=0; i < this->_board.get_neighbors(_city).size(); i++){
            if(_board.get_neighbors(_city).at(i) == c){
                _city = c;
                //If this player is a medic.
                if(this->role() == "Medic"){
                    Color co = _board.get_colors().find(c)->second;
                    //If this disease color has a cure treat it.
                    if(_board.get_cures().find(co)->second){
                        _board.set_level_to_zero(c);
                    }
                }
                return *this;
            }
        }
        throw invalid_argument("City is not a neighbor.");
    }

    Player& Player::fly_direct(City c){
        if(c == _city){
            throw invalid_argument("Cant fly from city to itself.");
        }
        for(size_t i=0;i<_cards.size(); i++){
            if(_cards.at(i) == c){
                _city = c;
                _cards.erase(_cards.begin()+(long)i);
                //If this player is a medic.
                if(this->role() == "Medic"){
                    Color co = _board.get_colors().find(c)->second;
                    //If this disease color has a cure treat it.
                    if(_board.get_cures().find(co)->second && _board[c] != 0){
                        _board.set_level_to_zero(c);
                    }
                }
                return *this;
            }
        }
        throw invalid_argument("City card is not in your hand.");
    }

    Player& Player::fly_charter(City c){
        if(c == _city){
            throw invalid_argument("Cant fly from city to itself.");
        }
        for(size_t i=0;i<_cards.size(); i++){
            if(_cards.at(i) == _city){
                _city = c;
                _cards.erase(_cards.begin()+(long)i);
                //If this player is a medic.
                if(this->role() == "Medic"){
                    Color co = _board.get_colors().find(c)->second;
                    //If this disease color has a cure treat it.
                    if(_board.get_cures().find(co)->second){
                        _board.set_level_to_zero(c);
                    }
                }
                return *this;
            }
        }
        throw invalid_argument("Current city card dont exist in your hand.");
    }

    Player& Player::fly_shuttle(City c){
        if(c == _city){
            throw invalid_argument("Cant fly from city to itself.");
        }
        //If there isn't a research station, here or in target city.
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()
           && _board.get_research_centers().find(c) != _board.get_research_centers().end()){
            if(!_board.get_research_centers().find(_city)->second ||
               !_board.get_research_centers().find(c)->second){
                throw invalid_argument("There isn't a research center here or at the destination city");
            }

            _city = c;
            //If this player is a medic.
            if(this->role() == "Medic"){
                Color co = _board.get_colors().find(c)->second;
                //If this disease color has a cure treat it.
                if(_board.get_cures().find(co)->second){
                    _board.set_level_to_zero(c);
                }
            }
            return *this;
        }

        throw invalid_argument("City is not in the list.");

    }

    void Player::build(){
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()){
            if(!_board.get_research_centers().find(_city)->second) {//If there isn't a center.
                //check for this city card.
                for(size_t i=0;i<_cards.size(); i++) {
                    if (_cards.at(i) == _city) {
                        _cards.erase(_cards.begin() + (long) i);
                        _board.add_research_center(_city);
                        return;
                    }
                }
                //if this city card not found throw.
                throw invalid_argument("Current city card dont exist in your hand.");
            }
        }
        else{
            throw invalid_argument("City is not in the list.");
        }
    }

    Player& Player::discover_cure(Color c){
        //If the given city is at the list
        if(_board.get_research_centers().find(_city) != _board.get_research_centers().end()){
            //If there is a research center at this city.
            if(_board.get_research_centers().find(_city)->second){
                if(_board.get_cures().find(c) != _board.get_cures().end()){
                    //If cure is found before.
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
                        throw invalid_argument("Not enough cards to discover.");
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
                throw exception();

            }

            throw invalid_argument("City doesn't has a research center.");

        }

        throw invalid_argument("City is not in the list.");

    }

    Player& Player::treat(City c){
        if(_city != c){
            throw invalid_argument("Not the right card.");
        }
        if(_board.is_clean()){
            throw invalid_argument("Board is clean.");
        }
        if(_board[c] == 0){
            throw invalid_argument("City is clean.");
        }

        //If there is a cure or not yet.
        bool flag = _board.get_cures().find(_board.get_colors().find(c)->second)->second;
        if(flag) {
            this->_board.set_level_to_zero(c);
        }
        else{
            this->_board.decrease_level(c);
        }
        return *this;
    }

    Player& Player::take_card(City c){
        if(_board.get_colors().find(c) != _board.get_colors().end()) {
            //check for this city card.
            for(size_t i=0;i<_cards.size(); i++) {
                //If we already has that card.
                if (_cards.at(i) == c) {
                    return *this;
                }
            }
            //If we dont has that card.
            _cards.push_back(c);
            return *this;
        }

        throw invalid_argument("City is not in the list.");
    }

    string Player::role(){
        return "Player";
    }

    void Player::remove_cards() {
        _cards.clear();
    }

    Player::~Player(){

    }
}
