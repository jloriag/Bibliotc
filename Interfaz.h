/* 
 * File:   Interfaz.h
 * Author: josue
 *
 * Created on 21 de octubre de 2014, 07:47 PM
 */

#ifndef INTERFAZ_H
#define	INTERFAZ_H
#include"ArbolTipos.h"
#include"ArbolLibros.h"
#include"Lectura.h"
class Interfaz {
public:
    Interfaz();
    virtual ~Interfaz();
    void menuPrinpicipal();


	char MenuPrincipal();

	//Tipos
	char MenuTipos();
	void MenuAgregarTipos();
	void MenuBorrarTipoCodigo();


	char MenuLibros();
	char MenuEliminarLibros();
	void BorrarLibros();
	void MenuAgregarLibros();
	void MenuBorrarLibroCodigo();
	void MenuBorrarLibrosTipos();

	char MenuConsultas();


	void Principal();
	void Tipos();
	void Libros();

private:

	ArbolTipos *_arboltipos;
	ArbolLibros *_arbollibros;
	int opcionNum;
	char opcion;
	char opcionPrincipal;
	bool insert;
	Lectura _lectura;
	static const string archivo;
};

#endif	/* INTERFAZ_H */

