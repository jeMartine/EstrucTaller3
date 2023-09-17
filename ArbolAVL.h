#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoBin.h"
#include <list>

template <class T>

class ArbolAVL
{
private:
    NodoBin<T> *raiz;

public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    int altura();
    int tamahno();
    bool insert(T &val); // modify, se llama balancear
    bool erase(T &val);  // modify, se llama balancear
    bool balancear(NodoBin<T> *nodo);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBin<T> *insertRec(NodoBin<T> *nodo, T valor);
};

#include "ArbolAVL.hxx"

#endif // ARBOLAVL_H