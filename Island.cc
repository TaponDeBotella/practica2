// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#include "Island.h"

Island::Island(Map &map) {

    vector<City> ciudades = map.getCities(); // primero se consigue el vector con todas las ciudades del mapa
    int tamayo_cities = ciudades.size(); // se consigue el tamanyo del vector de ciudades
    City ciudad;
    Coordinates coordenadas_ciudad;
    int distancia;

    mapa = map; // se guarda el mapa que han pasado por parametro

    capital = ciudades[0]; // la capital sera la que esta en la posicion 0
    Coordinates coordenadas_capital = capital.getCoord(); // se consigue las coordenadas de la capital

    for(int i=1; i<tamayo_cities; i++){ // se recorre todo el vector
        // y para anyadir se hace siguiendo la distancia de Manhattan

        ciudad = ciudades[i];  // se consigue la ciudad actual
        coordenadas_ciudad = ciudad.getCoord(); // y se saca su coordenada

        // d(c1,c2) = |x1-x2| + |y1-y2|
        distancia = abs(coordenadas_capital.getRow() - coordenadas_ciudad.getRow()) + abs(coordenadas_capital.getCol() - coordenadas_ciudad.getCol());

        // por ultimo se anyade pasandole a add la ciudad y la distancia que se ha obtenido con la formula
        cities.add(ciudad, distancia);    
    }
}

int Island::remove(string cityName) {

    int devolver = -1;
    City ciudad_borrada;
    Coordinates coordenadas_ciudad;
    Coordinates coordenadas_capital = capital.getCoord();

    ciudad_borrada = cities.remove(cityName); // se le pasa el nombre al remove de List para que la borre
    if(ciudad_borrada.getName() != ""){ // en caso de que se haya borrado correctamente, se devuelve la distancia

        devolver = abs(coordenadas_capital.getRow() - coordenadas_ciudad.getRow()) + abs(coordenadas_capital.getCol() - coordenadas_ciudad.getCol());
    }
    return devolver;
}

List &Island::getCities(){

    List *devolver_lista;
    int tamanyo_lista = cities.tamanyo(); // se consigue el tamanyo de la lista de cities
    City ciudad;
    int distancia;
    Coordinates coordenadas_ciudad;
    Coordinates coordenadas_capital = capital.getCoord(); // se almacenan las coordenadas de la capital

    if(cities.isEmpty()==true){ // en caso de que la lista de cities este vacia se devuelve una lista vacia

        *devolver_lista = List();
    }else{ // en caso de que no este vacia, se continua sin problema

        for(int i=1; i<tamanyo_lista; i++){ // se recorre la lista entera, saltandose la capital

            ciudad = cities.get(i); // se consigue la ciudad actual

            // primero hay que ver en donde se va a anyadir y para eso hay que sacarle la distancia como antes
            coordenadas_ciudad = ciudad.getCoord();
        
            distancia = abs(coordenadas_capital.getRow() - coordenadas_ciudad.getRow()) + abs(coordenadas_capital.getCol() - coordenadas_ciudad.getCol());
        
            devolver_lista->add(ciudad,distancia); // se anyade a la lista la ciudad actual
        }
    }

    return *devolver_lista;
}

string Island::getNearestCoast(){

    string devolver = "No hay ninguna localidad costera"; // en caso de que no haya ninguna localidad costera se devuelve un string con el mensaje de eror
    City ciudad; 
    Coordinates coordenadas_ciudad;
    bool es_costera = false;
    int distancia;
    Coordinates coordenadas_capital = capital.getCoord();
    int menos_distancia = 99; // se pone un niumero muy grande para que en la primera iteracion siempre entre en el if
    
    if(cities.isEmpty()==false){ // en caso de que la lista de cities no este vacia se sigue
        for(int i=0; i<cities.tamanyo(); i++){ // se recorren todas las ciudades

            ciudad = cities.get(i); // se consigue la ciudad actual
            coordenadas_ciudad = ciudad.getCoord(); // y las coordenadas de la ciudad actual

            // y ahora se comprueba si es costera con el metodo isCoast
            es_costera = isCoast(coordenadas_ciudad);

            if(es_costera == true){ // si resulta ser costera, entonces vemos su distancia a la capital con lo de Manhattan

                coordenadas_ciudad = ciudad.getCoord(); // se sacan las coordenadas de la ciudad para el calculo
                
                distancia = abs(coordenadas_capital.getRow() - coordenadas_ciudad.getRow()) + abs(coordenadas_capital.getCol() - coordenadas_ciudad.getCol());

                if(distancia<menos_distancia){ // ahora se comprueba si la distancia de ahora es menor que la de antes

                    menos_distancia = distancia; // se actualiza el valor a la nueva distancia
                    devolver = ciudad.getName(); // y se cambia el string que se devuelve al nombre de la ciudad actual
                }
            }
        }
    }

    return devolver;
}

