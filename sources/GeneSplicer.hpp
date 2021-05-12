//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_GENESPLICER_H
#define PANDEMIC_A_GENESPLICER_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic{
    class GeneSplicer : public Player{
    public:
        GeneSplicer(Board& board, City city);

        GeneSplicer(GeneSplicer& p);

        /**
         * Find a cure to a certain color of disease.
         * To do so, player must be in a research-center city
         * and throw 5 cards with the disease color.
         * If cure has been discovered already, action can still be performed.
         */
        GeneSplicer& discover_cure(Color c);


        string role();

        ~GeneSplicer();
    };
}
#endif //PANDEMIC_A_GENESPLICER_H
