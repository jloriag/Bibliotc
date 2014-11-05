#ifndef NODOTIPO_H
#define	NODOTIPO_H
#include"ListaISBN.h"
#include"Tipo.h"
class NodoTipo
{
private:
	ListaISBN* _listaISBN;
	NodoTipo *_izq;
	NodoTipo *_der;
	Tipo* _Tipo;

public:

	NodoTipo*&getIzq();
	void setIzq(NodoTipo*);
	NodoTipo*&getDer();
	void setDer(NodoTipo*);
	Tipo* getTipo()const;
	void setTipo(Tipo*);

	NodoTipo(Tipo*);
	ListaISBN* getListaISBN();
	void setListaISBN(ListaISBN*);
	void agregarISBN(int);
	bool borrarISBN(int);
	void destruirISBN();
	string MostrarListaISBN();
	~NodoTipo();
};
#endif
