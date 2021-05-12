//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_FIELDDOCTOR_H
#define PANDEMIC_A_FIELDDOCTOR_H
#include "Player.hpp"
using namespace std;
namespace pandemic{
    class FieldDoctor : public Player{
    public:
        FieldDoctor(Board& board, City city);

        FieldDoctor(FieldDoctor& p);

        /**
         * Decrease to disease level in current city.
         * If a cure for this color has been discovered, we will decrease the disease level to 0.
         * If the city is clean, throw exception.
         */
        FieldDoctor& treat(City c);

        string role();

        ~FieldDoctor();
    };
}
#endif //PANDEMIC_A_FIELDDOCTOR_H
