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

int max(int a, int b)
{
    return (a > b) ? a : b;
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
    if (nodo == NULL)
        return 0;
    return calcHeight(nodo->obtenerHijoIzq()) - calcHeight(nodo->obtenerHijoDer());
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
    nodo->fijarHeight(1 + max(calcHeight(nodo->obtenerHijoIzq()), calcHeight(nodo->obtenerHijoDer())));
    int balance = getBalanceFactor(nodo);
    if (balance > 1)
    {
        if (valor < nodo->obtenerHijoIzq()->obtenerDato())
        {
            std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
            return rotacionDer(nodo);
        }
        else if (valor > nodo->obtenerHijoIzq()->obtenerDato())
        {
            nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
            std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
            return rotacionDer(nodo);
        }
    }
    else if (balance < -1)
    {
        if (valor > nodo->obtenerHijoDer()->obtenerDato())
        {
            std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
            return rotacionIzq(nodo);
        }
        else if (valor < nodo->obtenerHijoDer()->obtenerDato())
        {
            std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
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
int ArbolAVLOrd<T>::calcHeight(NodoAVL<T> *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    return nodo->obtenerHeight();
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
    return tamano(this->raiz);
}

template <class T>
int ArbolAVLOrd<T>::tamano(NodoAVL<T> *nodo)
{
    if (nodo == nullptr)
    {
        return 0;
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
    nodo->fijarHeight(max(calcHeight(nodo->obtenerHijoIzq()), calcHeight(nodo->obtenerHijoDer())) + 1);
    temp->fijarHeight(max(calcHeight(temp->obtenerHijoIzq()), calcHeight(temp->obtenerHijoDer())) + 1);
    return temp;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::rotacionDer(NodoAVL<T> *nodo)
{
    NodoAVL<T> *temp = nodo->obtenerHijoIzq();
    NodoAVL<T> *temp2 = temp->obtenerHijoDer();
    temp->fijarHijoDer(nodo);
    nodo->fijarHijoIzq(temp2);
    nodo->fijarHeight(max(calcHeight(nodo->obtenerHijoIzq()), calcHeight(nodo->obtenerHijoDer())) + 1);
    temp->fijarHeight(max(calcHeight(temp->obtenerHijoIzq()), calcHeight(temp->obtenerHijoDer())) + 1);
    return temp;
}

template <class T>
bool ArbolAVLOrd<T>::erase(T &val)
{
    if (raiz == nullptr)
    {
        return false;
    }
    eraseNode(val, raiz);
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
        std::cout << "No existe el nodo\n";
        return nodo;
    }
    if (val < nodo->obtenerDato())
    {
        nodo->fijarHijoIzq(eraseNode(val, nodo->obtenerHijoIzq()));
        std::cout << "Padre " << nodo->obtenerDato() << " Eliminado izquierdo: " << val << "\n";
    }
    else if (val > nodo->obtenerDato())
    {
        nodo->fijarHijoDer(eraseNode(val, nodo->obtenerHijoDer()));
        std::cout << "Padre " << nodo->obtenerDato() << " Eliminado derecha: " << val << "\n";
    }
    else
    {
        // if (nodo->obtenerHijoIzq() == NULL) {
        //     NodoAVL<T> *temp = nodo->obtenerHijoDer();
        //     delete nodo;
        // } else if (nodo->obtenerHijoDer() == NULL) {
        //     NodoAVL<T> *temp = nodo->obtenerHijoIzq();
        //     delete nodo;
        // } else {
        //     NodoAVL<T> *temp = nodeMinVal(nodo->obtenerHijoDer());
        //     nodo->fijarDato(temp->obtenerDato());
        //     nodo->fijarHijoDer(eraseNode(temp->obtenerDato(), nodo->obtenerHijoDer()));
        // }

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
    nodo->fijarHeight(1 + max(calcHeight(nodo->obtenerHijoIzq()), calcHeight(nodo->obtenerHijoDer())));
    int balance = getBalanceFactor(nodo);
    if (balance > 1)
    {
        if (getBalanceFactor(nodo->obtenerHijoIzq()) >= 0)
        {
            std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
            return rotacionDer(nodo);
        }
        else
        {
            std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
            nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
            return rotacionDer(nodo);
        }
    }
    if (balance < -1)
    {
        if (balance <= 0)
        {
            std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
            return rotacionIzq(nodo);
        }
        else
        {
            std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
            nodo->fijarHijoDer(rotacionDer(nodo->obtenerHijoDer()));
            return rotacionIzq(nodo);
        }
    }
    return nodo;
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
