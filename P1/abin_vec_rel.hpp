#ifndef ABIN_VEC_REL_H
#define ABIN_VEC_REL_H

#include <cassert>
#include <cstddef>
#include <vector>

template <typename T>
class AbinVecRel {
public:
    typedef size_t nodo;
    static const nodo NODO_NULO;

    explicit AbinVecRel(size_t maxNodos = 0);

    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHijoDrcho(nodo n, const T& e);
    bool vacio() const;
    size_t tama() const;

    const T& elemento(nodo n) const;
    T& elemento(nodo n);

    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;

private:
    std::vector<T> nodos;
    size_t numNodos;
};

// Definición del nodo nulo
template <typename T>
const typename AbinVecRel<T>::nodo AbinVecRel<T>::NODO_NULO{SIZE_MAX};

template <typename T>
AbinVecRel<T>::AbinVecRel(size_t maxNodos) : nodos(maxNodos), numNodos(0) {}

template <typename T>
inline void AbinVecRel<T>::insertarRaiz(const T& e) {
    assert(vacio());
    nodos[0] = e;
    numNodos = 1;
}

template <typename T>
inline void AbinVecRel<T>::insertarHijoIzqdo(nodo n, const T& e) {
    assert(n < nodos.size());
    nodo i = 2 * n + 1;
    nodos[i] = e;
    ++numNodos;
}

template <typename T>
inline void AbinVecRel<T>::insertarHijoDrcho(nodo n, const T& e) {
    assert(n < nodos.size());
    nodo i = 2 * n + 2;
    nodos[i] = e;
    ++numNodos;
}

template <typename T>
inline bool AbinVecRel<T>::vacio() const {
    return numNodos == 0;
}

template <typename T>
inline size_t AbinVecRel<T>::tama() const {
    return numNodos;
}

#endif // ABIN_VEC_REL_H
