#include "NodoAvl.h"
template <class T>
NodoAVL<T>::NodoAVL(T &valor)
{
    dato = valor;
    hijoIzq = NULL;
    hijoDer = NULL;
    par = NULL;
    height = 1;
}

template <class T>
NodoAVL<T>::NodoAVL()
{
    dato = NULL;
    hijoIzq = NULL;
    hijoDer = NULL;
    par = NULL;
    height = 1;
}

template <class T>
NodoAVL<T> *NodoAVL<T>::obtenerPar()
{
    return par;
}

template <class T>
void NodoAVL<T>::fijarPar(NodoAVL<T> *padre)
{
    par = padre;
}

template <class T>
T &NodoAVL<T>::obtenerDato()
{
    return dato;
}

template <class T>
NodoAVL<T> *NodoAVL<T>::obtenerHijoIzq()
{
    return hijoIzq;
}

template <class T>
NodoAVL<T> *NodoAVL<T>::obtenerHijoDer()
{
    return hijoDer;
}

template <class T>
int NodoAVL<T>::obtenerHeight()
{
    return height;
}

template <class T>
void NodoAVL<T>::fijarDato(T &valor)
{
    dato = valor;
}

template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T> *izq)
{
    hijoIzq = izq;
}

template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T> *der)
{
    hijoDer = der;
}

template <class T>
void NodoAVL<T>::fijarHeight(int height)
{
    this->height = height;
}

template <class T>
bool NodoAVL<T>::eshoja()
{
    if (hijoDer == NULL && hijoIzq == NULL)
        return true;
    else
        return false;
}
