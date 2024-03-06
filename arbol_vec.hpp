#ifdef ARBOL_VEC_HPP
#define ARBOL_VEC_HPP

#include <iostream>

template <typename T> class ArbolVec {

    public:
        typedef size_t nodo;
        static const nodo NODO_NULO;
        
        explicit ArbolVec(size_t maxNodos) ; //Constructor, requiere ctor. t()

        /*El término EXPLICIT antes del nombre del constructor se utiliza para evitar las conversiones
        implícitas. En otras palabras, si tienes un constructor que puede ser llamado con un
        solo argumento, entonces ese constructor puede ser utilizado para convertir implícitamente
        un objeto de otro tipo al tipo de tu clase. Al usar explicit, estás diciendo que este
        constructor solo debe ser utilizado para la creación explícita de objetos,
        y no para la conversión implícita.*/

        void insertarRaiz(const T& e); //ponemos const para que la referencia no pueda afectar al ohjeto original

        /*El calificador CONST significa que esta función no puede modificar el objeto e.
        Esto es útil para garantizar que la función no cambie accidentalmente el estado del objeto.*/
        
        void insertarHijoIzqdo(nodo n, const T& e);
        void insertarHijoDrcho(nodo n, const T& e);

        /*Las funciones son insertarHijoIzqdo e insertarHijoDrcho, ambas toman dos argumentos: un objeto de tipo nodo llamado 
        n y una referencia constante al objeto e de tipo T.*/

        void eliminarHijoIzqdo(nodo n);
        void eliminarHijoDrcho(nodo n);
        void eliminarRaiz();
        bool arbolVacio() const;
        const T& elemento(nodo n) const; //devuelve el elemento de un nodo (versión constante)
        T& elemento(nodo n); //devuelve el elemento de un nodo (versión no constante)

        /*La primera función const T& elemento(nodo n) const devuelve una referencia constante a un objeto de tipo T. 
        Esto significa que no puede modificar el objeto T devuelto por esta función. Además, el calificador const al 
        final de la declaración de la función indica que esta es una función constante, lo que significa que no puede 
        modificar ningún miembro de datos no constante de la clase.

        La segunda función T& elemento(nodo n) devuelve una referencia a un objeto de tipo T. A diferencia de la primera función, 
        esta función te permite modificar el objeto T devuelto. Sin embargo, esta función no es constante, lo que significa que puede 
        modificar los miembros de datos de la clase.*/

        nodo raiz() const; //devuelve la raíz del árbol (versión constante)
        nodo padre(nodo n) const; //devuelve el padre de un nodo (versión constante)
        nodo hijoIzqdo(nodo n) const; //devuelve el hijo izquierdo de un nodo (versión constante)
        nodo hijoDrcho(nodo n) const; //devuelve el hijo derecho de un nodo (versión constante)
        ArbolVec(const ArbolVec<T>& a); //Constructor de copia
        ArbolVec<T>& operator =(const ArbolVec<T>& a); //Operador de asignación
        ~ArbolVec(); //Destructor

    private:
        struct celda {
            T elto; //elemento del nodo (de tipo T) 
            nodo padre, hizq, hder; //posiciones de los nodos padre, hijo izquierdo y derecho en el vector
        };
        celda *nodos; //vector de nodos
        size_t maxNodos; //tamaño del vector
        size_t nNodos; //número de nodos del árbol

};

//definicion del nodo nulo
template <typename T>
const typename ArbolVec<T>::nodo ArbolVec<T>::NODO_NULO (SIZE_MAX);
template <typename T>
inline Arbolvec<T>::ArbolVec(size_t maxNodos) : 
    nodos (new celda[maxNodos]),
    maxNodos (maxNodos),
    numNodos (0) {} 

template <typename T>
inline void ArbolVec<T>::insertarRaiz(const T& e){
    asssert(numNodos == 0); //el árbol debe estar vacío

    numNodos = 1; //el número de nodos del árbol es 1 (raiz)
    nodos[0].elto = e; //el elemento de la raíz es e
    nodos[0].padre = NODO_NULO; //la raíz no tiene padre
    nodos[0].hizq = NODO_NULO; //la raíz no tiene hijo izquierdo cuando se inserta
    nodos[0].hder = NODO_NULO; //la raíz no tiene hijo derecho cuando se inserta
}

template <typename T>
inline void ArbolVec::insertarHijoIzqdo(nodo n, const T& e){ 

    assert( n>= 0 && n < numNodos); //n debe ser un nodo válido
    assert(nodos[n].hizq == NODO_NULO); //n no debe tener hijo izquierdo
    assert(numNodos < maxNodos); //el árbol no debe estar lleno

    nodos[n].hizq = numNodos
    nodos[numNodos].elto = e; //el elemento del nuevo nodo es e
    nodos[numNodos].padre = n; //el padre del nuevo nodo es n
    nodos[numNodos].hizq = NODO_NULO;
    nodos[numNodos].hder = NODO_NULO; //los hijos del hijo insertado son nodo nulos
    ++numNodos; //incrementamos el número de nodos del árbol

}

template <typename T>
inline void ArbolVec::insertarHijoDrcho(nodo n, const T& e){
    assert( n>= 0 && n < numNodos); //n debe ser un nodo válido
    assert(nodos[n].hder == NODO_NULO); //n no debe tener hijo derecho
    assert (numNodos < maxNodos); //el árbol no debe estar lleno

    nodos[n].hder = numNodos
    nodos[numNodos].elto = e; //el elemento del nuevo nodo es e
    nodos[numNodos].padre = n; //el padre del nuevo nodo es n
    nodos[numNodos].hizq = NODO_NULO;
    nodos[numNodos].hder = NODO_NULO; //los hijos del hijo insertado son nodo nulos
    ++numNodos; //incrementamos el número de nodos del árbol

}

