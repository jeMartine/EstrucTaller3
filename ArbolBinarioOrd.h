#ifndef ARBOLBINARIOORD_H 
#define ARBOLBINARIOORD_H
#include "NodoBin.h"
#include <list>

template <class T>

class ArbolBinarioOrd {
private:
    NodoBin <T> * raiz;
public:
    ArbolBinarioOrd();
    ~ArbolBinarioOrd();
    T datoRaiz();
    bool esVacio();
    int altura();
    int altura(NodoBin <T> * nodo);
    int tamahno();
    bool insert(T& val);
    bool erase(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBin<T>* insertRec(NodoBin<T>* nodo, T valor);
};
//prueba de cambios 
#include "ArbolBinarioOrd.hxx"

#endif // ARBOLBINARIOORD_H