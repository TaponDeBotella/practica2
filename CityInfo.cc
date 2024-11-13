// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#include "CityInfo.h"



CityInfo::CityInfo(){ // constructor de CityInfol. Se inicializa todo a 0, falso o vacio

	museums = 0;
	monuments = 0;
	hotels = 0;
	restaurants = 0;
	airport = false;
	mostImportant = ""; // no hace falta inicializar esto, ya que se inicializa automaticamente en su propia clase
}

CityInfo::CityInfo(int mu, int mo, int h, int r, bool a){

	airport = a;
	mostImportant = "";

	if(mu<0){
		museums = 0;
	}else{
		museums = mu;
	}

	if(mo<0){
		monuments = 0;
	}else{
		monuments = mo;
	}

	if(h<0){
		hotels = 0;
	}else{
		hotels = h;
	}

	if(r<0){
		restaurants = 0;
	}else{
		restaurants = r;
	}
}

CityInfo::CityInfo(const CityInfo &c){ // en este constructor se copian todos los datos de las variables del objeto pasado por referencia

	museums = c.museums;
	monuments = c.monuments;
	hotels = c.hotels;
	restaurants = c.restaurants;
	airport = c.airport;
	mostImportant = c.mostImportant;
}

CityInfo::~CityInfo(){

	museums = 0;
	monuments = 0;
	hotels = 0;
	restaurants = 0;
	airport = false;
	mostImportant = "";
}



// Sobrecarga operador salida

ostream & operator<<(ostream &os, const CityInfo &c){
	os << c.museums << " " << c.monuments << " " << c.hotels << " "
	<< c.restaurants << " " << c.airport << " " << c.mostImportant << endl;
	return os;
}

// Sobrecarga operador =

CityInfo & CityInfo::operator =(const CityInfo &c){

	if(this != &c){
	museums = c.museums;
	monuments = c.monuments;
	hotels = c.hotels;
	restaurants = c.restaurants;
	airport = c.airport;
	mostImportant = c.mostImportant;
	}

	return *this;

}

// Sobrecarga operador !=

bool CityInfo::operator !=(const CityInfo &c){

	bool ret;
	ret = true;
	vector<int> cc = c.getInterestPoints();
	bool air = c.hasAirport(); 
	string mi = c.getMostImportant();
	int cont =0;

	if(museums == cc[0]){

		cont++;
	}

	if(monuments == cc[1]){

		cont++;
	}

	if(hotels == cc[2]){

		cont++;
	}

	if(restaurants == cc[3]){

		cont++;
	}

	if(airport == air){

		cont++;
	}

	if(mostImportant == mi){

		cont++;
	}

	if(cont==6){
		ret = false;
	}

	return ret;

}

// Sobrecarga operador ==

bool CityInfo::operator==(const CityInfo &c){

	bool ret;
	ret = true;
	vector<int> cc = c.getInterestPoints();
	bool air = c.hasAirport(); 
	string mi = c.getMostImportant();

	if(museums != cc[0]){

		ret = false;
	}

	if(monuments != cc[1]){

		ret = false;
	}

	if(hotels != cc[2]){

		ret = false;
	}

	if(restaurants != cc[3]){

		ret = false;
	}

	if(airport != air){

		ret = false;
	}

	if(mostImportant != mi){

		ret = false;
	}

	return ret;

}

vector<int> CityInfo::getInterestPoints() const{ // devuelve los valores de las variables int del objeto

	vector<int> ret;

	ret.push_back(museums);
	ret.push_back(monuments);
	ret.push_back(hotels);
	ret.push_back(restaurants);

	return ret;
}

bool CityInfo::hasAirport() const{

	return airport;
}

string CityInfo::getMostImportant() const{

	return mostImportant;
}

string CityInfo::getMostFrequent() const{

	int cont = 0;
	string ret;
	
	if(airport==true){

		cont = 1;
		ret = "airport";
	}

	if(hotels > cont){
	
		cont = hotels;
		ret = "hotel";				
	}

	if(monuments > cont){

		cont = monuments;
		ret = "monument";
					
	}

	if(museums > cont){

		cont = museums;
		ret = "museum";
				
	}

	if(restaurants > cont){

		
		cont = restaurants;
		ret = "restaurant";
				
	}

	return ret;
}

void CityInfo::setMostImportant(string name){

	mostImportant = name;
}

