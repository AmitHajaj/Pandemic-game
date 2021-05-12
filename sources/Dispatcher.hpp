
#ifndef PANDEMIC_A_DISPATCHER_H
#define PANDEMIC_A_DISPATCHER_H
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace std;
namespace pandemic{
    class Dispatcher : public Player{
    public:
        Dispatcher(Board& board, City city);

        Dispatcher(Dispatcher& p);

        /**
         * Fly from current city to a city, only if the player hold this city's card in you hand,
         * and player must throw this destination city's card.
         */
        Dispatcher& fly_direct(City c);


        string role();

        ~Dispatcher();
    };
}
#endif //PANDEMIC_A_DISPATCHER_H
