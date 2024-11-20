// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#ifndef CITY_H // Siempre hay que poner #ifndef y al final del fichero #endif 
#define CITY_H

#include "Coordinates.h"
#include "CityInfo.h"

#include <iostream>
#include <vector>
using namespace std;

class City{

    friend ostream & operator<<(ostream &os, const City &c);

    private:

        int id;
        string name;
        Coordinates coord;
        CityInfo info;
        bool esInicioCrucero;

    public:

        City(string name);
        City(const City &c);
        City & operator=(const City &c);
        int setCoord(int r, int c, vector<vector<char>> &map);
        string getName() const;
        Coordinates &getCoord();
        void setInfo(CityInfo info);
        int getId() const;
        CityInfo &getInfo();
        City(); // constructor por defecto
        bool getInicioCrucero(); // devuelve el valor de esInicioCrucero
        void setInicioCrucero(); // pone la variable esInicioCrucero como true
};
#endif