#ifndef NODOBIN_H 
#define NODOBIN_H

template <class T>

class NodoBin {
    private:
    T dato;
    NodoBin <T> * hijoIzq;
    NodoBin <T> * hijoDer;

    public:
    NodoBin (T& valor);
    NodoBin ();

    T& obtenerDato ();
    void fijarDato(T& valor);
    NodoBin <T>* obtenerHijoIzq();
    NodoBin <T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBin <T> *izq);
    void fijarHijoDer(NodoBin <T> *der);
};

#include "NodoBin.hxx"

#endif // NODOBIN_H