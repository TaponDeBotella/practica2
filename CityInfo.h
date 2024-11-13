// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#ifndef CITYINFO_H // Siempre hay que poner #ifndef y al final del fichero #endif 
#define CITYINFO_H

#include <iostream>
#include <vector>
using namespace std;

class CityInfo{

	friend ostream & operator<<(ostream &os, const CityInfo &c);

	private: // aqui van a ir todas las variables privadas del programa

		int museums;
		int monuments;
		int hotels;
		int restaurants;
		bool airport;
		string mostImportant;

	public: // y aqui van a ir las publicas (normalmente funciones)

		CityInfo(); // este es el constructor de la clase
		CityInfo(int mu, int mo, int h, int r, bool a); // constructor propio
		CityInfo(const CityInfo &); // constructor copia
		~CityInfo(); // destructor
		CityInfo & operator =(const CityInfo &); // sobrecarga operador =
		bool operator!=(const CityInfo &);
		bool operator==(const CityInfo &);
		vector<int> getInterestPoints() const;
		bool hasAirport() const;
		string getMostImportant() const;
		string getMostFrequent() const;
		void setMostImportant(string name);








}; // las clases se terminan siemper con ;

#endif // acordarse de ponerlo siempre