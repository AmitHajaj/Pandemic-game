//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_MEDIC_H
#define PANDEMIC_A_MEDIC_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic{
    class Medic : public Player{
    public:
        Medic(Board& board, City city);

        Medic(Medic& p);

        /**
         * Decrease to disease level in current city.
         * If a cure for this color has been discovered, we will decrease the disease level to 0.
         * If the city is clean, throw exception.
         */
        Medic& treat(City c);

        string role();

        ~Medic();
    };
}
#endif //PANDEMIC_A_MEDIC_H
