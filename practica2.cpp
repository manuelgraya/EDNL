/*1. Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos árboles binarios son
similares*

bool fun(a1,a2,abin)
devolver recursiva (raiz A. raiz b ,a ,b)


recursiva 
si n1= nodo nulo or n2= nodo nulo
    devolver n1= nodo nulo and n2=nodo nulo
si no 
    devolver recursiva (hizq(n1 a1), hder (n1 a1, ),a1,a2 AND lo mismo con el derecho)

*/

/*

vamos a interpretarlo como la imagen en el espejo

abin reflejado(A abin)

B abin;
si arbolvacio(A)

insertarraiz (raiz (A),B)
reflejoabinrec (raiz (a), raiz (b), A , B)

devolver B


reflejoabinrec(n1,n2 nodo a1,a2 abin)
si hijoizq (n1,A)!= nodo nulo
insertarhijoderecho(elemento(n1,A),n2,B)
reflejoabinrec(hizq(n1,A)hder(n2,b, A,B))
fin si
si hijoder (n1,A)!= nodo nulo
insertarhijoderecho(elemento(n1,A),n2,B)
reflejoabinrec(hizq(n1,A)hder(n2,b, A,B))
fin si

*/