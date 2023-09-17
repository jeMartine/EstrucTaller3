#ifndef ARBOLAVLORD_H
#define ARBOLAVLORD_H
#include "NodoBin.h"
#include <list>

template <class T>

class ArbolAVLOrd
{
private:
    NodoBin<T> *raiz;

struct NodoAVL {
        T valor;
        NodoAVL* izquierdo;
        NodoAVL* derecho;

        NodoAVL( T& val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
    };


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
    NodoBin<T> rotacionIzq(NodoBin<T> *nodo);
    NodoBin<T> rotacionDer(NodoBin<T> *nodo);
    int getBalanceFactor(NodoBin<T> *nodo);
    NodoBin<T> *ArbolAVLOrd<T>::*nodeMinVal(NodoBin<T> *nodo);
    NodoBin<T> *eraseNode(T &val, NodoBin<T> *nodo);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBin<T> *insertRec(NodoBin<T> *nodo, T valor);
    void inOrdenLista(std::list<T>& lista);

};

#include "ArbolAVLOrd.hxx"

#endif // ARBOLAVL_H
