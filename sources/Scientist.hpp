//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_SCIENTIST_H
#define PANDEMIC_A_SCIENTIST_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace std;
namespace pandemic{
    class Scientist : public Player{
    private:
        int _num_of_cards_to_find_cure;
    public:

        Scientist(Board& board, City city, int n);

        Scientist(Scientist& p);

        /**
         * Find a cure to a certain color of disease.
         * To do so, player must be in a research-center city
         * and throw 5 cards with the disease color.
         * If cure has been discovered already, action can still be performed.
         */
        Scientist& discover_cure(Color c);


        string role();

        ~Scientist();
    };
}
#endif //PANDEMIC_A_SCIENTIST_H
