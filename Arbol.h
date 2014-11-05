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
	int Mayor(Nodo*);
	bool agregar(Objeto *, Nodo*&);
	bool eliminar(int, Nodo*&);
	bool removerNodo(Nodo*&);
	bool esHoja(Nodo*);
	void desplegarNivel(int, Nodo*);

	int numeroDeHojas(Nodo*);
	int nodosInternos(Nodo*);
public:
	Arbol();
	bool agregar(Objeto *);
	bool eliminar(int);
	Nodo *&getRaiz();
	void setRaiz(Nodo *);
	//Despliegues
	void desplegarNivel(int);
	void preOrden();
	void enOrden();
	void postOrden();
	int numeroDeHojas();
	int nodosInternos();

	int numerodeNodos();
	void preOrden(Nodo*);
	void enOrden(Nodo*);
	void postOrden(Nodo*);
	~Arbol();

};


#endif	/* ARBOL_H */