template <typename T>
void ArbolVec<T>::eliminarHijoIzqdo(nodo n){

    nodo hizqdo; //nodo hijo izquierdo de n

    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    hizqdo = nodos[n].hizq; //obtenemos el hijo izquierdo de n
    assert(hizqdo != NODO_NULO); //n debe tener hijo izquierdo
    assert(nodos[hizqdo].hizq == NODO_NULO && nodos[hizqdo].hder == NODO_NULO); //el hijo izquierdo de n debe ser una hoja

    if (hizqdo != numNodos-1)
    {
    // Mover el último nodo a la posición del hijo izqdo.nodos[hizqdo] = nodos[numNodos-1];
    // Actualizar la posición del hijo (izquierdo o derecho)// en el padre del nodo movido.
    if (nodos[nodos[hizqdo].padre].hizq == numNodos-1)nodos[nodos[hizqdo].padre].hizq = hizqdo;
    else
    nodos[nodos[hizqdo].padre].hder = hizqdo;
    // Si el nodo movido tiene hijos,
    // actualizar la posición del padre.
    if (nodos[hizqdo].hizq != NODO_NULO)
    nodos[nodos[hizqdo].hizq].padre = hizqdo;
    if (nodos[hizqdo].hder != NODO_NULO)
    nodos[nodos[hizqdo].hder].padre = hizqdo;
    }
    nodos[n].hizq = NODO_NULO;
        --numNodos;
}

template <typename T>
void ArbolVec<T>::eliminarHijoDrcho(nodo n){

    nodo hdrcho; //nodo hijo derecho de n

    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    hizqdo = nodos[n].hder; //obtenemos el hijo derecho de n
    assert(hdrcho != NODO_NULO); //n debe tener hijo derechod
    assert(nodos[hdrecho].hizq == NODO_NULO && nodos[hdrcho].hder == NODO_NULO); //el hijo derecho de n debe ser una hoja

    if (hdrcho != numNodos-1)
    {
    // Mover el último nodo a la posición del hijo izqdo.nodos[hizqdo] = nodos[numNodos-1];
    // Actualizar la posición del hijo (izquierdo o derecho)// en el padre del nodo movido.
    if (nodos[nodos[hdrcho].padre].hizq == numNodos-1)ç
    nodos[nodos[hdrcho].padre].hizq = hdrcho;
    else
    nodos[nodos[hdrcho].padre].hder = hdrcho;
    // Si el nodo movido tiene hijos,
    // actualizar la posición del padre.
    if (nodos[hdrcho].hizq != NODO_NULO)
    nodos[nodos[hdrcho].hizq].padre = hizqdo;
    if (nodos[hdrcho].hder != NODO_NULO)
    nodos[nodos[hdrcho].hder].padre = hizqdo;
    }
    nodos[n].hder = NODO_NULO;
        --numNodos;
}

template <typename T>
inline void ArbolVec<T>::eliminarRaiz(){
    assert(numNodos == 1); //el árbol debe tener un único nodo
    numNodos = 0; //el árbol se convierte en vacío
}

template <typename T>
inline bool ArbolVec<T>::arbolVacio() const{
    return (numNodos == 0);
}

template <typename T>
inline const T& ArbolVec<T>::elemento(nodo n) const{
    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    return nodos[n].elto; //devolvemos el elemento del nodo n
}

template <typename T>
inline typename ArbolVec<T>::nodo ArbolVec<T>::raiz() const{
    return (numNodos > 0) ? 0 : NODO_NULO; //la raíz es el primer nodo
}

template <typename T>
inline T& ArbolVec<T>::elemento(nodo n){
    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    return nodos[n].elto; //devolvemos el elemento del nodo n
}

template <typename T>
inline typename ArbolVec<T>::nodo ArbolVec<T>::raiz()const{
    return (numNodos > 0) ? 0 : NODO_NULO; //la raíz es el primer nodo
}

template <typename T>
inline typename ArbolVec<T>::nodo ArbolVec<T>::padre(nodo n) const{
    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    return nodos[n].padre; //devolvemos el padre del nodo n
}

template <typename T> inline 
typename ArbolVec<T>::nodo ArbolVec<T>::hijoIzqdo(nodo n) const{
    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    return nodos[n].hizq; //devolvemos el hijo izquierdo del nodo n
}

template <typename T> inline
typename ArbolVec<T>::nodo ArbolVec<T>::hijoDrcho(nodo n) const{
    assert(n >= 0 && n < numNodos); //n debe ser un nodo válido
    return nodos[n].hder; //devolvemos el hijo derecho del nodo n
}

template <typename T>
ArbolVec<T>::ArbolVec(const ArbolVec<T>& A): //Constructor de copia 
    nodos(new celda[A.maxNodos]),
    maxNodos(A.maxNodos),
    numNodos(A.numNodos){
        for (nodo n = 0; n < numNodos; n++){
            nodos[n] = A.nodos[n];
        }
    }

template <typename T>
inline ArbolVec<T>::~ArbolVec(){
    delete[] nodos; //liberamos la memoria dinámica reservada para el vector de nodos
}

template <typename T>
ArbolVec<T>& ArbolVec<T>::operator =(const ArbolVec<T>& A){

    if (this != &A) // Evitar autoasignación.
    {
    // Destruir el vector y crear uno nuevo si es necesario.if (maxNodos != A.maxNodos)
    {
    delete[] nodos;
    maxNodos = A.maxNodos;
    nodos = new celda[maxNodos];
    }
    // Copiar el vector.
    numNodos = A.numNodos;
    for (nodo n = 0; n <= numNodos-1; n++)
        nodos[n] = A.nodos[n];
    }

    return *this; //devolvemos el objeto actual
}

#endif