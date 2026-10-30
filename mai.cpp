#include <iostream>
#include "ArregloDinamico.h"

int main() {
    // Uso explícito del espacio de nombres definido
    EstructurasDatos::ArregloDinamico<double> listaNumeros;
    int cantidadElementos = 0;

    std::cout << "Ingrese la cantidad de números (N) a almacenar: ";
    if (!(std::cin >> cantidadElementos) || cantidadElementos <= 0) {
        std::cerr << "Entrada inválida. Debe ingresar un número entero positivo." << std::endl;
        return 1;
    }

    for (int i = 0; i < cantidadElementos; ++i) {
        double valor;
        std::cout << "Ingrese el número [" << i + 1 << "]: ";
        std::cin >> valor;
        listaNumeros.agregar(valor);
    }

    // Delegación de responsabilidades: la propia lista sabe cómo ordenarse
    listaNumeros.ordenarAscendente();

    std::cout << "\nLos números ordenados en orden ascendente son:\n";
    for (std::size_t i = 0; i < listaNumeros.obtenerTamanio(); ++i) {
        std::cout << listaNumeros.obtener(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
