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

bool Arbol::agregar(Objeto *NuevoObjeto, Nodo*& a) {
    
    if(a == NULL){
		a = new Nodo(NuevoObjeto);
              
		if(getRaiz()==NULL){
			setRaiz(a);
		}
		return true;
	}
	else{
		if (a->getObjeto()->getCriterio() == NuevoObjeto->getCriterio())
			return false;
		else
			if (a->getObjeto()->getCriterio()  > NuevoObjeto->getCriterio())
				return agregar (NuevoObjeto, a->getIzq());
			else
				return agregar (NuevoObjeto, a->getDer());
	}

}

bool Arbol::agregar(Objeto *NuevoObjeto){
	return agregar(NuevoObjeto,getRaiz());
}

Arbol::~Arbol() {
}

