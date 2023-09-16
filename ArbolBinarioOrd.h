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
    bool esVacio();
    int altura();
    int tamahno();
    bool insertar(T& val);
    bool eliminar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBin<T>* insertRec(NodoBin<T>* nodo, T valor);
};

#include "ArbolBinarioOrd.hxx"

#endif // ARBOLBINARIOORD_H