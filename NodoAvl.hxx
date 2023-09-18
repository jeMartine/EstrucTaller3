#include "NodoAvl.h"

template <class T>
T NodoAVL<T>::obtenerValor(){
    return valor;
}
template <class T>
NodoAVL<T> * NodoAVL<T>::obtenerIzquierdo(){
return izquierdo;
}
template <class T>
NodoAVL<T> * NodoAVL<T>::obtenerDerecho(){
return derecho;
}

template <class T>
int NodoAVL<T>:: obtenerAltura(){
return altura;
}
template <class T>
void NodoAVL<T>::fijarValor( T &val){
valor = val;
}
template <class T>
void NodoAVL<T>::fijarIzquierdo(NodoAVL<T> *nodo){
izquierdo = nodo;
}
template <class T>
void NodoAVL<T>::fijarDerecho(NodoAVL<T> *nodo){
derecho = nodo;
}
template <class T>
void NodoAVL<T>::fijarAltura(int alt){
altura = alt;
}

template <class T>
bool NodoBin<T>::esHoja()
{
    if (hijoIzq == NULL && hijoDer == NULL)
        return true;
    else
        return false;
}
