#ifndef LECTURA_H
#define	LECTURA_H
#include"Tipo.h"
#include"Libros.h"
#include"ArbolTipos.h"
class Lectura
{
private:
	string cadena;
public:
	Tipo* LeeTipo();
	Libros* LeeLibro(ArbolTipos*&);
};
#endif

