//
// Created by amit on 01/05/2021.
//

#ifndef PANDEMIC_A_BOARD_H
#define PANDEMIC_A_BOARD_H

#include <map>
#include <vector>
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic {

    class Board {
    private:
        map <City, Color> _colors;
        map <City, int> _cities_level;
        map <City, vector<City> > _neighbors;
        map <City, bool> _research_centers;
        map <Color, bool> _cures;

    public:
        Board();

        vector<City> get_neighbors(City c);

        map<string, City> build_board();

        map<Color, bool> get_cures();

        void set_cure(Color c);

        void decrease_level(City c);

        void set_level_to_zero(City c);

        map<City, Color> get_colors();

        map<City, bool> get_research_centers();

        void add_research_center(City c);

        int & operator[](City c);
//        const int & operator[](City c) const;

        friend ostream& operator <<(ostream& os, const Board& b);

        bool is_clean();

        void remove_cures();

        void remove_stations();

        ~Board();
    };
    ostream& operator <<(ostream& os, const Board& b);
}


#endif //PANDEMIC_A_BOARD_H
