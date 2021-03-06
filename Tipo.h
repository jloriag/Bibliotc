/*
* File:   Tipo.h
* Author: josue
*
* Created on 19 de octubre de 2014, 03:06 PM
*/

#ifndef TIPO_H
#define	TIPO_H
#include"objeto.h"
#include"Arbol.h"
class Tipo :public Objeto {
public:
	Tipo(int, string);
	Tipo();
	~Tipo();

	int getID()const;
	string getDescripcion()const;
	void setID(int);
	void setDescripcion(string);



	virtual string toString();
	virtual void Captura();

	//Manejo de Archivos
	Tipo(ifstream&);
	static void deserialize(ifstream&, Tipo*);
	static bool serialize(ofstream&, Tipo*);
	virtual bool guardar(ofstream&);
private:
	// int _id; ID es el criterio
	string _descripcion;
};

#endif	/* TIPO_H */

