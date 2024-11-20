// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA

#include "City.h"

City::City(string name){

    id = -1; // siempre se inicializa a -1
    this->name = name; // el this-> en c++ es igual que el this. del java
    info = CityInfo(); // llamamos al constructor vacio de CityInfo y Coordinates para que obtengan sus valores por defecto
    coord = Coordinates(); 
    esInicioCrucero = false;   
}

City::City(const City &c){ // constructor copia

    id = c.id;
    name = c.name;
    info = c.info;
    coord = c.coord;
    esInicioCrucero = c.esInicioCrucero;
}

City::City(){ // constructor por defecto

    name = ""; // inicializa el nombre de la ciudad con una cadena vacia
    id = -1;   // inicializa el id de la ciudad como -1
    esInicioCrucero = false;

}

City & City::operator =(const City &c){ // sobrecarga operador =

	if(this != &c){
	id = c.id;
	name = c.name;
	coord = c.coord;
	info = c.info;
	}

	return *this;
}

int City::setCoord(int r, int c, vector<vector<char>> &map){

    bool valid = coord.validCoord(); // comprobamos si hay ya coordenada 
    int ret = -1; 

    if(valid!=true){ // en caso de que no tenga coordenada, procedemos con el metodo
        
        if(r>=0 && r<= (int)    map.size()){ // se comprueba que la coordenada es valida
            if(c>=0 && c<=(int)map[0].size()){

                if(map[r][c]=='T'){ // si esa casilla es Tierra, se procede

                    map[r][c] = 'C'; // se pone una ciudad en esa casilla
                    id = (r*((int)map[0].size()) + c); // se modifica el id de la ciudad
                    ret = id; // valor que devuelve si se modifica algo
                    Coordinates cor(r,c);
                    coord = cor;
                }
            }
        }        
    }

    return ret;
}

string City::getName() const{

    return name;
}

Coordinates &City::getCoord(){

    return coord; // se pone el & porque tenemos que devolver una referencia al objeto, porque si no, estariamos devolviendo una copia del objeto, y eso no lo queremos
} 

int City::getId() const{

    return id;
}

ostream & operator<<(ostream &os, const City &c){

    os << c.id << "-" << c.name << "-" << c.coord << endl 
    << c.info;

    return os;
}

CityInfo &City::getInfo(){

    return info;
}

void City::setInfo(CityInfo info){

    this->info = info; // se sustituye la informacion de la ciudad
}

bool City::getInicioCrucero(){

    return esInicioCrucero;
}

void City::setInicioCrucero(){

    esInicioCrucero = true;
}