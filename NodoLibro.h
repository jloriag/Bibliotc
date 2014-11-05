#ifndef NODOLIBRO_H
#define	NODOLIBRO_H
#include"Libros.h"
class NodoLibro
{
public:
	NodoLibro(Libros*);
	NodoLibro*&getIzq();
	void setIzq(NodoLibro*);
	NodoLibro*&getDer();
	void setDer(NodoLibro*);
	Libros* getLibros()const;
	void setLibros(Libros*);

	~NodoLibro();
private:
	NodoLibro *_izq;
	NodoLibro *_der;
	Libros* _Libros;
};
#endif

