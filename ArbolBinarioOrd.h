#ifndef ARBOLBINARIOORD_H
#define ARBOLBINARIOORD_H
#include "NodoBin.h"
#include <list>

template <class T>

class ArbolBinarioOrd
{
private:
    NodoBin<T> *raiz;


public:
    ArbolBinarioOrd();
    ~ArbolBinarioOrd();
    T datoRaiz();
    bool esVacio();
    int altura();
    int altura(NodoBin<T> *nodo);
    int tamahno();
    bool insert(T &val);
    bool erase(T &val);
    NodoBin<T> *eraseNode(T &val, NodoBin<T> *nodo);
    void preOrden();
    std::list<T>& inOrden(std::list<T>& resultado);
    void inOrden(NodoBin<T>* nodo, std::list<T>& resultado);
    void posOrden();
    void nivelOrden();
    NodoBin<T> *insertRec(NodoBin<T> *nodo, T valor);
};

#include "ArbolBinarioOrd.hxx"

#endif // ARBOLBINARIOORD_H