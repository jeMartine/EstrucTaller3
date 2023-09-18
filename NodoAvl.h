#ifndef NODOAVL_H
#define NODOAVL_H
template <class T>
class NodoAVL
{
private:
    T valor;
    NodoAVL<T> *izquierdo;
    NodoAVL<T> *derecho;
    int altura;
    public:
    NodoAVL(T &val);
    T obtenerValor();
    NodoAVL<T> *obtenerIzquierdo();
    NodoAVL<T> *obtenerDerecho();
    int obtenerAltura();
    void fijarValor( T &val);
    void fijarIzquierdo(NodoAVL<T> *nodo) ;
    void fijarDerecho(NodoAVL<T> *nodo) ;
    void fijarAltura(int alt);
    bool eshoja();
};
#include "NodoAvl.hxx"


#endif // NODOAVL_H
