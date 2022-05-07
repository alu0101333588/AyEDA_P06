#pragma once
#include <iostream>

template<class Key>
class NodoB {
    public:
        NodoB (const Key& dat, NodoB *izq = NULL, NodoB *der = NULL) : dato_(dat), izdo_(izq), dcho_(der) {}

        NodoB* getNodoIzq() {return izdo_;}
        NodoB* getNodoDer() {return dcho_;}

        Key* getDato() {return dato_;}

        void setNodoIzq(NodoB izq) {izdo_ = izq;}
        void setNodoDer(NodoB der) {dcho_ = der;}
        void setDato(Key dato) {dato_ = dato;}

    private:
        Key dato_; 
        NodoB *izdo_;
        NodoB *dcho_;

};