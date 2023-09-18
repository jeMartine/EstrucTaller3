#ifndef ARBOLAVLORD_H
#define ARBOLAVLORD_H
#include "NodoBin.h"
#include <list>

template <class T>

class ArbolAVLOrd
{
private:
    NodoBin<T> *raiz;


public:
    ArbolAVLOrd();
    ~ArbolAVLOrd();
    T datoRaiz();
    bool esVacio();
    int altura();
    int altura(NodoBin<T> *nodo);
    int tamahno();
    int tamano(NodoBin<T> *nodo);
    bool insert(T &val); // modificar para que sea AVL
    bool erase(T &val);  // modificar para que sea AVL
    NodoBin<T> rotacionIzq(NodoBin<T> *nodo);
    NodoBin<T> rotacionDer(NodoBin<T> *nodo);
    int getBalanceFactor(NodoBin<T> *nodo);
    NodoBin<T> *eraseNode(T &val, NodoBin<T> *nodo);
    void preOrden();
    void preOrden(NodoBin<T> *nodo);
    void inOrden();
    void inOrden(NodoBin<T> *nodo);
    void posOrden();
    void posOrden(NodoBin<T> *nodo);
    void nivelOrden();
    
    NodoBin<T> *insertRec(NodoBin<T> *nodo, T valor);
    void inOrdenLista(std::list<T> &lista);
    void inOrdenListaRaiz(NodoAVL *nodo, std::list<T> &lista);
};

#include "ArbolAVLOrd.hxx"

#endif // ARBOLAVL_H
