#include "NodoBin.h"

template <class T>
NodoBin<T>::NodoBin(T& valor){
    dato = valor;
    hijoIzq= NULL;
    hijoDer= NULL;
}

template <class T>
NodoBin<T>::NodoBin(){
    hijoIzq= NULL;
    hijoDer= NULL;
}


template <class T>
T& NodoBin<T>::obtenerDato (){
    return dato;
}

template <class T>
void NodoBin<T>::fijarDato(T& valor){
    dato= valor;
}

template <class T>
NodoBin <T>* NodoBin<T>::obtenerHijoIzq(){
    return hijoIzq;
}

template <class T>
NodoBin <T>* NodoBin<T>::obtenerHijoDer(){
    return hijoDer;
}

template <class T>
void NodoBin<T>::fijarHijoIzq(NodoBin <T> *izq){
    hijoIzq = izq;
}

template <class T>
void NodoBin<T>::fijarHijoDer(NodoBin <T> *der){
    hijoDer = der;
}

