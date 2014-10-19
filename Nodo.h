/* 
 * File:   Nodo.h
 * Author: josue
 *
 * Created on 19 de octubre de 2014, 03:34 PM
 */

#ifndef NODO_H
#define	NODO_H
#include"objeto.h"

class Nodo {
public:
    Nodo(Objeto*);
    Nodo*&getIzq();
    void setIzq(Nodo*);
    Nodo*&getDer();
    void setDer(Nodo*);
    Objeto* getObjeto()const;
    void setObjeto( Objeto* );
    
    ~Nodo();
private:
    Nodo *_izq;
    Nodo *_der;
    Objeto* _objeto;
};

#endif	/* NODO_H */

