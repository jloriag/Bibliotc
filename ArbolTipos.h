/*
 * File:   ArbolTipos.h
 * Author: josue
 *
 * Created on 30 de octubre de 2014, 04:08 PM
 */

#ifndef ARBOLTIPOS_H
#define	ARBOLTIPOS_H
#include"NodoTipo.h"
class ArbolTipos {
	NodoTipo* _raiz;
	int Mayor(NodoTipo*);
	bool agregar(Tipo *, NodoTipo*&);
	bool eliminar(int, NodoTipo*&);
	bool removerNodo(NodoTipo*&);
	bool esHoja(NodoTipo*);
	void desplegarNivel(int, NodoTipo*);

	int numeroDeHojas(NodoTipo*);
	int nodosInternos(NodoTipo*);
	NodoTipo*& encuentra(int, NodoTipo*&);
public:
	
	bool agregar(Tipo *);
	bool eliminar(int);
	NodoTipo *&getRaiz();
	void setRaiz(NodoTipo *);
	//Despliegues
	void desplegarNivel(int);
	void preOrden();
	void enOrden();
	void postOrden();
	int numeroDeHojas();
	int nodosInternos();

	int numerodeNodos();
	NodoTipo*& encuentra(int);
	bool encuentraTipo(int);
	ListaISBN* obtenerListaISBN(int);
	string mostrarListarISBN(int);
	bool insertaISBN(int,int);
	void preOrden(NodoTipo*);
	void enOrden(NodoTipo*);
	void postOrden(NodoTipo*);
	ArbolTipos();
	~ArbolTipos();
	void deserialize(ifstream&, ArbolTipos*);
	bool serialize(ofstream&, ArbolTipos*);
	ArbolTipos(ifstream&);
	bool guardar(ofstream&);
	void cargaNodos(NodoTipo*, ofstream&);
};


#endif	/* ARBOLTIPOS_H */

