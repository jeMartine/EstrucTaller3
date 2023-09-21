#ifndef ARBOLAVLORD_H
#define ARBOLAVLORD_H
#include "NodoAvl.h"
#include <list>

template <class T>

class ArbolAVLOrd
{
private:
    NodoAVL<T> *raiz;

public:
    ArbolAVLOrd();
    ~ArbolAVLOrd();
    T datoRaiz();
    bool esVacio();
    int size();
    int size(NodoAVL<T> *nodo);
    int calcHeight(NodoAVL<T> *nodo);
    int tamahno();
    int tamano(NodoAVL<T> *nodo);
    bool insert(T &val); // modificar para que sea AVL
    bool erase(T &val);  // modificar para que sea AVL

    void updateHeight(NodoAVL<T> *nodo);
    NodoAVL<T> *LLR(NodoAVL<T> *nodo);
    NodoAVL<T> *RRR(NodoAVL<T> *nodo);
    NodoAVL<T> *LRR(NodoAVL<T> *nodo);
    NodoAVL<T> *RLR(NodoAVL<T> *nodo);
    NodoAVL<T> *balanceee(NodoAVL<T> *nodo);

    NodoAVL<T> *rotacionIzq(NodoAVL<T> *nodo);
    NodoAVL<T> *rotacionDer(NodoAVL<T> *nodo);
    int getBalanceFactor(NodoAVL<T> *nodo);

    // NodoAVL<T> *insertRec(NodoAVL<T> *nodo, T valor);
    NodoAVL<T> *insertRec(NodoAVL<T> *nodo, NodoAVL<T> *parent, T valor);

    NodoAVL<T> *eraseNode(T &val, NodoAVL<T> *nodo);
    int obtenerCantidadHijos(NodoAVL<T> *nodo);
    NodoAVL<T> obtenerHijoNoVacio(NodoAVL<T> *nodo);
    void preOrden();
    void preOrden(NodoAVL<T> *nodo);
    void inOrden();
    void inOrden(NodoAVL<T> *nodo);
    void posOrden();
    void posOrden(NodoAVL<T> *nodo);
    void nivelOrden();

<<<<<<< Updated upstream
   std::list<T>& inOrdenLista(std::list<T> &lista);
=======
    std::list<T> &inOrdenLista(std::list<T> &lista);
>>>>>>> Stashed changes
    void inOrdenListaRaiz(NodoAVL<T> *nodo, std::list<T> &lista);
};

#include "ArbolAVLOrd.hxx"

#endif // ARBOLAVL_H
