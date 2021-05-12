//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_PLAYER_H
#define PANDEMIC_A_PLAYER_H
#include <vector>
#include "Board.hpp"
#define NUMBER_OF_CARDS_TO_FIND 5
using namespace std;

namespace pandemic {
    class Player {
    protected:
        Board& _board;
        City _city;
        vector<City> _cards;
    public:
        Player();

        /**
         * Constructor
         */
        Player(Board& b, City c);

        Player(Player& p);

        virtual City get_city();
        /**
         * Move from current city to adjacent city.
         */
        virtual Player& drive(City c);

        /**
         * Fly from current city to a city, only if the player hold this city's card in you hand,
         * and player must throw this destination city's card.
         */
        virtual Player& fly_direct(City c);

        /**
         * Fly from current city to a city. player must throw current city's card.
         */
        virtual Player& fly_charter(City c);

        /**
        * Fly from current city to a city. Only if current city has research-center and
         * if the destination city has research-center.
        */
        virtual Player& fly_shuttle(City c);

        /**
         * Build a research-center in current city. To do so, player must throw the current city caard
         * and current city cant have a research-center already.
         */
        virtual void build();

        /**
         * Find a cure to a certain color of disease.
         * To do so, player must be in a research-center city
         * and throw 5 cards with the disease color.
         * If cure has been discovered already, action can still be performed.
         */
        virtual Player& discover_cure(Color c);

        /**
         * Decrease to disease level in current city.
         * If a cure for this color has been discovered, we will decrease the disease level to 0.
         * If the city is clean, throw exception.
         */
        virtual Player& treat(City c);

        /**
         * Take a card from the deck.
         * If the card is already in the player hand, nothing happened.
         */
        virtual Player& take_card(City c);

        virtual void remove_cards();

        virtual string role();


        ~Player();

    };
}


#endif //PANDEMIC_A_PLAYER_H
