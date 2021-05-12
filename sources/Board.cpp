//
// Created by amit on 01/05/2021.
//

#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace pandemic {
    //Build the board.
    Board::Board() {
//        this->_neighbors = new map <City, vector<City> >;
//        this->_cures = new map <Color, bool>;
//        this->_research_centers = new map <City, bool>;
//        this->_colors = new map<City, Color>;
//        this->_cities_level = new map<City, int>;

        //Initialize all diseases as not cured yet.
        this->_cures[Color::Blue] = false;
        this->_cures[Color::Black] = false;
        this->_cures[Color::Red] = false;
        this->_cures[Color::Yellow] = false;


        City Alg = City::Algiers;
        this->_colors.insert(make_pair(Alg, Color::Black));
        this->_research_centers.insert(make_pair(Alg, false));
        this->_cities_level.insert(make_pair(Alg, 0));

        City Atl = City::Atlanta;
        this->_colors.insert(make_pair(Atl, Color::Blue));
        this->_research_centers.insert(make_pair(Atl, false));
        this->_cities_level.insert(make_pair(Atl, 0));

        City Bagh = City::Baghdad;
        this->_colors.insert(make_pair(Bagh, Color::Black));
        this->_research_centers.insert(make_pair(Bagh, false));
        this->_cities_level.insert(make_pair(Bagh, 0));

        City Bang = City::Bangkok;
        this->_colors.insert(make_pair(Bang, Color::Red));
        this->_research_centers.insert(make_pair(Bang, false));
        this->_cities_level.insert(make_pair(Bang, 0));

        City Bjng = City::Beijing;
        this->_colors.insert(make_pair(Bjng, Color::Red));
        this->_research_centers.insert(make_pair(Bjng, false));
        this->_cities_level.insert(make_pair(Bjng, 0));

        City Bgta = City::Bogota;
        this->_colors.insert(make_pair(Bgta, Color::Yellow));
        this->_research_centers.insert(make_pair(Bgta, false));
        this->_cities_level.insert(make_pair(Bgta, 0));

        City Baires = City::BuenosAires;
        this->_colors.insert(make_pair(Baires, Color::Yellow));
        this->_research_centers.insert(make_pair(Baires, false));
        this->_cities_level.insert(make_pair(Baires, 0));

        City Cairo = City::Cairo;
        this->_colors.insert(make_pair(Cairo, Color::Black));
        this->_research_centers.insert(make_pair(Cairo, false));
        this->_cities_level.insert(make_pair(Cairo, 0));

        City Chennai = City::Chennai;
        this->_colors.insert(make_pair(Chennai, Color::Black));
        this->_research_centers.insert(make_pair(Chennai, false));
        this->_cities_level.insert(make_pair(Chennai, 0));

        City Chicago = City::Chicago;
        this->_colors.insert(make_pair(Chicago, Color::Blue));
        this->_research_centers.insert(make_pair(Chicago, false));
        this->_cities_level.insert(make_pair(Chicago, 0));

        City Delhi = City::Delhi;
        this->_colors.insert(make_pair(Delhi, Color::Black));
        this->_research_centers.insert(make_pair(Delhi, false));
        this->_cities_level.insert(make_pair(Delhi, 0));

        City Essen = City::Essen;
        this->_colors.insert(make_pair(Essen, Color::Blue));
        this->_research_centers.insert(make_pair(Essen, false));
        this->_cities_level.insert(make_pair(Essen, 0));

        City Mcmc = City::HoChiMinhCity;
        this->_colors.insert(make_pair(Mcmc, Color::Red));
        this->_research_centers.insert(make_pair(Mcmc, false));
        this->_cities_level.insert(make_pair(Mcmc, 0));

        City HongKong = City::HongKong;
        this->_colors.insert(make_pair(HongKong, Color::Red));
        this->_research_centers.insert(make_pair(HongKong, false));
        this->_cities_level.insert(make_pair(HongKong, 0));

        City Istanbul = City::Istanbul;
        this->_colors.insert(make_pair(Istanbul, Color::Black));
        this->_research_centers.insert(make_pair(Istanbul, false));
        this->_cities_level.insert(make_pair(Istanbul, 0));

        City Jakarta = City::Jakarta;
        this->_colors.insert(make_pair(Jakarta, Color::Red));
        this->_research_centers.insert(make_pair(Jakarta, false));
        this->_cities_level.insert(make_pair(Jakarta, 0));

        City Jsbrg = City::Johannesburg;
        this->_colors.insert(make_pair(Jsbrg, Color::Yellow));
        this->_research_centers.insert(make_pair(Jsbrg, false));
        this->_cities_level.insert(make_pair(Jsbrg, 0));

        City Karachi = City::Karachi;
        this->_colors.insert(make_pair(Karachi, Color::Black));
        this->_research_centers.insert(make_pair(Karachi, false));
        this->_cities_level.insert(make_pair(Karachi, 0));

        City Khartoum = City::Khartoum;
        this->_colors.insert(make_pair(Khartoum, Color::Yellow));
        this->_research_centers.insert(make_pair(Khartoum, false));
        this->_cities_level.insert(make_pair(Khartoum, 0));

        City Kinshasa = City::Kinshasa;
        this->_colors.insert(make_pair(Kinshasa, Color::Yellow));
        this->_research_centers.insert(make_pair(Kinshasa, false));
        this->_cities_level.insert(make_pair(Kinshasa, 0));

        City Kolkata = City::Kolkata;
        this->_colors.insert(make_pair(Kolkata, Color::Black));
        this->_research_centers.insert(make_pair(Kolkata, false));
        this->_cities_level.insert(make_pair(Kolkata, 0));

        City Lagos = City::Lagos;
        this->_colors.insert(make_pair(Lagos, Color::Yellow));
        this->_research_centers.insert(make_pair(Lagos, false));
        this->_cities_level.insert(make_pair(Lagos, 0));

        City Lima = City::Lima;
        this->_colors.insert(make_pair(Lima, Color::Yellow));
        this->_research_centers.insert(make_pair(Lima, false));
        this->_cities_level.insert(make_pair(Lima, 0));

        City London = City::London;
        this->_colors.insert(make_pair(London, Color::Blue));
        this->_research_centers.insert(make_pair(London, false));
        this->_cities_level.insert(make_pair(London, 0));

        City LA = City::LosAngeles;
        this->_colors.insert(make_pair(LA, Color::Yellow));
        this->_research_centers.insert(make_pair(LA, false));
        this->_cities_level.insert(make_pair(LA, 0));

        City Madrid = City::Madrid;
        this->_colors.insert(make_pair(Madrid, Color::Blue));
        this->_research_centers.insert(make_pair(Madrid, false));
        this->_cities_level.insert(make_pair(Madrid, 0));

        City Manila = City::Manila;
        this->_colors.insert(make_pair(Manila, Color::Red));
        this->_research_centers.insert(make_pair(Manila, false));
        this->_cities_level.insert(make_pair(Manila, 0));

        City MxCty = City::MexicoCity;
        this->_colors.insert(make_pair(MxCty, Color::Yellow));
        this->_research_centers.insert(make_pair(MxCty, false));
        this->_cities_level.insert(make_pair(MxCty, 0));

        City Miami = City::Miami;
        this->_colors.insert(make_pair(Miami, Color::Yellow));
        this->_research_centers.insert(make_pair(Miami, false));
        this->_cities_level.insert(make_pair(Miami, 0));

        City Milan = City::Milan;
        this->_colors.insert(make_pair(Milan, Color::Blue));
        this->_research_centers.insert(make_pair(Milan, false));
        this->_cities_level.insert(make_pair(Milan, 0));

        City Mtrl = City::Montreal;
        this->_colors.insert(make_pair(Mtrl, Color::Blue));
        this->_research_centers.insert(make_pair(Mtrl, false));
        this->_cities_level.insert(make_pair(Mtrl, 0));

        City Moscow = City::Moscow;
        this->_colors.insert(make_pair(Moscow, Color::Black));
        this->_research_centers.insert(make_pair(Moscow, false));
        this->_cities_level.insert(make_pair(Moscow, 0));

        City Mumbai = City::Mumbai;
        this->_colors.insert(make_pair(Mumbai, Color::Black));
        this->_research_centers.insert(make_pair(Mumbai, false));
        this->_cities_level.insert(make_pair(Mumbai, 0));

        City NY= City::NewYork;
        this->_colors.insert(make_pair(NY, Color::Blue));
        this->_research_centers.insert(make_pair(NY, false));
        this->_cities_level.insert(make_pair(NY, 0));

        City Osaka = City::Osaka;
        this->_colors.insert(make_pair(Osaka, Color::Red));
        this->_research_centers.insert(make_pair(Osaka, false));
        this->_cities_level.insert(make_pair(Osaka, 0));

        City Paris = City::Paris;
        this->_colors.insert(make_pair(Paris, Color::Blue));
        this->_research_centers.insert(make_pair(Paris, false));
        this->_cities_level.insert(make_pair(Paris, 0));

        City Riyadh = City::Riyadh;
        this->_colors.insert(make_pair(Riyadh, Color::Black));
        this->_research_centers.insert(make_pair(Riyadh, false));
        this->_cities_level.insert(make_pair(Riyadh, 0));

        City SanF = City::SanFrancisco;
        this->_colors.insert(make_pair(SanF, Color::Blue));
        this->_research_centers.insert(make_pair(SanF, false));
        this->_cities_level.insert(make_pair(SanF, 0));

        City Santiago = City::Santiago;
        this->_colors.insert(make_pair(Santiago, Color::Yellow));
        this->_research_centers.insert(make_pair(Santiago, false));
        this->_cities_level.insert(make_pair(Santiago, 0));

        City SaoP = City::SaoPaulo;
        this->_colors.insert(make_pair(SaoP, Color::Yellow));
        this->_research_centers.insert(make_pair(SaoP, false));
        this->_cities_level.insert(make_pair(SaoP, 0));

        City seoul = City::Seoul;
        this->_colors.insert(make_pair(seoul, Color::Red));
        this->_research_centers.insert(make_pair(seoul, false));
        this->_cities_level.insert(make_pair(seoul, 0));

        City Shanghai = City::Shanghai;
        this->_colors.insert(make_pair(Shanghai, Color::Red));
        this->_research_centers.insert(make_pair(Shanghai, false));
        this->_cities_level.insert(make_pair(Shanghai, 0));

        City StPeter = City::StPetersburg;
        this->_colors.insert(make_pair(StPeter, Color::Blue));
        this->_research_centers.insert(make_pair(StPeter, false));
        this->_cities_level.insert(make_pair(StPeter, 0));

        City Sydney = City::Sydney;
        this->_colors.insert(make_pair(Sydney, Color::Red));
        this->_research_centers.insert(make_pair(Sydney, false));
        this->_cities_level.insert(make_pair(Sydney, 0));

        City Taipei = City::Taipei;
        this->_colors.insert(make_pair(Taipei, Color::Red));
        this->_research_centers.insert(make_pair(Taipei, false));
        this->_cities_level.insert(make_pair(Taipei, 0));

        City Tehran = City::Tehran;
        this->_colors.insert(make_pair(Tehran, Color::Black));
        this->_research_centers.insert(make_pair(Tehran, false));
        this->_cities_level.insert(make_pair(Tehran, 0));

        City Tokyo = City::Tokyo;
        this->_colors.insert(make_pair(Tokyo, Color::Red));
        this->_research_centers.insert(make_pair(Tokyo, false));
        this->_cities_level.insert(make_pair(Tokyo, 0));

        City DC = City::Washington;
        this->_colors.insert(make_pair(DC, Color::Blue));
        this->_research_centers.insert(make_pair(DC, false));
        this->_cities_level.insert(make_pair(DC, 0));

        //Now we connect between neighbors.
        this->_neighbors[Alg].push_back(Madrid);
        this->_neighbors[Alg].push_back(Paris);
        this->_neighbors[Alg].push_back(Istanbul);
        this->_neighbors[Alg].push_back(Cairo);

        this->_neighbors[Atl].push_back(Chicago);
        this->_neighbors[Atl].push_back(Miami);
        this->_neighbors[Atl].push_back(DC);

        this->_neighbors[Bagh].push_back(Istanbul);
        this->_neighbors[Bagh].push_back(Tehran);
        this->_neighbors[Bagh].push_back(Cairo);
        this->_neighbors[Bagh].push_back(Riyadh);
        this->_neighbors[Bagh].push_back(Karachi);

        this->_neighbors[Bang].push_back(Kolkata);
        this->_neighbors[Bang].push_back(Chennai);
        this->_neighbors[Bang].push_back(Jakarta);
        this->_neighbors[Bang].push_back(Mcmc);
        this->_neighbors[Bang].push_back(HongKong);

        this->_neighbors[Bjng].push_back(Shanghai);
        this->_neighbors[Bjng].push_back(seoul);

        this->_neighbors[Bgta].push_back(MxCty);
        this->_neighbors[Bgta].push_back(Lima);
        this->_neighbors[Bgta].push_back(Miami);
        this->_neighbors[Bgta].push_back(SaoP);
        this->_neighbors[Bgta].push_back(Baires);

        this->_neighbors[Baires].push_back(Bgta);
        this->_neighbors[Baires].push_back(SaoP);

        this->_neighbors[Cairo].push_back(Alg);
        this->_neighbors[Cairo].push_back(Istanbul);
        this->_neighbors[Cairo].push_back(Bagh);
        this->_neighbors[Cairo].push_back(Khartoum);
        this->_neighbors[Cairo].push_back(Riyadh);

        this->_neighbors[Chennai].push_back(Mumbai);
        this->_neighbors[Chennai].push_back(Delhi);
        this->_neighbors[Chennai].push_back(Kolkata);
        this->_neighbors[Chennai].push_back(Bang);
        this->_neighbors[Chennai].push_back(Jakarta);

        this->_neighbors[Chicago].push_back(SanF);
        this->_neighbors[Chicago].push_back(LA);
        this->_neighbors[Chicago].push_back(MxCty);
        this->_neighbors[Chicago].push_back(Atl);
        this->_neighbors[Chicago].push_back(Mtrl);

        this->_neighbors[Delhi].push_back(Tehran);
        this->_neighbors[Delhi].push_back(Karachi);
        this->_neighbors[Delhi].push_back(Mumbai);
        this->_neighbors[Delhi].push_back(Chennai);
        this->_neighbors[Delhi].push_back(Kolkata);

        this->_neighbors[Essen].push_back(London);
        this->_neighbors[Essen].push_back(Paris);
        this->_neighbors[Essen].push_back(Milan);
        this->_neighbors[Essen].push_back(StPeter);

        this->_neighbors[Mcmc].push_back(Jakarta);
        this->_neighbors[Mcmc].push_back(HongKong);
        this->_neighbors[Mcmc].push_back(Bang);
        this->_neighbors[Mcmc].push_back(Manila);

        this->_neighbors[HongKong].push_back(Bang);
        this->_neighbors[HongKong].push_back(Kolkata);
        this->_neighbors[HongKong].push_back(Mcmc);
        this->_neighbors[HongKong].push_back(Shanghai);
        this->_neighbors[HongKong].push_back(Manila);
        this->_neighbors[HongKong].push_back(Taipei);

        this->_neighbors[Istanbul].push_back(Milan);
        this->_neighbors[Istanbul].push_back(Alg);
        this->_neighbors[Istanbul].push_back(StPeter);
        this->_neighbors[Istanbul].push_back(Cairo);
        this->_neighbors[Istanbul].push_back(Bagh);
        this->_neighbors[Istanbul].push_back(Moscow);

        this->_neighbors[Jakarta].push_back(Chennai);
        this->_neighbors[Jakarta].push_back(Bang);
        this->_neighbors[Jakarta].push_back(Mcmc);
        this->_neighbors[Jakarta].push_back(Sydney);

        this->_neighbors[Jsbrg].push_back(Khartoum);
        this->_neighbors[Jsbrg].push_back(Kinshasa);

        this->_neighbors[Karachi].push_back(Tehran);
        this->_neighbors[Karachi].push_back(Bagh);
        this->_neighbors[Karachi].push_back(Riyadh);
        this->_neighbors[Karachi].push_back(Mumbai);
        this->_neighbors[Karachi].push_back(Delhi);

        this->_neighbors[Khartoum].push_back(Cairo);
        this->_neighbors[Khartoum].push_back(Lagos);
        this->_neighbors[Khartoum].push_back(Kinshasa);
        this->_neighbors[Khartoum].push_back(Jsbrg);

        this->_neighbors[Kinshasa].push_back(Lagos);
        this->_neighbors[Kinshasa].push_back(Khartoum);
        this->_neighbors[Kinshasa].push_back(Jsbrg);

        this->_neighbors[Kolkata].push_back(Delhi);
        this->_neighbors[Kolkata].push_back(Chennai);
        this->_neighbors[Kolkata].push_back(Bang);
        this->_neighbors[Kolkata].push_back(HongKong);

        this->_neighbors[Lagos].push_back(SaoP);
        this->_neighbors[Lagos].push_back(Khartoum);
        this->_neighbors[Lagos].push_back(Kinshasa);

        this->_neighbors[Lima].push_back(MxCty);
        this->_neighbors[Lima].push_back(Bgta);
        this->_neighbors[Lima].push_back(Santiago);

        this->_neighbors[London].push_back(NY);
        this->_neighbors[London].push_back(Madrid);
        this->_neighbors[London].push_back(Essen);
        this->_neighbors[London].push_back(Paris);

        this->_neighbors[LA].push_back(SanF);
        this->_neighbors[LA].push_back(Chicago);
        this->_neighbors[LA].push_back(MxCty);
        this->_neighbors[LA].push_back(Sydney);

        this->_neighbors[Madrid].push_back(London);
        this->_neighbors[Madrid].push_back(NY);
        this->_neighbors[Madrid].push_back(Paris);
        this->_neighbors[Madrid].push_back(SaoP);
        this->_neighbors[Madrid].push_back(Alg);

        this->_neighbors[Manila].push_back(Taipei);
        this->_neighbors[Manila].push_back(SanF);
        this->_neighbors[Manila].push_back(Mcmc);
        this->_neighbors[Manila].push_back(Sydney);
        this->_neighbors[Manila].push_back(HongKong);

        this->_neighbors[MxCty].push_back(LA);
        this->_neighbors[MxCty].push_back(Chicago);
        this->_neighbors[MxCty].push_back(Miami);
        this->_neighbors[MxCty].push_back(Lima);
        this->_neighbors[MxCty].push_back(Bgta);

        this->_neighbors[Miami].push_back(MxCty);
        this->_neighbors[Miami].push_back(Atl);
        this->_neighbors[Miami].push_back(DC);
        this->_neighbors[Miami].push_back(Bgta);

        this->_neighbors[Milan].push_back(Paris);
        this->_neighbors[Milan].push_back(Essen);
        this->_neighbors[Milan].push_back(Istanbul);

        this->_neighbors[Mtrl].push_back(Chicago);
        this->_neighbors[Mtrl].push_back(DC);
        this->_neighbors[Mtrl].push_back(NY);

        this->_neighbors[Moscow].push_back(StPeter);
        this->_neighbors[Moscow].push_back(Istanbul);
        this->_neighbors[Moscow].push_back(Tehran);

        this->_neighbors[Mumbai].push_back(Karachi);
        this->_neighbors[Mumbai].push_back(Delhi);
        this->_neighbors[Mumbai].push_back(Chennai);

        this->_neighbors[NY].push_back(Mtrl);
        this->_neighbors[NY].push_back(London);
        this->_neighbors[NY].push_back(Madrid);
        this->_neighbors[NY].push_back(DC);

        this->_neighbors[Osaka].push_back(Taipei);
        this->_neighbors[Osaka].push_back(Tokyo);

        this->_neighbors[Paris].push_back(Alg);
        this->_neighbors[Paris].push_back(Essen);
        this->_neighbors[Paris].push_back(Madrid);
        this->_neighbors[Paris].push_back(Milan);
        this->_neighbors[Paris].push_back(London);

        this->_neighbors[Riyadh].push_back(Bagh);
        this->_neighbors[Riyadh].push_back(Cairo);
        this->_neighbors[Riyadh].push_back(Karachi);

        this->_neighbors[SanF].push_back(LA);
        this->_neighbors[SanF].push_back(Chicago);
        this->_neighbors[SanF].push_back(Tokyo);
        this->_neighbors[SanF].push_back(Manila);

        this->_neighbors[Santiago].push_back(Lima);

        this->_neighbors[SaoP].push_back(Bgta);
        this->_neighbors[SaoP].push_back(Baires);
        this->_neighbors[SaoP].push_back(Lagos);
        this->_neighbors[SaoP].push_back(Madrid);

        this->_neighbors[seoul].push_back(Bjng);
        this->_neighbors[seoul].push_back(Shanghai);
        this->_neighbors[seoul].push_back(Tokyo);

        this->_neighbors[Shanghai].push_back(Bjng);
        this->_neighbors[Shanghai].push_back(HongKong);
        this->_neighbors[Shanghai].push_back(Taipei);
        this->_neighbors[Shanghai].push_back(seoul);
        this->_neighbors[Shanghai].push_back(Tokyo);

        this->_neighbors[StPeter].push_back(Essen);
        this->_neighbors[StPeter].push_back(Istanbul);
        this->_neighbors[StPeter].push_back(Moscow);

        this->_neighbors[Sydney].push_back(Jakarta);
        this->_neighbors[Sydney].push_back(Manila);
        this->_neighbors[Sydney].push_back(LA);

        this->_neighbors[Taipei].push_back(Shanghai);
        this->_neighbors[Taipei].push_back(HongKong);
        this->_neighbors[Taipei].push_back(Osaka);
        this->_neighbors[Taipei].push_back(Manila);

        this->_neighbors[Tehran].push_back(Bagh);
        this->_neighbors[Tehran].push_back(Moscow);
        this->_neighbors[Tehran].push_back(Karachi);
        this->_neighbors[Tehran].push_back(Delhi);

        this->_neighbors[Tokyo].push_back(seoul);
        this->_neighbors[Tokyo].push_back(Shanghai);
        this->_neighbors[Tokyo].push_back(Osaka);
        this->_neighbors[Tokyo].push_back(SanF);

        this->_neighbors[DC].push_back(Atl);
        this->_neighbors[DC].push_back(NY);
        this->_neighbors[DC].push_back(Mtrl);
        this->_neighbors[DC].push_back(Miami);
    }

    vector<City> Board::get_neighbors(City c){
        if(this->_neighbors.find(c) != this->_neighbors.end()) {
            return this->_neighbors.at(c);
        }
        throw exception();

    }

    map<City, bool> Board::get_research_centers() {
        return this->_research_centers;
    }

    void Board::add_research_center(City c){
        this->_research_centers.find(c)->second = true;
    }

    map<Color, bool> Board::get_cures() {
        return this->_cures;
    }

    void Board::set_cure(Color c) {
        if(this->_cures.find(c) != this->_cures.end()) {
            this->_cures.find(c)->second = true;
        }
        else{
            throw exception();
        }
    }

    void Board::decrease_level(City c) {
        this->_cities_level[c] = this->_cities_level.find(c)->second - 1;
    }

    void Board::set_level_to_zero(City c) {
            this->_cities_level[c] = 0;
    }

    map<City, Color> Board::get_colors() {
        return this->_colors;
    }
    int & Board::operator[](City c){
        if(this->_cities_level.find(c) != this->_cities_level.end()){
            return this->_cities_level[c];
        }
        throw exception();

    }


//    const int & Board::operator[](City c) const{
//        if(this->_cities_level.find(c) != this->_cities_level.end()){
//            return this->_cities_level.find(c)->second;
//        }
//        else{
//            throw exception();
//        }
//    }

    ostream& operator<<(ostream &os, const Board &b){
        return os<<""<<endl;
    }

    bool Board::is_clean() {
        for(auto level : this->_cities_level){
            if(level.second != 0){
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        for (auto const& x : _cures)
        {
            _cures[x.first] = false;
        }
    }

    void Board::remove_stations(){
        for (auto const& x : _research_centers)
        {
            _research_centers[x.first] = false;
        }
    }

    Board::~Board() {
    }
}
