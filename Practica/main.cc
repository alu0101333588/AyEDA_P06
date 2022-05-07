#include <iostream>
#include "NodoB.h"
#include "AB.h"

using Key = int;

int main() {
    int opcion = -1;
    AB<Key> *arbol = new AB<Key>;
    std::cout << "Árbol vacío" << std::endl;
    arbol->Imprimir();

    Key Clave;

    while (opcion != 0) {
        std::cout << "[0] Salir" << std::endl;
        std::cout << "[1] Insertar clave" << std::endl;
        std::cout << "[2] Buscar clave" << std::endl;
        std::cout << "[3] Mostrar árbol inorden" << std::endl;

        std::cin >> opcion;

        switch (opcion){
        case 1:
            std::cout << "Clave (Insertar): ";
            std::cin >> Clave;
            std::cout << "Insertar: " << Clave << std::endl;
            if (arbol->insertar(Clave)) {
                arbol->Imprimir();
            } else {
                std::cout << "ELEMENTO REPETIDO" << std::endl;
            }
            break;

        case 2: 
            std::cout << "Clave (Busqueda): ";
            std::cin >> Clave;
            std::cout << "Busqueda [" << Clave << "]: ";
            if (arbol->buscar(Clave)) {
                std::cout << "MATCH" << std::endl;
            } else {
                std::cout << "NO ENCONTRADO" << std::endl;
            }
            break;

        case 3:
            arbol->inorden();
            break;
        
        default:
            break;
        }
    }

    return 0;
    

}
