#include <iostream>
#include "abin.hpp"
#include "abin_E-S.h"

#include <iostream>
#include <locale> // Incluir la librería para trabajar con tildes

int main(){
    std::locale::global(std::locale("")); // Establecer la configuración regional para trabajar con tildes
    Abin<int> arbol;
    rellenarAbin(arbol, -1); // Rellena el árbol con valores, -1 indica nodo nulo
    std::cout << "presiona cualquier tecla para continuar...";
    std::cout << "\n" << std::endl;
    imprimirAbin(arbol); // Imprime el árbol
    std::cin.ignore(); // Pausa el programa hasta que se presione una tecla
    std::cin.ignore(); // Pausa el programa hasta que se presione una tecla

    return 0;
}