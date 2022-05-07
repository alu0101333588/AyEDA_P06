#pragma once
#include "NodoB.h"
#include <iostream>
#include <fstream>
//#include <queue>

//template<Class Key> class NodoB;

template<class Key>
class AB {
    public:
        AB () : raiz_(nullptr) {}
        ~AB() {Podar(raiz_);}

        virtual bool insertar (const Key& k) = 0;
        virtual bool buscar (const Key& k) = 0;
        void inorden() const;
        //friend std::ostream& operator<<(std::ostream& os, const NodoB<Key> *raiz);
        void Print(NodoB<Key> *raiz, int nivel);
        void Imprimir();
        void Podar(NodoB<Key>* &nodo);

        bool Vacio(NodoB<Key> *nodo);
        bool Hoja(NodoB<Key> *nodo);

        int Tamano(NodoB<Key> *nodo);
        int Tamano();

        bool Equilibrado(NodoB<Key> *nodo);
        bool Equilibrado();
        void inorden2(NodoB<Key> *nodo);

    protected:
        void setRaiz(Key nodo_padre, NodoB<Key> nodo_hijo1, NodoB<Key> nodo_hijo2);
        void setRaiz(NodoB<Key> raiz) {raiz_ = raiz;}
        NodoB<Key>* getRaiz() {return raiz_;}

    private:
        NodoB<Key> *raiz_;
        
};

template<class Key>
void AB<Key>::setRaiz(Key nodo_padre, NodoB<Key> nodo_hijo1, NodoB<Key> nodo_hijo2) {
    raiz_->setDato(nodo_padre);
    raiz_->setNodoDer(nodo_hijo1);
    raiz_->setNodoIzq(nodo_hijo2);
}

template<class Key>
void AB<Key>::Podar(NodoB<Key>* &nodo) {
    if (nodo == NULL) {
        return;
    }

    Podar(nodo->izdo_);
    Podar(nodo->dcho_);
    delete nodo;
    nodo = NULL;
}

template<class Key>
bool AB<Key>::Vacio(NodoB<Key> *nodo) {
    if (nodo == NULL) {
        return true;
    }
    return false;
}

template<class Key>
bool AB<Key>::Hoja(NodoB<Key> *nodo) {
    if (!(nodo->dcho_) && !(nodo->izdo_)) {
        return true;
    }
    return false;
}

template<class Key>
void AB<Key>::Imprimir() {
    Print(raiz_, 0);
}

/*template<class Key>
std::ostream& operator<<(std::ostream& os, const NodoB<Key> *raiz) {
    os << "PRUEBAS" << std::endl;
    return os;
    std::queue<Key> Q;
    std::queue<int> Q2;
    NodoB<Key> *nodo;
    int nivel, nivel_actual = 0;
    Q.push_back(raiz);
    Q2.push_back(0);

    while (!Q.empty()) {
        nodo = Q.front();
        nivel = Q2.front();
        Q.pop_front();
        Q2.pop_front();

        if (nivel > nivel_actual) {
            nivel_actual = nivel;
        }

        if (nodo != NULL) {
            Buscar(nodo);
            Q.push_back(nodo->izdo_);
            Q2.push_back(nivel+1);

            Q.push_back(nodo->dcho_);
            Q2.push_back(nivel+1);

        } 
    }
    
    // push_back(), pop_front(), back(), front(), size(), empty()


    //void printNivel(nodoB<Clave>* nodo, int nivel, nodoB<Clave>* nodo_anterior) {

}*/


template<class Key>
void AB<Key>::Print(NodoB<Key> *raiz, int nivel) {

    if (raiz == NULL) {
        if (nivel < 2) {
            std::cout << "[.]";
            return;
        } else {
            return;
        }
    }

    if (nivel == 1) {
        std::cout << "[";
        raiz->getDato();
        std::cout << "]";
    } else if (nivel > 1) {
        Print(raiz->izdo_, nivel-1);
        Print(raiz->dcho_, nivel-1);
    }

}


template<class Key>
void AB<Key>::inorden() const {
    inorden2(getRaiz());
}

template<class Key>
void AB<Key>::inorden2(NodoB<Key> *nodo) {
    if (nodo == NULL) {
        inorden2(nodo->getNodoIzq());
        std::cout << "[" << nodo-> getDato() << "]";
        inorden2(nodo->getNodoDer());

    }
}







template<class Key>
bool AB<Key>::Equilibrado(NodoB<Key> *nodo) {

    if (nodo == NULL) {
        return true;
    }
    int equilibrio = Tamano(nodo->izdo_) - Tamano(nodo->dcho_);
    if (equilibrio == 1) {
        return (Equilibrado(nodo->izdo_) && Equilibrado(nodo->dcho_));
    } 

    return false;

}

template<class Key>
int AB<Key>::Tamano(NodoB<Key> *nodo) {
    if (nodo != NULL) {
        return (1 + Tamano(nodo->dcho_) + Tamano(nodo->izdo_));
    }
    return 0;
}

template<class Key>
bool AB<Key>::Equilibrado() {
    if (raiz_ == NULL) {
        return true;
    }
    int equilibrio = Tamano(raiz_->izdo_) - Tamano(raiz_->dcho_);
    if (equilibrio == 1) {
        return (Equilibrado(raiz_->izdo_) && Equilibrado(raiz_->dcho_));
    } 

    return false;
}

template<class Key>
int AB<Key>::Tamano() {
    if (raiz_ != NULL) {
        return (1 + Tamano(raiz_->dcho_) + Tamano(raiz_->izdo_));
    }
    return 0;
}
