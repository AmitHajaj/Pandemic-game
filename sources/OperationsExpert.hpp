//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_OPERATIONEXPERT_H
#define PANDEMIC_A_OPERATIONEXPERT_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace std;
namespace pandemic{
    class OperationsExpert : public Player{
    public:
        OperationsExpert(Board& board, City city);

        OperationsExpert(OperationsExpert& p);

        /**
         * Build a research-center in current city. To do so, player must throw the current city caard
         * and current city cant have a research-center already.
         */
        void build();


        string role();

        ~OperationsExpert();
    };
}
#endif //PANDEMIC_A_OPERATIONEXPERT_H
