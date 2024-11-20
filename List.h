// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#ifndef LIST_H  
#define LIST_H 

#include "Map.h"
#include <iostream>
using namespace std;

class List{ // se crea la clase list, y dentro tendra el nodo

    private:
    #ifndef NODE_H  
    #define NODE_H 
    class Node{ // se crea la clase node dentro de la clase list

        friend ostream & operator <<(ostream &os, const Node &c){

           City ciudad = c.city;
           int distancia = c.distance;

           os << ciudad.getName() << " (" << distancia << ") " ;
           return os;
        } 

        public:
        City city;
        int distance;
        Node *next;
        Node *prev;
        
        Node(City ciudad){

            city = City(ciudad); // se inicializa la ciudad con la que se ha pasado por parametro
            distance = -1; // el resto de variables se inicializan con valores por defecto
            next = NULL;
            prev = NULL;
        } 

        bool operator ==(const Node &nodo){

            bool var_devolver = true;
            City ciudad_nodo = nodo.city;
            string nombre_cuidad = ciudad_nodo.getName();

            if(nodo.distance != distance){
                var_devolver = false;
            }

            if(nombre_cuidad != city.getName()){
                var_devolver = false;
            }

            return var_devolver;
        }
    }; 
    #endif 

    friend ostream & operator <<(ostream &os, const List &c);

    // variables privadas de la clase List
    Node *head;
    Node *tail;
    City error;

    public: // metodos de List

    List(); // constructor
    bool isEmpty() const;
    int range() const;
    void add(City city, int distance);
    City remove(string cityName);
    int removeFromDistance(int distance);
    City &get(int index);
    void reversePrint() const;
    int tamanyo(); // metodo que devuelve el size de la lista. Devuelve 0 si la lista esta vacia
    
};
#endif