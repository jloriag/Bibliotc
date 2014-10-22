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
    int  Mayor(Nodo* );
    bool agregar(Objeto *, Nodo*&);
    bool eliminar(int, Nodo*&);
    bool removerNodo(Nodo*&);
    bool esHoja(Nodo*);
    void desplegarNivel(int,Nodo*);
public:
    Arbol();
    bool agregar(Objeto *);
    bool eliminar(int);
    Nodo *&getRaiz();
    void setRaiz(Nodo *);
    void desplegarNivel(int);

   ~Arbol();
   
};

class ArbolTipos:public Arbol{
    
public:
    ArbolTipos();
    //static void deserialize(ifstream&, ArbolTipos*);
    //static bool serialize(ofstream&, ArbolTipos*);

};
#endif	/* ARBOL_H */

