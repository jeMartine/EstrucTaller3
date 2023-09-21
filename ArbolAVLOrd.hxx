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
    // raiz = insertRec(raiz, val);
    raiz = insertRec(raiz, NULL, val);
    return true;
}

template <class T>
void ArbolAVLOrd<T>::updateHeight(NodoAVL<T> *nodo)
{
    if (nodo != NULL)
    {
        int val = 1;
        if (nodo->obtenerHijoIzq() != NULL)
        {
            val = nodo->obtenerHijoIzq()->obtenerHeight() + 1;
        }
        if (nodo->obtenerHijoDer() != NULL)
        {
            val = max(val, nodo->obtenerHijoDer()->obtenerHeight() + 1);
        }
        nodo->fijarHeight(val);
    }
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::LLR(NodoAVL<T> *nodo)
{
    std::cout << "Rotacion izquierda de " << nodo->obtenerDato() << "\n";
    NodoAVL<T> *temp = nodo->obtenerHijoIzq();
    nodo->fijarHijoIzq(temp->obtenerHijoDer());
    if (temp->obtenerHijoDer() != NULL)
    {
        temp->obtenerHijoDer()->fijarPar(nodo);
    }
    temp->fijarHijoDer(nodo);
    temp->fijarPar(nodo->obtenerPar());
    nodo->fijarPar(temp);

    if (temp->obtenerPar() != NULL && nodo->obtenerDato() < temp->obtenerPar()->obtenerDato())
    {
        temp->obtenerPar()->fijarHijoIzq(temp);
    }
    else
    {
        if (temp->obtenerPar() != NULL)
        {
            temp->obtenerPar()->fijarHijoDer(temp);
        }
    }
    nodo = temp;
    updateHeight(nodo->obtenerHijoDer());
    updateHeight(nodo->obtenerHijoIzq());
    updateHeight(nodo);
    updateHeight(nodo->obtenerPar());
    return nodo;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::RRR(NodoAVL<T> *nodo)
{
    std::cout << "Rotacion derecha de " << nodo->obtenerDato() << "\n";

    NodoAVL<T> *temp = nodo->obtenerHijoDer();
    nodo->fijarHijoDer(temp->obtenerHijoIzq());
    if (temp->obtenerHijoIzq() != NULL)
    {
        temp->obtenerHijoIzq()->fijarPar(nodo);
    }
    temp->fijarHijoIzq(nodo);
    temp->fijarPar(nodo->obtenerPar());
    nodo->fijarPar(temp);
    if (temp->obtenerPar() != NULL && nodo->obtenerDato() < temp->obtenerPar()->obtenerDato())
    {
        temp->obtenerPar()->fijarHijoIzq(temp);
    }
    else
    {
        if (temp->obtenerPar() != NULL)
        {
            temp->obtenerPar()->fijarHijoDer(temp);
        }
    }
    nodo = temp;
    updateHeight(nodo->obtenerHijoDer());
    updateHeight(nodo->obtenerHijoIzq());
    updateHeight(nodo);
    updateHeight(nodo->obtenerPar());
    return nodo;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::LRR(NodoAVL<T> *nodo)
{
    std::cout << "Rotacion izquierda-derecha de " << nodo->obtenerDato() << "\n";

    nodo->fijarHijoIzq(RRR(nodo->obtenerHijoIzq()));
    return LLR(nodo);
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::RLR(NodoAVL<T> *nodo)
{
    std::cout << "Rotacion derecha-izquierda de " << nodo->obtenerDato() << "\n";
    nodo->fijarHijoDer(LLR(nodo->obtenerHijoDer()));
    return RRR(nodo);
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
int ArbolAVLOrd<T>::getBalanceFactor(NodoAVL<T> *nodo)
{
    if (nodo == NULL)
        return 0;
    return calcHeight(nodo->obtenerHijoIzq()) - calcHeight(nodo->obtenerHijoDer());
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::insertRec(NodoAVL<T> *nodo, NodoAVL<T> *parent, T valor)
{
    if (nodo == NULL)
    {
        nodo = new NodoAVL<T>(valor);
        if (nodo == NULL)
        {
            std::cout << "Error al crear el nodo\n";
            return NULL;
        }
        else
        {
            nodo->fijarHeight(1);
            nodo->fijarHijoIzq(NULL);
            nodo->fijarHijoDer(NULL);
            nodo->fijarPar(parent);
            nodo->fijarDato(valor);
        }
    }
    else if (nodo->obtenerDato() > valor)
    {
        nodo->fijarHijoIzq(insertRec(nodo->obtenerHijoIzq(), nodo, valor));
        std::cout << "Padre: " << nodo->obtenerDato() << " agregado izquierdo: " << valor << "\n";

        int firstHeight = 0;
        int secondHeight = 0;
        if (nodo->obtenerHijoIzq() != NULL)
        {
            firstHeight = nodo->obtenerHijoIzq()->obtenerHeight();
        }
        if (nodo->obtenerHijoDer() != NULL)
        {
            secondHeight = nodo->obtenerHijoDer()->obtenerHeight();
        }
        if (abs(firstHeight - secondHeight) == 2)
        {
            if (nodo->obtenerHijoIzq() != NULL && valor < nodo->obtenerHijoIzq()->obtenerDato())
            {
                nodo = LLR(nodo);
            }
            else
            {
                nodo = LRR(nodo);
            }
        }
    }
    else if (nodo->obtenerDato() < valor)
    {
        nodo->fijarHijoDer(insertRec(nodo->obtenerHijoDer(), nodo, valor));
        std::cout << "Padre: " << nodo->obtenerDato() << " agregado derecha: " << valor << "\n";

        int firstHeight = 0;
        int secondHeight = 0;
        if (nodo->obtenerHijoIzq() != NULL)
        {
            firstHeight = nodo->obtenerHijoIzq()->obtenerHeight();
        }
        if (nodo->obtenerHijoDer() != NULL)
        {
            secondHeight = nodo->obtenerHijoDer()->obtenerHeight();
        }
        if (abs(firstHeight - secondHeight) == 2)
        {
            if (nodo->obtenerHijoDer() != NULL && valor < nodo->obtenerHijoDer()->obtenerDato())
            {
                nodo = RLR(nodo);
            }
            else
            {
                nodo = RRR(nodo);
            }
        }
    }
    else
    {
        std::cout << "El nodo ya existe\n";
    }
    updateHeight(nodo);
    return nodo;
}

// template <class T>
// NodoAVL<T> *ArbolAVLOrd<T>::insertRec(NodoAVL<T> *nodo, T valor)
// {
//     if (nodo == NULL)
//     {
//         return new NodoAVL<T>(valor);
//     }

//     if (valor < nodo->obtenerDato())
//     {
//         if (nodo->obtenerHijoIzq() == nullptr)
//             std::cout << "Padre: " << nodo->obtenerDato() << " agregado izquierdo: " << valor << "\n";

//         nodo->fijarHijoIzq(insertRec(nodo->obtenerHijoIzq(), valor));
//     }
//     else if (valor > nodo->obtenerDato())
//     {
//         if (nodo->obtenerHijoDer() == nullptr)
//             std::cout << "Padre: " << nodo->obtenerDato() << " agregado derecho: " << valor << "\n";

//         nodo->fijarHijoDer(insertRec(nodo->obtenerHijoDer(), valor));
//     }
//     else
//     {
//         return nodo;
//     }
//     nodo->fijarHeight(1 + max(calcHeight(nodo->obtenerHijoIzq()), calcHeight(nodo->obtenerHijoDer())));
//     int balance = getBalanceFactor(nodo);
//     if (balance > 1)
//     {
//         if (valor < nodo->obtenerHijoIzq()->obtenerDato())
//         {
//             std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
//             return rotacionDer(nodo);
//         }
//         else if (valor > nodo->obtenerHijoIzq()->obtenerDato())
//         {
//             nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
//             std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
//             return rotacionDer(nodo);
//         }
//     }
//     else if (balance < -1)
//     {
//         if (valor > nodo->obtenerHijoDer()->obtenerDato())
//         {
//             std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
//             return rotacionIzq(nodo);
//         }
//         else if (valor < nodo->obtenerHijoDer()->obtenerDato())
//         {
//             std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
//             nodo->fijarHijoDer(rotacionDer(nodo->obtenerHijoDer()));
//             return rotacionIzq(nodo);
//         }
//     }
//     return nodo;
// }

template <class T>
int ArbolAVLOrd<T>::size()
{
    if (this->esVacio())
        return -1;
    else
        return size(this->raiz);
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
int ArbolAVLOrd<T>::size(NodoAVL<T> *nodo)
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
bool ArbolAVLOrd<T>::erase(T &val)
{
    if (raiz == NULL)
    {
        return false;
    }
    std::cout << "se quiere eliminar " << val << "\n";

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
int ArbolAVLOrd<T>::obtenerCantidadHijos(NodoAVL<T> *nodo)
{
    int cantidad = 0;
    if (nodo->obtenerHijoIzq() != nullptr)
    {
        cantidad++;
    }
    if (nodo->obtenerHijoDer() != nullptr)
    {
        cantidad++;
    }
    return cantidad;
}

template <class T>
NodoAVL<T> ArbolAVLOrd<T>::obtenerHijoNoVacio(NodoAVL<T> *nodo)
{
    if (nodo->obtenerHijoIzq() != nullptr)
    {
        return nodo->obtenerHijoIzq();
    }
    else
    {
        return nodo->obtenerHijoDer();
    }
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::balanceee(NodoAVL<T> *nodo)
{
    int firstHeight = 0;
    int secondHeight = 0;
    if (nodo->obtenerHijoIzq() != NULL)
    {
        firstHeight = nodo->obtenerHijoIzq()->obtenerHeight();
    }
    if (nodo->obtenerHijoDer() != NULL)
    {
        secondHeight = nodo->obtenerHijoDer()->obtenerHeight();
    }
    if (abs(firstHeight - secondHeight) == 2)
    {
        if (firstHeight < secondHeight)
        {
            int rightHeight1 = 0;
            int rightHeight2 = 0;
            if (nodo->obtenerHijoDer()->obtenerHijoDer() != NULL)
            {
                rightHeight1 = nodo->obtenerHijoDer()->obtenerHijoDer()->obtenerHeight();
            }
            if (nodo->obtenerHijoDer()->obtenerHijoIzq() != NULL)
            {
                rightHeight2 = nodo->obtenerHijoDer()->obtenerHijoIzq()->obtenerHeight();
            }
            if (rightHeight1 < rightHeight2)
            {
                nodo = RLR(nodo);
            }
            else
            {
                nodo = RRR(nodo);
            }
        }
        else
        {
            int leftHeight1 = 0;
            int leftHeight2 = 0;
            if (nodo->obtenerHijoIzq()->obtenerHijoDer() != NULL)
            {
                leftHeight2 = nodo->obtenerHijoIzq()->obtenerHijoDer()->obtenerHeight();
            }
            if (nodo->obtenerHijoIzq()->obtenerHijoIzq() != NULL)
            {
                leftHeight1 = nodo->obtenerHijoIzq()->obtenerHijoIzq()->obtenerHeight();
            }
            if (leftHeight1 > leftHeight2)
            {
                nodo = LLR(nodo);
            }
            else
            {
                nodo = LRR(nodo);
            }
        }
    }
    return nodo;
}

template <class T>
NodoAVL<T> *ArbolAVLOrd<T>::eraseNode(T &val, NodoAVL<T> *nodo)
{
    if (nodo != NULL)
    {
        if (nodo->obtenerDato() == val)
        {
            if (nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() != NULL)
            {
                if (nodo->obtenerPar() != NULL)
                {
                    if (nodo->obtenerPar()->obtenerDato() < nodo->obtenerDato())
                    {
                        nodo->obtenerPar()->fijarHijoDer(nodo->obtenerHijoIzq());
                    }
                    else
                    {
                        nodo->obtenerPar()->fijarHijoIzq(nodo->obtenerHijoIzq());
                    }
                    nodo->obtenerHijoIzq()->fijarPar(nodo->obtenerPar());
                    nodo->fijarHijoIzq(balanceee(nodo->obtenerHijoIzq()));
                    return nodo->obtenerHijoIzq();
                }
            }
            else if (nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() != NULL)
            {
                if (nodo->obtenerPar() != NULL)
                {
                    if (nodo->obtenerPar()->obtenerDato() < nodo->obtenerDato())
                    {
                        nodo->obtenerPar()->fijarHijoDer(nodo->obtenerHijoDer());
                    }
                    else
                    {
                        nodo->obtenerPar()->fijarHijoIzq(nodo->obtenerHijoDer());
                    }
                    updateHeight(nodo->obtenerPar());
                }
                nodo->obtenerHijoDer()->fijarPar(nodo->obtenerPar());
                nodo->fijarHijoDer(balanceee(nodo->obtenerHijoDer()));
                return nodo->obtenerHijoDer();
            }
            else if (nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() == NULL)
            {
                if (nodo->obtenerPar()->obtenerDato() < nodo->obtenerDato())
                {
                    nodo->obtenerPar()->fijarHijoDer(NULL);
                }
                else
                {
                    nodo->obtenerPar()->fijarHijoIzq(NULL);
                }
                if (nodo->obtenerPar() != NULL)
                {
                    updateHeight(nodo->obtenerPar());
                }
                nodo = NULL;
                return NULL;
            }
            else
            {
                NodoAVL<T> *temp = nodo;
                temp = temp->obtenerHijoDer();
                while (temp->obtenerHijoIzq() != NULL)
                {
                    temp = temp->obtenerHijoIzq();
                }
                std::string valll = temp->obtenerDato();
                nodo->fijarHijoDer(eraseNode(nodo->obtenerDato(), nodo->obtenerHijoDer()));
                nodo->fijarDato(valll);
                nodo = balanceee(nodo);
            }
        }
        else if (val > nodo->obtenerDato())
        {
            nodo->fijarHijoDer(eraseNode(val, nodo->obtenerHijoDer()));
            nodo = balanceee(nodo);
        }
        else if (val < nodo->obtenerDato())
        {
            nodo->fijarHijoIzq(eraseNode(val, nodo->obtenerHijoIzq()));
            nodo = balanceee(nodo);
        }
        if (nodo != NULL)
        {
            updateHeight(nodo);
        }
    }
    else
    {
        std::cout << "No existe el nodo\n";
    }
    return nodo;
}

// template <class T>
// NodoAVL<T> *ArbolAVLOrd<T>::eraseNode(T &val, NodoAVL<T> *nodo)
// {
//     // if (nodo->obtenerDato() == val)
//     // {
//     //     if (obtenerCantidadHijos(nodo) == 0)
//     //     {
//     //         delete nodo;
//     //         nodo = NULL;
//     //     }
//     //     else if (obtenerCantidadHijos(nodo) == 1)
//     //     {
//     //         nodo = obtenerHijoNoVacio(nodo);
//     //     }
//     //     else
//     //     {
//     //         NodoAVL<T> *izqMay = nodo->obtenerHijoIzq()->obtenerMayor();
//     //         if (obtenerPadreNodo(izqMay)->obtenerDato() != nodo->obtenerDato())
//     //         {
//     //             obtenerPadreNodo(izqMay)->fijarHijoDer(izqMay->obtenerHijoIzq());
//     //             izqMay->fijarHijoIzq(nodo->obtenerHijoIzq());
//     //         }
//     //         izqMay->fijarHijoDer(nodo->obtenerHijoDer());
//     //         nodo = izqMay;
//     //     }
//     //     return true;
//     // }

//     if (val < nodo->obtenerDato())
//     {
//         nodo->fijarHijoIzq(eraseNode(val, nodo->obtenerHijoIzq()));
//         std::cout << "Padre " << nodo->obtenerDato() << " Eliminado izquierdo: " << val << "\n";
//     }
//     else if (val > nodo->obtenerDato())
//     {
//         nodo->fijarHijoDer(eraseNode(val, nodo->obtenerHijoDer()));
//         std::cout << "Padre " << nodo->obtenerDato() << " Eliminado derecha: " << val << "\n";
//     }
//     else
//     {
//         // if (nodo->obtenerHijoIzq() == NULL) {
//         //     NodoAVL<T> *temp = nodo->obtenerHijoDer();
//         //     delete nodo;
//         // } else if (nodo->obtenerHijoDer() == NULL) {
//         //     NodoAVL<T> *temp = nodo->obtenerHijoIzq();
//         //     delete nodo;
//         // } else {
//         //     NodoAVL<T> *temp = nodeMinVal(nodo->obtenerHijoDer());
//         //     nodo->fijarDato(temp->obtenerDato());
//         //     nodo->fijarHijoDer(eraseNode(temp->obtenerDato(), nodo->obtenerHijoDer()));
//         // }

//         if (nodo->obtenerHijoIzq() == NULL || nodo->obtenerHijoDer() == NULL)
//         {
//             NodoAVL<T> *temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
//             if (temp == NULL)
//             {
//                 temp = nodo;
//                 nodo = NULL;
//             }
//             else
//             {
//                 *nodo = *temp;
//             }
//             free(temp);
//         }
//         else
//         {
//             NodoAVL<T> *temp = nodeMinVal(nodo->obtenerHijoDer());
//             nodo->fijarDato(temp->obtenerDato());
//             nodo->fijarHijoDer(eraseNode(temp->obtenerDato(), nodo->obtenerHijoDer()));
//         }
//     }
//     if (nodo == NULL)
//     {
//         std::cout << "No existe el nodo\n";
//         return nodo;
//     }
//     nodo->fijarHeight(1 + max(calcHeight(nodo->obtenerHijoIzq()), calcHeight(nodo->obtenerHijoDer())));
//     int balance = getBalanceFactor(nodo);
//     if (balance > 1)
//     {
//         if (getBalanceFactor(nodo->obtenerHijoIzq()) >= 0)
//         {
//             std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
//             return rotacionDer(nodo);
//         }
//         else if (getBalanceFactor(nodo->obtenerHijoIzq()) < 0)
//         {
//             std::cout << "Rotacion derecha: " << nodo->obtenerDato() << "\n";
//             nodo->fijarHijoIzq(rotacionIzq(nodo->obtenerHijoIzq()));
//             return rotacionDer(nodo);
//         }
//     }
//     if (balance < -1)
//     {
//         if (balance <= 0)
//         {
//             std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
//             return rotacionIzq(nodo);
//         }
//         else
//         {
//             std::cout << "Rotacion izquierda: " << nodo->obtenerDato() << "\n";
//             nodo->fijarHijoDer(rotacionDer(nodo->obtenerHijoDer()));
//             return rotacionIzq(nodo);
//         }
//     }
//     return nodo;
// }

template <class T>
void ArbolAVLOrd<T>::preOrden(NodoAVL<T> *nodo)
{
    if (nodo != NULL)
    {
        std::cout << nodo->obtenerDato() << " ";
        preOrder(nodo->obtenerHijoIzq());
        preOrder(nodo->obtenerHijoDer());
    }
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

template <class T>
<<<<<<< Updated upstream
std::list<T>& ArbolAVLOrd<T>::inOrdenLista(std::list<T> &lista)
{


    
    if (!this->esVacio())
    {
        (this->inOrdenListaRaiz(this-> raiz, lista)); 
=======
std::list<T> &ArbolAVLOrd<T>::inOrdenLista(std::list<T> &lista)
{

    if (!this->esVacio())
    {
        (this->inOrdenListaRaiz(this->raiz, lista));
>>>>>>> Stashed changes
    }
    return lista;
}

// esta es la forma recursiva
template <class T>
void ArbolAVLOrd<T>::inOrdenListaRaiz(NodoAVL<T> *nodo, std::list<T> &lista)
{
    if (nodo != nullptr)
    {
        inOrdenListaRaiz(nodo->obtenerHijoIzq(), lista);
        lista.push_back(nodo->obtenerDato());
        inOrdenListaRaiz(nodo->obtenerHijoDer(), lista);
    }
}
