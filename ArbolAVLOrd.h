#ifndef ARBOLAVLORD_H
#define ARBOLAVLORD_H
#include "NodoAvl.h"
#include <list>

template <class T>

class ArbolAVLOrd
{
private:
    NodoAVL<T> *raiz;

public:
    ArbolAVLOrd();
    ~ArbolAVLOrd();
    T datoRaiz();
    bool esVacio();
    int altura();
    int altura(NodoAVL<T> *nodo);
    int calcHeight(NodoAVL<T> *nodo);
    int tamahno();
    int tamano(NodoAVL<T> *nodo);
    bool insert(T &val); // modificar para que sea AVL
    bool erase(T &val);  // modificar para que sea AVL
    NodoAVL<T> *rotacionIzq(NodoAVL<T> *nodo);
    NodoAVL<T> *rotacionDer(NodoAVL<T> *nodo);
    int getBalanceFactor(NodoAVL<T> *nodo);
    NodoAVL<T> *insertRec(NodoAVL<T> *nodo, T valor);
    NodoAVL<T> *eraseNode(T &val, NodoAVL<T> *nodo);
    void preOrden();
    void preOrden(NodoAVL<T> *nodo);
    void inOrden();
    void inOrden(NodoAVL<T> *nodo);
    void posOrden();
    void posOrden(NodoAVL<T> *nodo);
    void nivelOrden();

    void inOrdenLista(std::list<T> &lista);
    void inOrdenListaRaiz(NodoAVL<T> *nodo, std::list<T> &lista);
};

#include "ArbolAVLOrd.hxx"

#endif // ARBOLAVL_H