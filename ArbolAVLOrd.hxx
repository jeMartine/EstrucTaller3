#include "ArbolAVLOrd.h"

template <class T>
ArbolAVLOrd<T>::ArbolAVLOrd()
{
    this->raiz = NULL;
}

template <class T>
ArbolAVLOrd<T>::~ArbolAVLOrd()
{
    if (this->raiz != NULL)
    {
        delete this->raiz;
        this->raiz = NULL;
    }
}

template <class T>
bool ArbolAVLOrd<T>::esVacio()
{
    return this->raiz == NULL;
}

template <class T>
bool ArbolAVLOrd<T>::insert(T &val)
{
    raiz = insertRec(raiz, val);
}

template <class T>
int ArbolAVLOrd<T>::getBalanceFactor(NodoBin<T> *nodo)
{
    if (nodo == NULL)
        return 0;
    return altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
}

template <class T>
NodoBin<T> *ArbolAVLOrd<T>::insertRec(NodoBin<T> *nodo, T valor)
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
    if (getBalanceFactor(nodo) > 1)
    {
        if (valor < nodo->obtenerHijoIzq()->obtenerDato())
        {
            return rotacionDer(nodo);
        }
        else
        {
            nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
            return rotacionDer(nodo);
        }
    }
    if (getBalanceFactor(nodo) < -1)
    {
        if (valor > nodo->obtenerHijoDer()->obtenerDato())
        {
            return rotacionIzq(nodo);
        }
        else if (valor < nodo->obtenerHijoDer()->obtenerDato())
        {
            nodo->fijarHijoDer(rotacionDer(nodo->obtenerHijoDer()));
            return rotacionIzq(nodo);
        }
    }
    return nodo;
}

template <class T>
int ArbolAVLOrd<T>::altura()
{
    if (this->esVacio())
        return -1;
    else
        return altura(this->raiz);
}

template <class T>
int ArbolAVLOrd<T>::altura(NodoBin<T> *nodo)
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
T ArbolAVLOrd<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}

template <class T>
int ArbolAVLOrd<T>::tamahno()
{
}

template <class T>
NodoBin<T> ArbolAVLOrd<T>::rotacionIzq(NodoBin<T> *nodo)
{
    NodoBin<T> *temp = nodo->obtenerHijoDer();
    NodoBin<T> *temp2 = temp->obtenerHijoIzq();
    temp->fijarHijoIzq(nodo);
    nodo->fijarHijoDer(temp2);
    return temp;
}

template <class T>
NodoBin<T> ArbolAVLOrd<T>::rotacionDer(NodoBin<T> *nodo)
{
    NodoBin<T> *temp = nodo->obtenerHijoIzq();
    NodoBin<T> *temp2 = temp->obtenerHijoDer();
    temp->fijarHijoDer(nodo);
    nodo->fijarHijoIzq(temp2);
    return temp;
}

template <class T>
bool ArbolAVLOrd<T>::erase(T &val)
{
    if (raiz == NULL)
    {
        return false;
    }
    return eraseNode(val, raiz);
}

template <class T>
NodoBin<T> *ArbolAVLOrd<T>::*nodeMinVal(NodoBin<T> *nodo)
{
    NodoBin<T> *current = nodo;
    while (current->obtenerHijoIzq() != NULL)
    {
        current = current->obtenerHijoIzq();
    }
    return current;
}

template <class T>
NodoBin<T> *ArbolAVLOrd<T>::eraseNode(T &val, NodoBin<T> *nodo)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    if (val < nodo->obtenerDato())
    {
        raiz->fijarHijoIzq(eraseNode(val, nodo->obtenerHijoIzq()));
    }
    else if (val > nodo->obtenerDato())
    {
        raiz->fijarHijoDer(eraseNode(val, nodo->obtenerHijoDer()));
    }
    else
    {
        if (raiz->obtenerHijoIzq() == NULL || raiz->obtenerHijoDer() == NULL)
        {
            NodoBin<T> *temp = raiz->obtenerHijoIzq() ? raiz->obtenerHijoIzq() : raiz->obtenerHijoDer();
            if (temp == NULL)
            {
                temp = raiz;
                raiz = NULL;
            }
            else
            {
                *raiz = *temp;
            }
            free(temp);
        }
        else
        {
            NodoBin<T> *temp = nodeMinVal(raiz->obtenerHijoDer());
            raiz->fijarDato(temp->obtenerDato());
            raiz->fijarHijoDer(eraseNode(temp->obtenerDato(), raiz->obtenerHijoDer()));
        }
    }
    if (raiz == NULL)
    {
        return raiz;
    }
    int balance = getBalanceFactor(raiz);
    if (balance > 1)
    {
        if (getBalanceFactor(raiz->obtenerHijoIzq()) >= 0)
        {
            return rotacionDer(raiz);
        }
        else
        {
            raiz->fijarHijoIzq(rotacionIzq(raiz->obtenerHijoIzq()));
            return rotacionDer(raiz);
        }
    }
    if (balance < -1)
    {
        if (getBalanceFactor(raiz->obtenerHijoDer()) <= 0)
        {
            return rotacionIzq(raiz);
        }
        else
        {
            raiz->fijarHijoDer(rotacionDer(raiz->obtenerHijoDer()));
            return rotacionIzq(raiz);
        }
    }
    return raiz;
}

template <class T>
void ArbolAVLOrd<T>::preOrden()
{
}

template <class T>
void ArbolAVLOrd<T>::inOrden()
{
    if (!this->esVacio)
    {
        (this->raiz())->inOrden();
    }
}

template <class T>
void ArbolAVLOrd<T>::posOrden()
{
}

template <class T>
void ArbolAVLOrd<T>::nivelOrden()
{
}
