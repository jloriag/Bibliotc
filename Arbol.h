/* 
 * File:   Arbol.h
 * Author: josue
 *
 * Created on 19 de octubre de 2014, 03:40 PM
 */

#ifndef ARBOL_H
#define	ARBOL_H
#include"Nodo.h"
class Arbol {
    private:
    Nodo* _raiz;
    bool agregar(Objeto *, Nodo*&);
public:
    Arbol();
    bool agregar(Objeto *);
//    Nodo* eliminar(int,Nodo*&);
    Nodo *&getRaiz();
    void setRaiz(Nodo *);
   ~Arbol();
   
 

};

#endif	/* ARBOL_H */

