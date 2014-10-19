/* 
 * File:   Nodo.cpp
 * Author: josue
 * 
 * Created on 19 de octubre de 2014, 03:34 PM
 */

#include "Nodo.h"

Nodo::Nodo(Objeto* ob) {
    setObjeto(ob);
    setDer(NULL);
    setIzq(NULL);
}

Nodo*&Nodo::getIzq() {
    return _izq;
}

void Nodo::setIzq(Nodo* _izq) {
    this->_izq = _izq;
}

Nodo*& Nodo::getDer() {
    return _der;
}

void Nodo::setDer(Nodo* _der) {
    this->_der = _der;
}

Objeto* Nodo::getObjeto()const {
    return _objeto;
}

void Nodo::setObjeto(Objeto* _objeto) {
    this->_objeto = _objeto;
}

Nodo::~Nodo() {
    delete _objeto;
}

