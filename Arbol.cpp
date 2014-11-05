/* 
 * File:   Arbol.cpp
 * Author: josue
 * 
 * Created on 19 de octubre de 2014, 03:40 PM
 */

#include "Arbol.h"

Arbol::Arbol() {
    setRaiz(NULL);
}

Nodo *&Arbol::getRaiz() {
    return _raiz;
}

void Arbol::setRaiz(Nodo *_raiz) {
    this->_raiz = _raiz;
}

bool Arbol::esHoja(Nodo* A) {
    if ((A->getIzq() == NULL) && (A->getDer() == NULL))
        return true;
    else
        return false;
}

int Arbol::Mayor(Nodo* A) {

    if (A->getDer() == NULL && A->getIzq() != NULL)
        return Mayor(A->getIzq());
    else
        if (esHoja(A))
        return A->getObjeto()->getCriterio();
    else
        return A->getDer()->getObjeto()->getCriterio();
}

bool Arbol::agregar(Objeto *NuevoObjeto, Nodo*& a) {

    if (a == NULL) {
        a = new Nodo(NuevoObjeto);

        if (getRaiz() == NULL) {
            setRaiz(a);
        }
        return true;
    } else {
        if (a->getObjeto()->getCriterio() == NuevoObjeto->getCriterio())
            return false;
        else
            if (a->getObjeto()->getCriterio() > NuevoObjeto->getCriterio())
            return agregar(NuevoObjeto, a->getIzq());
        else
            return agregar(NuevoObjeto, a->getDer());
    }

}

bool Arbol::agregar(Objeto *NuevoObjeto) {
    return agregar(NuevoObjeto, getRaiz());
}

bool Arbol::eliminar(int _dato, Nodo*& A) {
    // Busca el nodo que contiene a _dato
    if (A != NULL) {
        if (A->getObjeto()->getCriterio() == _dato)
            return removerNodo(A);

        else
            if (_dato < A->getObjeto()->getCriterio())
            return eliminar(_dato, A->getIzq());
        else
            return eliminar(_dato, A->getDer());
    } else
        return false;
}

bool Arbol::eliminar(int _dato) {
    return eliminar(_dato, getRaiz());
}

bool Arbol::removerNodo(Nodo*& A) {
    //Remover el nodo indicado
    //estoy bajo el supuesto que no es NULL
    Nodo *aux;
    if (A->getIzq() == NULL) {
        aux = A;
        A = A->getDer();
        delete aux;
        return true;
    } else
        if (A->getDer() == NULL) {
        aux = A;
        A = A->getIzq();
        delete aux;

    } else {
        int may = Mayor(A->getIzq());
        Nodo* iz = A->getIzq();
        A->setObjeto(iz->getObjeto());
        eliminar(may, A->getIzq());
    }
    return true;
}

void Arbol::desplegarNivel(int n, Nodo* A) {
    // desplegar los nodos del nivel n

    if (A != NULL) {
        if (n == 0) {
            cout << A->getObjeto()->toString() << "\n ";

        } else {
            desplegarNivel(n - 1, A->getIzq());
            desplegarNivel(n - 1, A->getDer());
        }
    }

}

void Arbol::desplegarNivel(int n) {
    cout << "------Mostrando Objetos del Nivel: " << n << "----- " << endl;
    desplegarNivel(n, getRaiz());

}

Arbol::~Arbol() {
}

void Arbol::preOrden(Nodo* A) {
    // Raiz, Izquierda, Derecha
    if (A != NULL) {
        cout << A->getObjeto()->toString() << " - ";
        preOrden(A->getIzq());
        preOrden(A->getDer());
    }

}

void Arbol::enOrden(Nodo* A) {
    // Izquierda, Raiz, Derecha
    if (A != NULL) {
        enOrden(A->getIzq());
        cout << A->getObjeto()->toString() << " - ";
        enOrden(A->getDer());
    }

}

void Arbol::postOrden(Nodo* A) {
    // Izquierda, Derecha, Raiz
    if (A != NULL) {
        postOrden(A->getIzq());
        postOrden(A->getDer());
        cout << A->getObjeto()->toString() << " - ";

    }

}

void Arbol::preOrden() {
    preOrden(getRaiz());
}

void Arbol::enOrden() {
    enOrden(getRaiz());
}

void Arbol::postOrden() {
    postOrden(getRaiz());
}

int Arbol::numeroDeHojas(Nodo* A) {

    if (A == NULL) {
        return 0;
    } else {
        if (A->getDer() == NULL && A->getIzq() == NULL) {
            return 1 + numeroDeHojas(A->getIzq()) + numeroDeHojas(A->getDer());
        } else {
            return numeroDeHojas(A->getIzq()) + numeroDeHojas(A->getDer());
        }
    }
}

int Arbol::nodosInternos(Nodo* A) {
    if (A == NULL) {
        return 0;
    } else {
        if (A->getDer() == NULL && A->getIzq() == NULL) {
            return nodosInternos(A->getIzq()) + numeroDeHojas(A->getDer());
        } else {
            return 1 + nodosInternos(A->getIzq()) + nodosInternos(A->getDer());
        }
    }
}

int Arbol::nodosInternos() {
    return nodosInternos(getRaiz());
}

int Arbol::numeroDeHojas() {
    return numeroDeHojas(getRaiz());
}

int Arbol:: numerodeNodos(){
     return nodosInternos()+numeroDeHojas();
 }
