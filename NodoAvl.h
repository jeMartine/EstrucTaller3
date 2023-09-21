#ifndef NODOAVL_H
#define NODOAVL_H
template <class T>
class NodoAVL
{
private:
    T dato;
    NodoAVL<T> *hijoIzq;
    NodoAVL<T> *hijoDer;
    int height;
    NodoAVL<T> *par;

public:
    NodoAVL(T &val);
    NodoAVL();

    T &obtenerDato();
    void fijarDato(T &val);
    NodoAVL<T> *obtenerHijoIzq();
    NodoAVL<T> *obtenerHijoDer();
    NodoAVL<T> *obtenerPar();
    void fijarPar(NodoAVL<T> *padre);
    int obtenerHeight();
    void fijarHijoIzq(NodoAVL<T> *izq);
    void fijarHijoDer(NodoAVL<T> *der);
    void fijarHeight(int height);

    bool eshoja();
};
#include "NodoAvl.hxx"

#endif // NODOAVL_H
