// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#ifndef MAP_H // Siempre hay que poner #ifndef y al final del fichero #endif 
#define MAP_H

#include "City.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Map{

    friend ostream & operator <<(ostream &os, const Map &c);

    private:
        vector<vector<char>> map;
        vector<City> cities;

    public:
        Map(); // constructor
        void read(string filename);
        vector<vector<char>> &getMap();
        char getMapPosition(Coordinates coord) const;
        vector<City> &getCities();
};
#endif