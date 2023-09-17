#include "ArbolBinarioOrd.h"

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd()
{
    this->raiz = NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd()
{
    if (this->raiz != NULL)
    {
        delete this->raiz;
        this->raiz = NULL;
    }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio()
{
    return this->raiz == NULL;
}

template <class T>
bool ArbolBinarioOrd<T>::insert(T &val)
{
    raiz = insertRec(raiz, val);
}

template <class T>
NodoBin<T> *ArbolBinarioOrd<T>::insertRec(NodoBin<T> *nodo, T valor)
{
    if (nodo == nullptr)
    {
        return new NodoBin<T>(valor);
    }

    if (valor < nodo->obtenerDato())
    {
        if (nodo->obtenerHijoIzq() == nullptr)
            std::cout << "Padre: " << nodo->obtenerDato() << " agregado izquierdo: " << valor << "\n";

        nodo->fijarHijoIzq(insertRec(nodo->obtenerHijoIzq(), valor));
    }
    else if (valor > nodo->obtenerDato())
    {
        if (nodo->obtenerHijoDer() == nullptr)
            std::cout << "Padre: " << nodo->obtenerDato() << " agregado derecho: " << valor << "\n";

        nodo->fijarHijoDer(insertRec(nodo->obtenerHijoDer(), valor));
    }
    return nodo;
}

template <class T>
int ArbolBinarioOrd<T>::altura()
{
    if (this->esVacio())
        return -1;
    else
        return altura(this->raiz);
}

template <class T>
int ArbolBinarioOrd<T>::altura(NodoBin<T> *nodo)
{
    int val;
    // prueba de cambios
    if (nodo->esHoja())
    {
        val = 0;
    }
    else
    {
        int valt_izq = -1;
        int valt_der = -1;
        if (nodo->obtenerHijoIzq() != NULL)
            valt_izq = this->altura(nodo->obtenerHijoIzq());
        if (nodo->obtenerHijoDer() != NULL)
            valt_der = this->altura(nodo->obtenerHijoDer());

        if (valt_izq > valt_der)
            val = valt_izq + 1;
        else
            val = valt_der + 1;
    }

    return val;
}

template <class T>
T ArbolBinarioOrd<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}

template <class T>
int ArbolBinarioOrd<T>::tamahno()
{
}

template <class T>
bool ArbolBinarioOrd<T>::erase(T &val)
{
    if (raiz = NULL)
    {
        return false;
    }
    return eraseNode(val, raiz);
}

template <class T>
int successor(NodoBin<T> *nodo)
{
    raiz = raiz->hijoDer;
    while (root->hijoizq != NULL)
    {
        raiz = raiz->hijoIzq;
    }
    return raiz->dato;
}

template <class T>
int predecessor(NodoBin<T> *nodo)
{
    raiz = raiz->hijoIzq;
    while (root->hijoDer != NULL)
    {
        raiz = raiz->hijoDer;
    }
    return raiz->dato;
}

template <class T>
NodoBin<T> *ArbolBinarioOrd<T>::eraseNode(T &val, NodoBin<T> *nodo)
{
    if (raiz = NULL)
    {
        return false;
    }
    if (val > nodo->obtenerDato())
    {
        return eraseNode(val, nodo->obtenerHijoDer());
    }
    else if (val < nodo->obtenerDato())
    {
        return eraseNode(val, nodo->obtenerHijoIzq());
    }
    else
    {
        if (raiz->hijoIzq == NULL && raiz->hijoDer == NULL)
        {
            raiz = NULL;
        }
        else if (raiz->hijoDer != NULL)
        {
            raiz->dato = successor(raiz);
            raiz->hijoDer = eraseNode(raiz->dato, raiz->hijoDer);
        }
        else if (raiz->hijoIzq != NULL)
        {
            raiz->dato = predecessor(raiz);
            raiz->hijoIzq = eraseNode(raiz->dato, raiz->hijoIzq);
        }
    }
    return raiz;
}

template <class T>
void ArbolBinarioOrd<T>::preOrden()
{
}

template <class T>
void ArbolBinarioOrd<T>::inOrden()
{
    if (!this->esVacio)
    {
        (this->raiz())->inOrden();
    }
}

template <class T>
void ArbolBinarioOrd<T>::posOrden()
{
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden()
{
}
