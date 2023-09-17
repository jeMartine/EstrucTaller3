#include "NodoBin.h"

template <class T>
NodoBin<T>::NodoBin(T &valor)
{
    dato = valor;
    hijoIzq = NULL;
    hijoDer = NULL;
}

template <class T>
NodoBin<T>::NodoBin()
{
    hijoIzq = NULL;
    hijoDer = NULL;
}

template <class T>
T &NodoBin<T>::obtenerDato()
{
    return dato;
}

template <class T>
void NodoBin<T>::fijarDato(T &valor)
{
    dato = valor;
}

template <class T>
NodoBin<T> *NodoBin<T>::obtenerHijoIzq()
{
    return hijoIzq;
}

template <class T>
NodoBin<T> *NodoBin<T>::obtenerHijoDer()
{
    return hijoDer;
}

template <class T>
void NodoBin<T>::fijarHijoIzq(NodoBin<T> *izq)
{
    hijoIzq = izq;
}

template <class T>
void NodoBin<T>::fijarHijoDer(NodoBin<T> *der)
{
    hijoDer = der;
}

template <class T>
bool NodoBin<T>::esHoja()
{
    if (hijoIzq == NULL && hijoDer == NULL)
        return true;
    else
        return false;
}

template <class T>
void NodoBin<T>::inOrden()
{
    if (this->hijoIzq != NULL)
    {
        (this->hijoIzq)->inOrden();
        std::cout << this->dato << std::endl;
    }
    if (this->hijoDer != NULL)
    {
        (this->hijoDer)->inOrden();
    }
}