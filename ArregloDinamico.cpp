#ifdef ARREGLO_DINAMICO_H // Asegura que solo se procese si se incluye desde el .h

namespace EstructurasDatos {

    template <typename T>
    ArregloDinamico<T>::ArregloDinamico() : datos(nullptr), capacidad(0), tamanio(0) {}

    template <typename T>
    ArregloDinamico<T>::~ArregloDinamico() {
        delete[] datos;
    }

    template <typename T>
    void ArregloDinamico<T>::redimensionar(std::size_t nuevaCapacidad) {
        T* nuevoArreglo = new T[nuevaCapacidad];
        for (std::size_t i = 0; i < tamanio; ++i) {
            nuevoArreglo[i] = datos[i];
        }
        delete[] datos;
        datos = nuevoArreglo;
        capacidad = nuevaCapacidad;
    }

    template <typename T>
    void ArregloDinamico<T>::agregar(const T& elemento) {
        if (tamanio >= capacidad) {
            std::size_t nuevaCapacidad = (capacidad == 0) ? 1 : capacidad * 2;
            redimensionar(nuevaCapacidad);
        }
        datos[tamanio] = elemento;
        ++tamanio;
    }

    template <typename T>
    void ArregloDinamico<T>::ordenarAscendente() {
        if (tamanio < 2) return;
        
        // Algoritmo Bubble Sort adaptado para la entidad de abstracción
        for (std::size_t i = 0; i < tamanio - 1; ++i) {
            for (std::size_t j = 0; j < tamanio - i - 1; ++j) {
                if (datos[j] > datos[j + 1]) {
                    T temporal = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temporal;
                }
            }
        }
    }

    template <typename T>
    T ArregloDinamico<T>::obtener(std::size_t indice) const {
        if (indice >= tamanio) {
            throw std::out_of_range("Índice fuera de los límites del arreglo.");
        }
        return datos[indice];
    }

    template <typename T>
    std::size_t ArregloDinamico<T>::obtenerTamanio() const {
        return tamanio;
    }

} // namespace EstructurasDatos

#endif
