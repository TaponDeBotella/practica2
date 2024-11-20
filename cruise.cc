// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#include <iostream>
using namespace std;

#include "Island.h"

int main(int argc,char* argv[]){

    Map mapa;

    if(argc==2){

        // variables
            City puertoInicio;
            string nombre_ciudad;
            City ciudad;
            City ciudad_costera1;
        ////////////////////

        string name=argv[1];
        mapa.read(name); // se usa el metodo read para leer todo el fichero
        vector<vector<char>> mapa_paramostrar = mapa.getMap(); // se almacena el mapa caracter por caracter en una matriz de char

        Island isla = Island(mapa); // se crea la isla con el mapa del fichero y toda su informacion
        List ciudades_costeras = isla.getCoastCities(); // se consigue la lista con todas las ciudades menos la capital
        City capital = isla.getCapital(); // y se consigue la capital

        //primero se comprueba si la capital es una ciudad costera
        Coordinates coordenadas_capital = capital.getCoord();
        ciudad_costera1 = ciudades_costeras.get(0);

        if(isla.isCoast(coordenadas_capital)==true){ // si la capital es costera, esa es el puerto de inicio

            capital.setInicioCrucero();
        }else{

            ciudad_costera1.setInicioCrucero(); // se le pone a la ciudad que sea la mas cercana
        }
        
        // ahora se ve donde esta el puerto (NESO)
        Coordinates coord_puertoSalida = 


    }
}