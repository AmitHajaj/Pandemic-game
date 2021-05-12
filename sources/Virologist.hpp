//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_VIROLOGIST_H
#define PANDEMIC_A_VIROLOGIST_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic{
    class Virologist : public Player{
    public:
        Virologist(Board& board, City city);

        Virologist(Virologist& p);

        /**
         * Decrease to disease level in current city.
         * If a cure for this color has been discovered, we will decrease the disease level to 0.
         * If the city is clean, throw exception.
         */
        Virologist& treat(City c);

        string role();

        ~Virologist();
    };
}
#endif //PANDEMIC_A_VIROLOGIST_H
