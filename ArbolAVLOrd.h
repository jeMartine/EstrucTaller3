#ifndef ARBOLAVLORD_H
#define ARBOLAVLORD_H
#include "NodoBin.h"
#include <list>

template <class T>

class ArbolAVLOrd
{
private:
    NodoBin<T> *raiz;
    // hello
public:
    ArbolAVLOrd();
    ~ArbolAVLOrd();
    T datoRaiz();
    bool esVacio();
    int altura();
    int altura(NodoBin<T> *nodo);
    int tamahno();
    bool insert(T &val); // modificar para que sea AVL
    bool erase(T &val);  // modificar para que sea AVL
    void balancear(NodoBin<T> *nodo);
    void rotacionIzq(NodoBin<T> *nodo);
    void rotacionDer(NodoBin<T> *nodo);
    void rotacionIzqDer(NodoBin<T> *nodo);
    void rotacionDerIzq(NodoBin<T> *nodo);
    int successor(NodoBin<T> *nodo);
    int predecessor(NodoBin<T> *nodo);
    NodoBin<T> *eraseNode(T &val, NodoBin<T> *nodo);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBin<T> *insertRec(NodoBin<T> *nodo, T valor);
};

#include "ArbolAVLOrd.hxx"

#endif // ARBOLAVL_H