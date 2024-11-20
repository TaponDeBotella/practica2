// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#ifndef ISLAND_H  
#define ISLAND_H 

#include "List.h"
#include <iostream>
using namespace std;

class Island{

    friend ostream & operator <<(ostream &os, const Island &c);

    private:

    City capital;
    List cities; // ordenada por distancia a la capital
    Map mapa;

    public:

    Island(Map &map);
    int remove(string cityName);
    List & getCities();
    string getNearestCoast();
    bool isCoast(Coordinates coord);
    List getCoastCities();
    City getCapital();
    void setInicioCrucero(string nombre_ciudad);
    Coordinates buscaPuerto(City ciudad); // busca donde esta el puerto de la ciudad costera en el siguiente orden (NESO)
};
#endif