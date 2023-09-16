#include "ArbolBinarioOrd.h"

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
    this->raiz=NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
    if(this->raiz !=NULL){
        delete this->raiz;
        this->raiz=NULL;
    }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio(){
    return this->raiz==NULL;
}


template <class T>
bool ArbolBinarioOrd<T>::insertar(T& val){
    raiz= insertRec(raiz, val);
}

template <class T>
NodoBin<T>* ArbolBinarioOrd<T>::insertRec(NodoBin<T>* nodo, T valor){
    if (nodo == nullptr) {
        return new NodoBin<T>(valor);
    }

    if (valor < nodo->obtenerDato()) {
        if(nodo->obtenerHijoIzq()==nullptr)
            std::cout<<"Padre: "<<nodo->obtenerDato()<<" agregado izquierdo: "<<valor<<"\n";

        nodo->fijarHijoIzq(insertRec(nodo->obtenerHijoIzq(), valor));
    } else if (valor > nodo->obtenerDato()) {
        if(nodo->obtenerHijoDer()==nullptr)
            std::cout<<"Padre: "<<nodo->obtenerDato()<<" agregado derecho: "<<valor<<"\n";


        nodo->fijarHijoDer(insertRec(nodo->obtenerHijoDer(), valor));
        
    }

    return nodo;
}

template <class T>
int ArbolBinarioOrd<T>::altura(){

}

template <class T>
int ArbolBinarioOrd<T>::tamahno(){

}


template <class T>
bool ArbolBinarioOrd<T>::eliminar(T& val){

}

template <class T>
void ArbolBinarioOrd<T>::preOrden(){

}

template <class T>
void ArbolBinarioOrd<T>::inOrden(){

}

template <class T>
void ArbolBinarioOrd<T>::posOrden(){

}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden(){

}
