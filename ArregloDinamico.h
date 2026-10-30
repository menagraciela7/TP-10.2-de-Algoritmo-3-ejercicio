#ifndef ARREGLO_DINAMICO_H
#define ARREGLO_DINAMICO_H

#include <cstddef>
#include <stdexcept>

namespace EstructurasDatos {

    template <typename T>
    class ArregloDinamico {
    private:
        T* datos;
        std::size_t capacidad;
        std::size_t tamanio;

        void redimensionar(std::size_t nuevaCapacidad);

    public:
        ArregloDinamico();
        ~ArregloDinamico();

        void agregar(const T& elemento);
        void ordenarAscendente(); // Implementa el método de ordenamiento Bubble Sort
        
        T obtener(std::size_t indice) const;
        std::size_t obtenerTamanio() const;
    };

} // namespace EstructurasDatos

// Dado que es una clase plantilla (template), la implementación de las funciones 
// miembro debe estar disponible en el archivo de cabecera o incluirse al final.
#include "ArregloDinamico.cpp"

#endif // ARREGLO_DINAMICO_H
