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
    return true;
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

    if (raiz == nullptr)
        return false;
    std::cout << "se quiere eliminar " << val << "\n";

    raiz = eraseNode(val, raiz);
    return true; // cuando se puede elimiarn
}

template <class T>
NodoBin<T> *nodeMinVal(NodoBin<T> *nodo)
{
    while (nodo->obtenerHijoIzq() != nullptr)
    {
        nodo = nodo->obtenerHijoIzq();
    }
    return nodo;
}

template <class T>
NodoBin<T> *ArbolBinarioOrd<T>::eraseNode(T &val, NodoBin<T> *nodo)
{
    // si el valor buscado no existe dentro del arbol
    if (nodo == NULL)
    {
        std::cout << "No existe el valor\n";
        return nodo;
    }

    if (val < nodo->obtenerDato())
    {
        nodo->fijarHijoIzq(eraseNode(val, nodo->obtenerHijoIzq()));
        // std::cout<<"Padre "<<nodo->obtenerDato()<<" Eliminado izquierdo: "<<val<<"\n";
    }
    else if (val > nodo->obtenerDato())
    {
        nodo->fijarHijoDer(eraseNode(val, nodo->obtenerHijoDer()));
        // std::cout<<"Padre "<<nodo->obtenerDato()<<" Eliminado derecho: "<<val<<"\n";
    }
    else
    {
        if (nodo->obtenerHijoIzq() == NULL)
        {
            NodoBin<T> *temp = nodo->obtenerHijoDer();
            delete nodo;
            return temp;
        }
        else if (nodo->obtenerHijoDer() == NULL)
        {
            NodoBin<T> *temp = nodo->obtenerHijoIzq();
            delete nodo;
            return temp;
        }
        else
        {
            NodoBin<T> *temp = nodeMinVal(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarHijoDer(eraseNode(temp->obtenerDato(), nodo->obtenerHijoDer()));
        }
    }
    return nodo;
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