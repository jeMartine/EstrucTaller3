#include "NodoAvl.h"
template <class T>
NodoAVL<T>::NodoAVL(T &valor){
    dato = valor;
    hijoIzq = NULL;
    hijoDer = NULL;
    padre = NULL;
}

template <class T>
NodoAVL<T>::NodoAVL(){
    hijoIzq = NULL;
    hijoDer = NULL;
    padre = NULL;
}


template <class T>
T& NodoAVL<T>::obtenerDato(){
    return dato;
}

template <class T>
NodoAVL<T> * NodoAVL<T>::obtenerHijoIzq(){
    return hijoIzq;
}

template <class T>
NodoAVL<T> * NodoAVL<T>::obtenerHijoDer(){
    return hijoDer;
}

template <class T>
NodoAVL<T> * NodoAVL<T>::obtenerPadre(){
    return padre;
}

template <class T>
void NodoAVL<T>::fijarDato( T &valor){
    dato = valor;
}

template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T> *izq){
    hijoIzq = izq;
 }

template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T> *der){
    hijoDer = der;
}

template <class T>
void NodoAVL<T>::fijarPadre(NodoAVL<T> *pad){
    padre = pad;
}

template <class T>
bool NodoAVL<T>::eshoja(){
    if (hijoDer == NULL && hijoIzq==NULL)
        return true;
    else
        return false;
}
