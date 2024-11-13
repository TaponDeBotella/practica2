// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA

#ifndef COORDINATES_H // Siempre hay que poner #ifndef y al final del fichero #endif 
#define COORDINATES_H

#include <iostream>
#include <vector>
using namespace std;

class Coordinates{

    friend ostream & operator<<(ostream &os, const Coordinates &c);

    private:

        int row;
        int col;

    public:

        Coordinates();
        Coordinates(int r, int c);
        Coordinates(const Coordinates &c);
        Coordinates & operator=(const Coordinates &c);
        int getRow() const;
        int getCol() const;
        bool validCoord();
};
#endif