#pragma once
#include <iostream>

template<class Key>
class NodoB {
    public:
        NodoB (const Key& dat, NodoB *izq = NULL, NodoB *der = NULL) : dato_(dat), izdo_(izq), dcho_(der) {}

        void setNodo(Key k);
        // NodoB<Key> *nodo,
        //NodoB* setNodo2(Key valor);

        NodoB* getNodoIzq() {return izdo_;}
        NodoB* getNodoDer() {return dcho_;}
        NodoB* getNodoCen() {return centro_;}

        Key getDato() {return dato_;}

        void setDato(Key dato) {dato_ = dato;}

        void setNodoIz(Key k);
        void setNodoDe(Key k);
        void setNodoCe(Key k);
        void inordenNodo();
        void inordenNodo2(NodoB<Key> *nodo);


    private:
        Key dato_; 
        NodoB *izdo_;
        NodoB *centro_;
        NodoB *dcho_;

};

template<class Key>
void NodoB<Key>::setNodo (Key k) {
    dato_ = new NodoB<Key> (k);
}

template<class Key>
void NodoB<Key>::setNodoIz(Key k) {
    izdo_ = new NodoB<Key> (k);
}

template<class Key>
void NodoB<Key>::setNodoDe(Key k) {
    dcho_ = new NodoB<Key> (k);
}

template<class Key>
void NodoB<Key>::setNodoCe(Key k) {
    centro_ = new NodoB<Key> (k);
}

template<class Key>
void NodoB<Key>::inordenNodo() {
    inordenNodo2(this);
    std::cout << std::endl;
}

template<class Key>
void NodoB<Key>::inordenNodo2(NodoB<Key> *nodo) {
    if (nodo == NULL) {
        return;
    }

    inordenNodo2(nodo->getNodoIzq());
    inordenNodo2(nodo->getNodoCen());
    std::cout << "[" << nodo->getDato() << "] ";    
    inordenNodo2(nodo->getNodoDer());
}