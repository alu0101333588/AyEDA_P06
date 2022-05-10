#include <iostream>
#include "ABE.h"
#include "dummy.h"

//using Key = Dummy;
//using Key = int;

int main() {
    int opcion = -1;
    AB<Dummy>* arbol = new ABE<Dummy>;
    std::cout << "Árbol vacío" << std::endl;
    //arbol->AB<Key>::Imprimir();
    std::cout << arbol << std::endl;

    //Key Clave;
    Dummy Clave (5, 10); 
    //= {5, 10};
    //arbol->insertar(Clave);


    while (opcion != 0) {
        std::cout << "-------------------------" << std::endl;
        std::cout << "[0] Salir" << std::endl;
        std::cout << "[1] Insertar clave" << std::endl;
        std::cout << "[2] Buscar clave" << std::endl;
        std::cout << "[3] Mostrar árbol inorden" << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::cin >> opcion;

        switch (opcion){
        case 1:
            std::cout << "Clave (Insertar): ";
            std::cin >> Clave;
            std::cout << "Insertar: " << Clave << std::endl << std::endl;
            if (arbol->insertar(Clave)) {
                std::cout << arbol << std::endl;
                //arbol->Imprimir();
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
                std::cout << "NO EXISTE" << std::endl;
            }
            break;

        case 3:
            arbol->inorden();
            break;

        case 4:
            std::cout << arbol << std::endl;
            //arbol->Imprimir();
            break;
        
        case 5:
            try {
                arbol->eliminar(Clave);
            } catch (const char* message) {
                std::cerr << message << std::endl;
            }
            break;
        
        default:
            break;
        }
    }

    return 0;
    

}
