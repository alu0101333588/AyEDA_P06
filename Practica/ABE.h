#pragma once
#include "AB.h"
#include <iostream>
#include <fstream>
//#include "NodoB.h"

//template<class Key> class NodoB;

template<class Key>
class ABE : public AB<Key> {
    public:
        bool insertar (const Key& k);
        bool buscar (const Key& k);
        void insertarEquilRama(const Key& k, NodoB<Key> *nodo);
        bool busqueda (const Key& k, NodoB<Key> *nodo);
};

template<class Key>
bool ABE<Key>::insertar (const Key& k) {
    if (AB<Key>::getRaiz() == NULL) {
        //AB<Key>::getRaiz() = new NodoB<Key> (k);
        AB<Key>::setRaiz3(k);
    } else {
        insertarEquilRama(k, AB<Key>::getRaiz());
        std::cout << "PROTOCOLO 2" << std::endl;
    }
    return true; //
}

template<class Key>
void ABE<Key>::insertarEquilRama(const Key& k, NodoB<Key> *nodo) {
    int tam_izq = AB<Key>::Tamano(nodo->getNodoIzq());
    int tam_der = AB<Key>::Tamano(nodo->getNodoDer());

    if (tam_izq <= tam_der) {
        if (AB<Key>::getRaiz()->getNodoIzq() != NULL) {
            insertarEquilRama(k, nodo->getNodoIzq());
        } else {
            //nodo->getNodoIzq() = new NodoB<Key> (k);
            nodo->setNodo(nodo->getNodoIzq(), k);
        }
    } else {
        if (nodo->getNodoDer() != NULL){
            insertarEquilRama(k, nodo->getNodoDer());
        } else {
            //nodo->getNodoDer() = new NodoB<Key> (k);
            nodo->setNodo(nodo->getNodoDer(), k);
        }
    }
}

template<class Key>
bool ABE<Key>::buscar (const Key& k) {
    return busqueda(k, AB<Key>::getRaiz());
}

template<class Key>
bool ABE<Key>::busqueda (const Key& k, NodoB<Key> *nodo) {
    if (nodo == NULL) {
        return false;
    } else if (k == nodo->getDato()) {
        return true;
    } else if (k < nodo->getDato()) {
        if (busqueda(k, nodo->getNodoIzq())) {
            return true;
        } else if (busqueda(k, nodo->getNodoDer())){
            return true;
        }
    }
    return false;
}



