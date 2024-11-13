// DNI 29577325S GUILLEN HERNANDEZ, ARIADNA
#include "List.h"

List::List(){ // constructor de List que inicializa los punteros a NULL y error con el conructor por defecto de City

    error = City();
    head = NULL;
    tail = NULL;
}

bool List::isEmpty() const{

    bool var_devolver = false;

    if(head==NULL){ // en caso de que la lista este vacia, el booleano pasa a ser verdadero
        var_devolver = true;
    }
    
    return var_devolver;
}

int List::range() const{

    Node *auxiliar; // se crea un nodo auxiliar para recorrer toda la lista
    int var_devolver = -1; // por defecto devueve -1

    for(auxiliar = head; auxiliar != NULL; auxiliar = auxiliar->next){

        if(auxiliar->distance > var_devolver){ // en caso de que la distancia que haya almacenada en el nodo sea mayor que la que tenemos actualmente en la variable a devolver

            var_devolver = auxiliar->distance; // se actualiza la distancia mayor
        }
    }

    return var_devolver;
}

void List::add(City ciudad, int distancia){ 
    // se crea un nuevo nodo con la ciudad y la distancia pasada por parametro
    Node *nuevo_nodo = new Node(ciudad);
    nuevo_nodo->distance = distancia;
    Node *auxiliar;
    bool apto_para_anyadir = true;

    for(auxiliar = head; auxiliar != NULL; auxiliar = auxiliar->next){

        if(auxiliar == nuevo_nodo){  // en caso de que la ciudad ya exista, no se anyade

            apto_para_anyadir = false;
        }
    }

    if(apto_para_anyadir == true){ // en caso de que sea apto, se anyade
        for(auxiliar = head; auxiliar != NULL; auxiliar = auxiliar->next){


        }

    }
}

City List::remove(string cityName){

    City ciudad_a_devolver = error; // en caso de que no encontrar la ciudad, se devuelve error
    City ciudad_auxiliar;
    string nombre_ciudad;
    Node *auxiliar = head; // se empieza a buscar por la cabeza (head) de la lista
 
    for(auxiliar; auxiliar!=NULL; auxiliar = auxiliar->next){ // se recorre la lista

        ciudad_auxiliar = auxiliar->city;
        nombre_ciudad = ciudad_auxiliar.getName(); // primero se consigue el nombre de la ciudad para comparar
        // en caso de que se encuentre la ciudad, se almacena para devolverla y despues se elimina
        if(nombre_ciudad == cityName){

            ciudad_a_devolver = ciudad_auxiliar;

            //ahora pueden ocurrir tres cosas 1. que se borre la head, 2. que se borre la tail, 3. que se borre por enmedio
            // borrado en la head
            if(auxiliar==head){
                if(auxiliar!=NULL){ // se comprueba que no es NULL ya
                
                    head = head->next; // se cambia el primer valor de la lista por el siguiente que haya

                    if(head == NULL){ // en caso de que ya no queden elementos en la lista, se actualiza el valor del tail tambien a NULL
                    
                        tail = NULL;
                    }

                    delete auxiliar; // y se borra el nodo
                }
            }

            // borrado en el tail
            if(auxiliar==tail){
                if(auxiliar!=NULL){

                    tail = tail->prev;

                     if(tail == NULL){ // en caso de que ya no queden elementos en la lista, se actualiza el valor del head tambien a NULL
                    
                        head = NULL;
                    }

                    delete auxiliar;
                }
            }

            //borrado genera, que no es ni head ni tail
            if(auxiliar!=head && auxiliar!=tail){
                if(auxiliar!=NULL){
                    // se juntan los nodos adyaccentes de auxiliar para que la Lista se junte
                    auxiliar->prev = auxiliar->next;
                    auxiliar->next = auxiliar->prev; 

                    delete auxiliar;
                }
            }
        }
    }

    return ciudad_a_devolver;
}

int List::removeFromDistance(int distance){

    int numero_ciudades_eliminada = 0;

    Node *auxiliar = head; // se empieza a recorrer la lista desde el primer elemento
    int distancia_deCity;
    City ciudad_borrada;
    string nombre_ciudad;

    for(auxiliar; auxiliar!=NULL; auxiliar = auxiliar->next){

        distancia_deCity = auxiliar->distance; // se almacena la distancia de la ciudad para poder usarla en la comparacion

        if(distancia_deCity >= distance){ // en caso de que sea mayor o igual, se borra

            ciudad_borrada = auxiliar->city; // se conigue la ciudad que hay en este nodo
            nombre_ciudad = ciudad_borrada.getName(); // y se consigue su nombre para poder usarlo en el metodo remove()
            auxiliar = auxiliar->prev; // se retrocede un nodo para que no se salte ningun elemento de la lista
            remove(nombre_ciudad); // se usa el metodo remove pasandole por parametro el nombre de la ciudad que hay que borrar
            
            numero_ciudades_eliminada = numero_ciudades_eliminada + 1; // se incremente el contador de ciudades borradas;
        }
    }
}

City &List::get(int index){

    City* devolver = &error;
    Node *auxiliar = head;

    if(auxiliar!=NULL){ // en caso de que la lista no este vacia, se sigue con el metodo

        for(auxiliar; auxiliar!=NULL; auxiliar = auxiliar->next){ // se recorre la lista entera


        }
    }

    return *devolver;
}

void List::reversePrint() const{

    if(head !=NULL){ // se comprueba que la lista no esta vacia
        Node *auxiliar = tail; // se empieza a imprimir desde el ultimo elemento de la lista

        for(auxiliar; auxiliar!=NULL; auxiliar = auxiliar->prev){

            cout << auxiliar << endl;
        }
    }
}

ostream & operator <<(ostream &os, const List &c){

    if(c.head !=NULL){ // se comprueba que la lista no esta vacia
        List::Node *auxiliar = c.head; // se empieza a imprimir desde el primer elemento de la lista

        for(auxiliar; auxiliar!=NULL; auxiliar = auxiliar->next){

            os << auxiliar << endl;
        }
    }

    return os;
}

int List::tamanyo(){

    Node *auxiliar = head;
    int contador = 0;

    if(head!=NULL && tail!=NULL){

        for(auxiliar; auxiliar!=NULL; auxiliar = auxiliar->next){

            contador = contador + 1;
        }
    }

    return contador;
}