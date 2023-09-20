#include "ArbolAVLOrd.h"
#include <queue>

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
    return true;
}

template <class T>
int ArbolAVLOrd<T>::getBalanceFactor(NodoAVL<T> *nodo)
{
    if (nodo == nullptr)
        return 0;
    return altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::insertRec(NodoAVL<T> *nodo, T valor)
{
    if (nodo == nullptr)
    {
        return new NodoAVL<T>(valor);
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
    else
    {
        return nodo;
    }
    int balance = getBalanceFactor(nodo);
    if (balance > 1)
    {
        if (valor < nodo->obtenerHijoIzq()->obtenerDato())
        {
            std::cout << "Rotacion derecha\n";
            return rotacionDer(nodo);
        }
        else if (valor > nodo->obtenerHijoIzq()->obtenerDato())
        {
            nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
            std::cout << "Rotacion derecha\n";
            return rotacionDer(nodo);
        }
    }
    if (getBalanceFactor(nodo) < -1)
    {
        if (valor > nodo->obtenerHijoDer()->obtenerDato())
        {
            std::cout << "Rotacion izquierda\n";
            return rotacionIzq(nodo);
        }
        else if (valor < nodo->obtenerHijoDer()->obtenerDato())
        {
            std::cout << "Rotacion izquierda\n";
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
int ArbolAVLOrd<T>::altura(NodoAVL<T> *nodo)
{
    int val;
    // prueba de cambios
    if (nodo->eshoja())
    {
        val = 0;
    }
    else
    {
        int valt_izq = -1;
        int valt_der = -1;
        if (nodo->obtenerHijoIzq() != nullptr)
            valt_izq = this->altura(nodo->obtenerHijoIzq());
        if (nodo->obtenerHijoDer() != nullptr)
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
    return tamano(this->raiz);
}
// recursivo
template <class T>
int ArbolAVLOrd<T>::tamano(NodoAVL<T> *nodo)
{
    if (nodo == nullptr)
    {
        return 0; // Árbol vacío, tamaño cero.
    }
    int tamanoIzquierda = tamano(nodo->obtenerHijoIzq());
    int tamanoDerecha = tamano(nodo->obtenerHijoDer());

    return 1 + tamanoIzquierda + tamanoDerecha;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::rotacionIzq(NodoAVL<T> *nodo)
{
    NodoAVL<T> *temp = nodo->obtenerHijoDer();
    NodoAVL<T> *temp2 = temp->obtenerHijoIzq();
    temp->fijarHijoIzq(nodo);
    nodo->fijarHijoDer(temp2);
    temp->fijarPadre(nodo->obtenerPadre());
    if (nodo->obtenerPadre() != nullptr)
    {
        if (nodo->obtenerPadre()->obtenerHijoIzq() == nodo)
            nodo->obtenerPadre()->fijarHijoIzq(temp);
        else
            nodo->obtenerPadre()->fijarHijoDer(temp);
    }
    nodo->fijarPadre(temp);
    return temp;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::rotacionDer(NodoAVL<T> *nodo)
{
    NodoAVL<T> *temp = nodo->obtenerHijoIzq();
    NodoAVL<T> *temp2 = temp->obtenerHijoDer();
    temp->fijarHijoDer(nodo);
    nodo->fijarHijoIzq(temp2);
    temp->fijarPadre(nodo->obtenerPadre());
    if (nodo->obtenerPadre() != nullptr)
    {
        if (nodo->obtenerPadre()->obtenerHijoIzq() == nodo)
            nodo->obtenerPadre()->fijarHijoIzq(temp);
        else
            nodo->obtenerPadre()->fijarHijoDer(temp);
    }
    nodo->fijarPadre(temp);
    return temp;
}

template <class T>
bool ArbolAVLOrd<T>::erase(T &val)
{
    if (raiz == nullptr)
    {
        return false;
    }
    raiz = eraseNode(val, raiz);
    return true;
}

template <class T>
NodoAVL<T> *nodeMinVal(NodoAVL<T> *nodo)
{
    NodoAVL<T> *current = nodo;
    while (current->obtenerHijoIzq() != nullptr)
    {
        current = current->obtenerHijoIzq();
    }
    return current;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::eraseNode(T &val, NodoAVL<T> *nodo)
{
    if (nodo == NULL)
    {
        std::cout << "No existe el valor\n";
        return nodo;
    }
    if (val < nodo->obtenerDato())
    {
        nodo->fijarHijoIzq(eraseNode(val, nodo->obtenerHijoIzq()));
    }
    else if (val > nodo->obtenerDato())
    {
        nodo->fijarHijoDer(eraseNode(val, nodo->obtenerHijoDer()));
    }
    else
    {
        if (nodo->obtenerHijoIzq() == NULL || nodo->obtenerHijoDer() == NULL)
        {
            NodoAVL<T> *temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
            if (temp == NULL)
            {
                temp = nodo;
                nodo = NULL;
            }
            else
            {
                *nodo = *temp;
            }
            free(temp);
        }
        else
        {
            NodoAVL<T> *temp = nodeMinVal(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarHijoDer(eraseNode(temp->obtenerDato(), nodo->obtenerHijoDer()));
        }
    }
    int balance = getBalanceFactor(nodo);
    if (balance > 1)
    {
        if (getBalanceFactor(nodo->obtenerHijoIzq()) >= 0)
        {
            return rotacionDer(nodo);
        }
        else
        {
            nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
            return rotacionDer(nodo);
        }
    }
    if (balance < -1)
    {
        if (getBalanceFactor(nodo->obtenerHijoDer()) <= 0)
        {
            return rotacionIzq(nodo);
        }
        else
        {
            nodo->fijarHijoDer(rotacionDer(nodo->obtenerHijoDer()));
            return rotacionIzq(nodo);
        }
    }
    return nodo;
}

template <class T>
void ArbolAVLOrd<T>::preOrden()
{
    preOrden(this->raiz);
}

// recursivo
template <class T>
void ArbolAVLOrd<T>::preOrden(NodoAVL<T> *nodo)
{
    if (nodo != nullptr)
    {
        preOrden(nodo->obtenerHijoIzq());
        preOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolAVLOrd<T>::inOrden()
{
    inOrden(this->raiz);
}
// recursivo
template <class T>
void ArbolAVLOrd<T>::inOrden(NodoAVL<T> *nodo)
{
    if (nodo != nullptr)
    {
        // Recorrer primero el subárbol izquierdo
        inOrden(nodo->obtenerHijoIzq());

        // Luego recorrer el subárbol derecho
        inOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolAVLOrd<T>::posOrden()
{
    posOrden(this->raiz);
}
// recursivo
template <class T>
void ArbolAVLOrd<T>::posOrden(NodoAVL<T> *nodo)
{
    if (nodo != nullptr)
    {
        // Recorrer primero el subárbol izquierdo
        posOrden(nodo->obtenerHijoIzq());

        // Luego recorrer el subárbol derecho
        posOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolAVLOrd<T>::nivelOrden()
{
    if (this->raiz == nullptr)
    {
        return;
    }

    std::queue<NodoAVL<T> *> cola; // Cola para realizar el recorrido
    cola.push(this->raiz);         // Comenzamos por la raíz

    while (!cola.empty())
    {
        NodoAVL<T> *nodo = cola.front();
        cola.pop();

        if (nodo->obtenerHijoIzq() != nullptr)
        {
            cola.push(nodo->obtenerHijoIzq());
        }
        if (nodo->obtenerHijoDer() != nullptr)
        {
            cola.push(nodo->obtenerHijoDer());
        }
    }
}

template <class T>
void ArbolAVLOrd<T>::inOrdenLista(std::list<T> &lista)
{
    inOrdenListaRaiz(raiz, lista);
}

// esta es la forma recursiva
template <class T>
void ArbolAVLOrd<T>::inOrdenListaRaiz(NodoAVL<T> *nodo, std::list<T> &lista)
{
    if (nodo != nullptr)
    {
        inOrdenListaRaiz(nodo->obtenerHijoIzq(), lista);
        lista.push_back(nodo->obtenerDato());
        inOrdenListaRaiz(nodo->obtenerHijoDer(), lista);
    }
}
