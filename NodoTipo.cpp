#include "NodoTipo.h"


NodoTipo::NodoTipo(Tipo* obj) 
{
	setTipo(obj);
	setDer(NULL);
	setIzq(NULL);
	_listaISBN = new ListaISBN();
}



NodoTipo*&NodoTipo::getIzq() {
	return _izq;
}

void NodoTipo::setIzq(NodoTipo* _izq) {
	this->_izq = _izq;
}

NodoTipo*& NodoTipo::getDer() {
	return _der;
}

void NodoTipo::setDer(NodoTipo* _der) {
	this->_der = _der;
}

Tipo* NodoTipo::getTipo()const {
	return _Tipo;
}

void NodoTipo::setTipo(Tipo* _Tipo) {
	this->_Tipo = _Tipo;
}

NodoTipo::~NodoTipo() {
	_listaISBN->destruir();
	delete _listaISBN;
	delete _Tipo;
}

ListaISBN* NodoTipo::getListaISBN(){
	return _listaISBN;
}

void NodoTipo::setListaISBN(ListaISBN* l){
	_listaISBN = l;
}

void NodoTipo::agregarISBN(int isbn){
	_listaISBN->Inserta(isbn);
}

bool NodoTipo::borrarISBN(int isbn){
	return _listaISBN->borrar(isbn);
}

void NodoTipo::destruirISBN(){
	_listaISBN->destruir();
}

string NodoTipo::MostrarListaISBN(){
	return _listaISBN->toString();
}
