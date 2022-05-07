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
        AB<Key>::setRaiz(k, NULL, NULL);
    } else {
        insertarEquilRama(k, AB<Key>::getRaiz());
    }
    return false; //
}

template<class Key>
void ABE<Key>::insertarEquilRama(const Key& k, NodoB<Key> *nodo) {
    int tam_izq = nodo.AB<Key>::Tamano(nodo.AB<Key>::getRaiz()->getNodoIzq());
    int tam_der = nodo.AB<Key>::Tamano(nodo.AB<Key>::getRaiz()->getNodoDer());

    if (tam_izq <= tam_der) {
        if (AB<Key>::getRaiz()->getNodoIzq() != NULL) {
            insertarEquilRama(k, nodo.AB<Key>::getRaiz()->getNodoIzq());
        } else {
            nodo.AB<Key>::getRaiz()->getNodoIzq() = new NodoB<Key> (k, NULL, NULL);
        }
    } else {
        if (nodo.AB<Key>::getRaiz()->getNodoDer() != NULL){
            insertarEquilRama(k, nodo.AB<Key>::getRaiz()->getNodoDer());
        } else {
            nodo.AB<Key>::getRaiz()->getNodoDer() = new NodoB<Key> (k, NULL, NULL);
        }
    }
}

template<class Key>
bool ABE<Key>::buscar (const Key& k) {
    return busqueda(AB<Key>::getRaiz(), k);
}

template<class Key>
bool ABE<Key>::busqueda (const Key& k, NodoB<Key> *nodo) {
    if (nodo == NULL) {
        return false;
    } else if (k == nodo.AB<Key>::getRaiz()->getDato()) {
        return true;
    } else if (k < nodo.AB<Key>::getRaiz()->getDato()) {
        if (busqueda(k, nodo.AB<Key>::getRaiz()->getNodoIzq())) {
            return true;
        } else if (busqueda(k, nodo.AB<Key>::getRaiz()->getNodoDer())){
            return true;
        }
    }
    return false;
}



