#include "NodoLibro.h"


/*
* File:   NodoLibro.cpp
* Author: josue
*
* Created on 19 de octubre de 2014, 03:34 PM
*/

#include "NodoLibro.h"

NodoLibro::NodoLibro(Libros* ob) {
	setLibros(ob);
	setDer(NULL);
	setIzq(NULL);
}

NodoLibro*&NodoLibro::getIzq() {
	return _izq;
}

void NodoLibro::setIzq(NodoLibro* _izq) {
	this->_izq = _izq;
}

NodoLibro*& NodoLibro::getDer() {
	return _der;
}

void NodoLibro::setDer(NodoLibro* _der) {
	this->_der = _der;
}

Libros* NodoLibro::getLibros()const {
	return _Libros;
}

void NodoLibro::setLibros(Libros* _Libros) {
	this->_Libros = _Libros;
}

NodoLibro::~NodoLibro() {
	delete _Libros;
}


