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
        void Impresion(NodoB<Key> *raiz);
        void ImpresionNivel(NodoB<Key> *raiz, int nivel);
        void Imprimir();
        void Podar(NodoB<Key>* nodo);

        bool Vacio(NodoB<Key> *nodo);
        bool Hoja(NodoB<Key> *nodo);

        int Tamano(NodoB<Key> *nodo);
        int Tamano();

        bool Equilibrado(NodoB<Key> *nodo);
        bool Equilibrado();
        const void inorden2(NodoB<Key> nodo) const;
        //void setNodoIz(Key k);
        //void setNodoDe(Key k);

    protected:
        void setRaiz2(Key nodo_padre, NodoB<Key> *nodo_hijo1 = NULL, NodoB<Key> *nodo_hijo2 = NULL);
        void setRaiz3(Key nodo_padre);
        void setRaiz(NodoB<Key> raiz) {raiz_ = raiz;}
        NodoB<Key>* getRaiz() {return raiz_;}
        NodoB<Key> getRaiz2() {return raiz_;}
        int Nivel (NodoB<Key> *nodo);
        

    private:
        NodoB<Key> *raiz_;
        
};

template<class Key>
void AB<Key>::setRaiz2(Key nodo_padre, NodoB<Key> *nodo_hijo1, NodoB<Key> *nodo_hijo2) {
    raiz_->setDato(nodo_padre);
    raiz_->setNodoDer(nodo_hijo1);
    raiz_->setNodoIzq(nodo_hijo2);
}

template<class Key>
void AB<Key>::setRaiz3(Key nodo_padre) {
    raiz_ = new NodoB<Key> (nodo_padre);
    //raiz_->setNodo(raiz_, nodo_padre);
}

template<class Key>
void AB<Key>::Podar(NodoB<Key>* nodo) {
    if (nodo == NULL) {
        return;
    }

    Podar(nodo->getNodoIzq());
    Podar(nodo->getNodoDer());
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
    if (!(nodo->getNodoDer()) && !(nodo->getNodoIzq())) {
        return true;
    }
    return false;
}

template<class Key>
void AB<Key>::Imprimir() {
    Impresion(raiz_);
    std::cout << std::endl;
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
int AB<Key>::Nivel (NodoB<Key> *nodo) {
    if (nodo == NULL) {
        return 0;
    } 

    int nivel_izq = Nivel(nodo->getNodoIzq());
    int nivel_der = Nivel(nodo->getNodoDer());

    if (nivel_der > nivel_izq) {
        return nivel_der++;
    } else {
        return nivel_izq++;
    }

}


template<class Key>
void AB<Key>::Impresion(NodoB<Key> *raiz) {
    std::cout << "Impresión..." << std::endl;

    int nivel = Nivel(raiz);
    NodoB<Key> *nodo(0);

    for (int i = 1; i <= nivel+1; i++) {
        std::cout << "Nivel " << i-1 << ": ";
        ImpresionNivel(raiz, i);
        std::cout << std::endl;
    }


}

template<class Key>
void AB<Key>::ImpresionNivel(NodoB<Key> *raiz, int nivel) {
    
    if (raiz == NULL) {
        if (nivel < 2) {
            std::cout << "[.]";
            return;
        } else {
            return;
        }
    }

    if (nivel == 1) {
        std::cout << "["<< raiz->getDato() << "]";

    } else if (nivel > 1) {
        ImpresionNivel(raiz->getNodoIzq(), nivel-1);
        ImpresionNivel(raiz->getNodoDer(), nivel-1);
    }
}


template<class Key>
void AB<Key>::inorden() const {
    //inorden2(getRaiz2());
}

template<class Key>
const void AB<Key>::inorden2(NodoB<Key> nodo) const {
    if (nodo == NULL) {
        inorden2(nodo->getRaiz()->getNodoIzq());
        std::cout << "[" << nodo-> getDato() << "]";
        inorden2(nodo->getNodoDer());

    }
}







template<class Key>
bool AB<Key>::Equilibrado(NodoB<Key> *nodo) {

    if (nodo == NULL) {
        return true;
    }
    int equilibrio = Tamano(nodo->izdo_) - Tamano(nodo->getNodoDer());
    if (equilibrio == 1) {
        return (Equilibrado(nodo->izdo_) && Equilibrado(nodo->getNodoDer()));
    } 

    return false;

}

template<class Key>
int AB<Key>::Tamano(NodoB<Key> *nodo) {
    if (nodo != NULL) {
        return (1 + Tamano(nodo->getNodoDer()) + Tamano(nodo->getNodoIzq()));
    }
    return 0;
}

template<class Key>
bool AB<Key>::Equilibrado() {
    if (raiz_ == NULL) {
        return true;
    }
    int equilibrio = Tamano(raiz_->getNodoIzq()) - Tamano(raiz_->getNodoDer());
    if (equilibrio == 1) {
        return (Equilibrado(raiz_->getNodoIzq()) && Equilibrado(raiz_->getNodoDer()));
    } 

    return false;
}

template<class Key>
int AB<Key>::Tamano() {
    if (raiz_ != NULL) {
        return (1 + Tamano(raiz_->getNodoDer()) + Tamano(raiz_->getNodoIzq()));
    }
    return 0;
}
