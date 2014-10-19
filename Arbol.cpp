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

//Nodo* Arbol:: eliminar(int criterio,Nodo*& a){
////    if(a==NULL)
////        return false;
////    if(a->getObjeto()->getCriterio()==criterio){
////        if(a->getIzq()==NULL){
////        
////        }
////    }
//    
//    if(criterio< a->getObjeto()->getCriterio()){
//        if(a->getIzq()!=NULL){
//            return eliminar(criterio,a->getIzq());
//        }
//        else{
//            return NULL;
//        }
//    } else if(criterio> a->getObjeto()->getCriterio()){
//        if(a->getDer()!=NULL){
//            return eliminar(criterio,a->getDer());
//        }else{
//            return NULL;
//        }
//    
//    }else{
//        if(a->getIzq()!=NULL&&a->getDer()!=NULL){
//            
//        
//        }
//    
//    }
//    
//     if (value < this->value) {
//            if (left != NULL)
//                  return left->remove(value, this);
//            else
//                  return NULL;
//      } else if (value > this->value) {
//            if (right != NULL)
//                  return right->remove(value, this);
//            else
//                  return NULL;
//      } else {
//            if (left != NULL && right != NULL) {
//                  this->value = right->minValue();
//                  return right->remove(this->value, this);
//            } else if (parent->left == this) {
//                  parent->left = (left != NULL) ? left : right;
//                  return this;
//            } else if (parent->right == this) {
//                  parent->right = (left != NULL) ? left : right;
//                  return this;
//            }
//      }
//}

Arbol::~Arbol() {
}