bool Island::isCoast(Coordinates coord){

    int fila = coord.getRow();
    int col = coord.getCol();
    bool es_costa = false;

    vector<int> tamanyoMapa = mapa.tamanyoMapa(); // se obtiene el size del mapa
    int sizeRow = tamanyoMapa[0]; // size de las filas
    int sizeCol = tamanyoMapa[1]; // size de las columas

    // se comprueba que la coordenada sea valida
    if(fila>=0 && fila<=sizeRow){
        if(col>=0 && col<=sizeCol){

            // primero se ve que rodea a la coordenada actual en el norte sur este y oeste
            char norte = mapa.getMapPosition(Coordinates(fila-1,col));
            char sur = mapa.getMapPosition(Coordinates(fila+1,col));
            char este = mapa.getMapPosition(Coordinates(fila,col+1));
            char oeste = mapa.getMapPosition(Coordinates(fila,col-1));

            // y ahora se comprueba si hay mar por algun lado
            if(norte == 'M'){
                es_costa = true;
            }      

            if(sur == 'M'){
                es_costa = true;
            }

            if(este == 'M'){
                es_costa = true;
            }

            if(oeste == 'M'){
                es_costa = true;
            }
        }
    } 
    return es_costa;
}

List Island::getCoastCities(){

    List devolver;
    City ciudad;
    Coordinates coordenadas_ciudad;
    Coordinates coordenadas_capital = capital.getCoord();
    int distancia;

    for(int i=0; i<cities.tamanyo(); i++){ // se recorre la lista de cities

        ciudad = cities.get(i); // y se saca cada ciudad        

        if(isCoast(coordenadas_ciudad)){ // si la ciudad es costera se anyade, pero primero se saca su distancia

            coordenadas_ciudad = ciudad.getCoord();
            distancia = abs(coordenadas_capital.getRow() - coordenadas_ciudad.getRow()) + abs(coordenadas_capital.getCol() - coordenadas_ciudad.getCol());

            devolver.add(ciudad,distancia); // y se anyade la ciudad a la List de ciudades costeras
        }
    }
    return devolver;
}

ostream & operator <<(ostream &os, const Island &isla){

    os << isla.capital << endl; // primero se muestra la capital

    os<< isla.cities; // y luego se muestran las ciudades con el formato del List

    return os;
}

City Island::getCapital(){

    return capital;
}

void Island::setInicioCrucero(string nombre_ciudad){

    City ciudad;

    for(int i=0; i<cities.tamanyo(); i++){ // se recorren todas las ciudades

        ciudad = cities.get(i);

        if(ciudad.getName()==nombre_ciudad){ // si coincide el nombre, entonces se pone como inicio de crucero

            ciudad.setInicioCrucero();
        }
    }
}

Coordinates Island::buscaPuerto(City ciudad){

    Coordinates devolver;
    Coordinates coord = ciudad.getCoord();
    bool puertoEncontrado = false;

    int fila = coord.getRow();
    int col = coord.getCol();

    // primero se ve que rodea a la coordenada actual en el norte sur este y oeste
    char norte = mapa.getMapPosition(Coordinates(fila-1,col));
    char sur = mapa.getMapPosition(Coordinates(fila+1,col));
    char este = mapa.getMapPosition(Coordinates(fila,col+1));
    char oeste = mapa.getMapPosition(Coordinates(fila,col-1));

    // ahora se busca el primer trozo de agua (NESO)
    if(norte == 'M'){

        devolver = Coordinates(fila-1,col);
        puertoEncontrado = true;
    } 

    if(este == 'M' && puertoEncontrado==false){

        devolver = Coordinates(fila,col+1);
        puertoEncontrado = true;
    }     

    if(sur == 'M' && puertoEncontrado==false){

        devolver = Coordinates(fila+1,col);
        puertoEncontrado = true;
    }

    if(oeste == 'M' && puertoEncontrado==false){

        devolver = Coordinates(fila,col-1);
        puertoEncontrado = true;
    }

    return devolver; // se devuelven las coordenadas el puerto

}