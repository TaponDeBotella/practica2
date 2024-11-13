// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#include "Map.h"

Map::Map(){ // se inicializan las variables, porque en el .h solo se crean y se indican que existen, pero no se inicializan aun

    map = vector<vector<char>>();
    cities = vector<City>();
}

void Map::read(string filename){
    ifstream fichero(filename);

    if(!fichero.is_open()){ // se comprueba que el fichero no tiene problemas
        cerr<< "ERROR en lectura de fichero" << endl; // si tiene problemas se cierra
    }else{ // si no, se procede

        // primero se borra toda la informacion del mapa
        map.clear();

        string linea; // se crea la variable para almacenar el texto
        string token;
        string nombreCiud;
        int i = 1;
        vector<char> roww;
        vector<char> colu;
        vector<int> inform = {0,0,0,0};
        string mi;
        bool ar = false;
        vector<int> vcord;
        bool vuelta = false;
        
        while(getline(fichero, linea)){

            if(i==1){  // primero se crea el mapa
                while(linea!="<CIUDAD>"){ // primero se lee el mapa, hasta que se llegue a la ciudad
                    



                    for(int x=0;x<(int)linea.size();x++){ // se recorre el vector map tantas veces como caracteres tenga linea
                   
                        roww.push_back(linea[x]); // rellenamos la fila que luego se va a insertar en el mapa
                    }

                    map.push_back(roww); // se le mete al mapa la fila de caracteres obtenidos
                    roww.clear();
                    getline(fichero, linea);               
                }
                i=0;
            } 


            if(linea=="<CIUDAD>" || vuelta==true){ // PARTE DE LA CIUDAD

                if(vuelta==false){
                  getline(fichero,linea); // obtenemos el nombre
                }
                nombreCiud = linea;

                getline(fichero, linea); // obtenemos las coordenadas
                stringstream iss(linea); // vamos a separarla por huecos blancos
                string token;                

                while(iss >> token){ 

                    vcord.push_back(stoi(token));
                } 
                getline(fichero, linea);  
                vuelta = false;                                             
            }

            if(linea=="<INFO>"){ // ahora obtenemos 
                // orden de informacion: museo, monuments, hotel, restauran, airport, *mostimportant
                while(getline(fichero, linea) && linea!="<CIUDAD>"){
                    if(linea!="aeropuerto"){ // como el aeropuerto va el ultimo, lo controlo
                                
                        stringstream iss(linea); // vamos a separarla por huecos blancos
                        string nombre;
                        int inf;

                        iss >> nombre; // almaceno de que parte es la informacion
                        iss >> inf; // y el numero que la acompanya

                        if(nombre=="museo"){ // si hay informacion del museo, se almacena
                            inform[0] = inf;
                        }

                        if(nombre=="monumento"){
                            inform[1] = inf;
                        }

                        if(nombre=="hotel"){
                            inform[2] = inf;
                        }

                        if(nombre=="restaurante"){
                            inform[3] = inf;
                        }

                        if(linea[0]=='*'){ // en caso de que sea el most important
                            mi = linea;
                        }                          

                    }else{ // en caso de que tenga aeropuerto

                        ar = true;
                    }
                }
                vuelta = true;
               
                City c(nombreCiud);
                c.setCoord(vcord[0], vcord[1], map);
                CityInfo cifo(inform[0], inform[1], inform[2], inform[3], ar); // se crea el CityInfo con los datos del fichero
                cifo.setMostImportant(mi); // le pongo el mostimportant
                c.setInfo(cifo); // le meto la CityInfo al City

                if(c.getId()>=0){
                    cities.push_back(c); // anyado al vector de City la que se acaba de crear
                    inform = {0,0,0,0};
                    vcord.clear();
                    mi="";
                    ar = false;
                }
            }                     
        }
    }
}

vector<vector<char>> &Map::getMap(){

    return map;
}

vector<City> &Map::getCities(){

    return cities;
}

char Map::getMapPosition(Coordinates coord) const{

    int r = coord.getRow();
    int c = coord.getCol();
    char ret;
    ret = 'X';

    if(coord.validCoord()==true){ // se comprueba que es valida
        if(r>=0 && r<=(int)map.size()){ // se comprueba si esta dentro del mapa
            if(c>=0 && c<=(int)map[1].size()){

                ret = map[r][c];
            }
        }
    }
    return ret;
}

ostream & operator <<(ostream &os, const Map &c){

    for(int x=0; x<(int)c.map.size(); x++){ // se recorre las filas
        for(int y=0; y<(int)c.map[x].size(); y++){ // y las columnas
            Coordinates coord(x,y); // se crean las coordenadas de cada una de las casillas
            char car = c.getMapPosition(coord); // conseguimos cada uno de los caracteres que forman el mapa

            os << car; // y se muestra por pantalla
        }
        os << endl; // salro de linea al final de cada columna
    }

    for(int i=0; i<(int)c.cities.size(); i++){

        City cit = c.cities[i];
        os << cit;
    }

    return os; // y se devuelve el resultado
}
