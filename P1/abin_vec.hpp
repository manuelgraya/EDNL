#ifndef ABIN_VEC_H
#define ABIN_VEC_H

#include <cassert>
#include <cstddef>   // size_t
#include <cstdint>   // SIZE_MAX
#include <utility>   // swap

template <typename T> 
class Abin {
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;

    explicit Abin(size_t maxNodos = 0);

    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHijoDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();

    bool vacio() const;
    size_t tama() const;
    size_t tamaMax() const;

    const T& elemento(nodo n) const;
    T& elemento(nodo n);

    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;

    Abin(const Abin& A);               // Constructor de copia
    Abin& operator=(const Abin& A);    // Operador de asignación
    ~Abin();                           // Destructor

private:
    struct celda {
        T elto;
        nodo padre, hizq, hder;
    };

    celda* nodos;      // Vector de celdas
    size_t maxNodos;   // Tamaño del vector
    size_t numNodos;   // Tamaño del árbol
    nodo libre;        // Lista de celdas libres

    bool valido(nodo n) const;
};

// Definición del nodo nulo
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO{SIZE_MAX};

// Implementación de métodos

template <typename T>
Abin<T>::Abin(size_t maxNodos) : nodos{new celda[maxNodos]}, maxNodos{maxNodos}, numNodos{0} {
    if (maxNodos > 1) {
        libre = 1;
        for (nodo n = 1; n < maxNodos; ++n) {
            nodos[n].hizq = n + 1;  // Enlazamos celdas libres
            nodos[n].padre = NODO_NULO;  // Marcamos celda libre
        }
    }
}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e) {
    assert(maxNodos > 0);
    assert(vacio());
    nodos[0] = {e, NODO_NULO, NODO_NULO, NODO_NULO};
    numNodos = 1;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e) {
    assert(tama() < tamaMax());
    assert(valido(n));
    assert(nodos[n].hizq == NODO_NULO);
    
    nodo hizqdo = libre;
    libre = nodos[libre].hizq;

    nodos[n].hizq = hizqdo;
    nodos[hizqdo] = {e, n, NODO_NULO, NODO_NULO};

    ++numNodos;
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e) {
    assert(tama() < tamaMax());
    assert(valido(n));
    assert(nodos[n].hder == NODO_NULO);

    nodo hdrcho = libre;
    libre = nodos[libre].hizq;

    nodos[n].hder = hdrcho;
    nodos[hdrcho] = {e, n, NODO_NULO, NODO_NULO};

    ++numNodos;
}

template <typename T>
inline bool Abin<T>::vacio() const {
    return numNodos == 0;
}

template <typename T>
inline size_t Abin<T>::tama() const {
    return numNodos;
}

template <typename T>
inline size_t Abin<T>::tamaMax() const {
    return maxNodos;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const {
    return vacio() ? NODO_NULO : 0;
}

template <typename T>
inline Abin<T>::~Abin() {
    delete[] nodos;
}

#endif // ABIN_VEC_H
