#include "Lectura.h"


Tipo* Lectura:: LeeTipo(){
	Tipo* t = new Tipo();
	system("cls");
	t->Captura();
	return t;
}

Libros* Lectura::LeeLibro(ArbolTipos*& tipos){
	Libros* libros = new Libros();
	system("cls");
	libros->Captura();
	if (tipos->encuentraTipo(libros->getTipo())){
	}
	else{
		_flushall();
		cout << "Ha Insertado un  tipo no existente!\n";
		cout << "Inserte la descripcion del nuevo tipo!  \n";
		Tipo* tipo = new Tipo();
		cout << "Descripcion:" << endl;
		cin >> cadena;
		tipo->setID(libros->getTipo());
		tipo->setDescripcion(cadena);
		tipos->agregar(tipo);
	}
	tipos->insertaISBN(libros->getTipo(),libros->getISBN());
	return libros;
}