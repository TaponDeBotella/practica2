// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#include "Coordinates.h"

Coordinates::Coordinates(){
    // se inicializan las coordenadas a -1 para indicar que no son validas
    row = -1;
    col = -1;
}

Coordinates::Coordinates(int r, int c){

    if(r>=0 && c>=0){ // los dos enteros tiene que ser validos

        row = r;
        col = c;
    }else{ // en caso de que no sean validos, seran -1

        row = -1;
        col = -1;
    }
}

Coordinates::Coordinates(const Coordinates &c){ // constructor de copia

    row = c.row;
    col = c.col;
}

Coordinates & Coordinates::operator=(const Coordinates &c){

    if(this != &c){

	    row = c.row;
	    col = c.col;
	}

	return *this;
}

int Coordinates::getRow() const{ // devuelve el valor de row

    return row;
}

int Coordinates::getCol() const{ // devuelve el valor de col

    return col;
}

ostream & operator<<(ostream &os, const Coordinates &c){
	os << "(" << c.row << "," << c.col << ")";
	return os;
}

bool Coordinates::validCoord(){ // indica si la coordenada es valida

    bool ret = false;

    if(row>=0){
        if(col>=0){

            ret = true;
        }
    }

    return ret;
}