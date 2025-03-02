#ifndef ABIN_H
#define ABIN_H

#include <cassert>
#include <cstddef>   // size_t
#include <utility>   // swap

template <typename T> 
class Abin {
   struct celda;   // Declaración adelantada privada

public:
   typedef celda* nodo;
   static const nodo NODO_NULO;

   Abin();
   void insertarRaiz(const T& e);
   void insertarHijoIzqdo(nodo n, const T& e);
   void insertarHijoDrcho(nodo n, const T& e);
   void eliminarHijoIzqdo(nodo n);
   void eliminarHijoDrcho(nodo n);
   void eliminarRaiz();
   bool vacio() const;
   size_t tama() const;
   const T& elemento(nodo n) const;
   T& elemento(nodo n);
   nodo raiz() const;
   nodo padre(nodo n) const;
   nodo hijoIzqdo(nodo n) const;
   nodo hijoDrcho(nodo n) const;

   Abin(const Abin& A);               // Constructor de copia
   Abin& operator =(const Abin& A);   // Operador de asignación
   ~Abin();                           // Destructor

private: 
   struct celda {
      T elto;
      nodo padre, hizq, hder;
   };

   nodo r;          // Raíz del árbol
   size_t numNodos; // Tamaño del árbol

   nodo copiar(nodo n);
   void destruir(nodo& n);
}; 

// Definición del nodo nulo
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO{nullptr};

// Implementación de los métodos

template <typename T>
inline Abin<T>::Abin() : r{NODO_NULO}, numNodos{0} {}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e) {
   assert(vacio());
   r = new celda{e};
   numNodos = 1;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e) {
   assert(n != NODO_NULO);
   assert(n->hizq == NODO_NULO);
   n->hizq = new celda{e, n};
   ++numNodos;
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e) {
   assert(n != NODO_NULO);
   assert(n->hder == NODO_NULO);
   n->hder = new celda{e, n};
   ++numNodos;
}

template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n) {
   assert(n != NODO_NULO);
   assert(n->hizq != NODO_NULO);
   assert(n->hizq->hizq == NODO_NULO && n->hizq->hder == NODO_NULO);
   delete n->hizq;
   n->hizq = NODO_NULO;
   --numNodos;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n) {
   assert(n != NODO_NULO);
   assert(n->hder != NODO_NULO);
   assert(n->hder->hizq == NODO_NULO && n->hder->hder == NODO_NULO);
   delete n->hder;
   n->hder = NODO_NULO;
   --numNodos;
}

template <typename T>
inline void Abin<T>::eliminarRaiz() {
   assert(numNodos == 1);
   delete r;
   r = NODO_NULO;
   numNodos = 0;
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
inline const T& Abin<T>::elemento(nodo n) const {
   assert(n != NODO_NULO);
   return n->elto;
}

template <typename T>
inline T& Abin<T>::elemento(nodo n) {
   assert(n != NODO_NULO);
   return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const {
   return r;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::padre(nodo n) const {
   assert(n != NODO_NULO);
   return n->padre;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const {
   assert(n != NODO_NULO);
   return n->hizq;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const {
   assert(n != NODO_NULO);
   return n->hder;
}

template <typename T>
inline Abin<T>::Abin(const Abin& A) : Abin{} {
   r = copiar(A.r);
   numNodos = A.numNodos;
}

template <typename T>
inline Abin<T>& Abin<T>::operator =(const Abin& A) {
   Abin B{A};
   std::swap(r, B.r);
   std::swap(numNodos, B.numNodos);
   return *this;
}

template <typename T>
inline Abin<T>::~Abin() {
   destruir(r);
}

template <typename T>
void Abin<T>::destruir(nodo& n) {
   if (n != NODO_NULO) {
      destruir(n->hizq);
      destruir(n->hder);
      delete n;
      n = NODO_NULO;
   }
}

template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n) {
   nodo m = NODO_NULO;
   if (n != NODO_NULO) {
      Abin A;
      A.r = new celda{n->elto};
      A.r->hizq = copiar(n->hizq);
      if (A.r->hizq != NODO_NULO) A.r->hizq->padre = A.r;
      A.r->hder = copiar(n->hder);
      if (A.r->hder != NODO_NULO) A.r->hder->padre = A.r;
      m = A.r;
      A.r = NODO_NULO;
   }
   return m;
}

#endif // ABIN_H
