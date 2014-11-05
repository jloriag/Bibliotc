#ifndef ListaISBNISBN_H
#define	ListaISBNISBN_H
#include"Objeto.h"
class NodoISBN{
private:
	int dato;
	NodoISBN* _sig;
public:
	NodoISBN();
	NodoISBN* getSig()const;
	void setSig(NodoISBN*);

	int getObjeto()const;
	void setObjeto(int);
};
//ListaISBN Simple de Objetos
class ListaISBN {
public:
	ListaISBN();
	void setPrimero(NodoISBN*);
	NodoISBN* getPrimero()const;

	int getLargo()const;
	void setLargo(int);
	virtual void Inserta(int);

	NodoISBN* locateInfo(int);
	virtual bool borrar(int);
	virtual string toString();
	virtual void destruir();
	~ListaISBN();
private:
	NodoISBN* _primera;
	int _largo;

	//Metodo para localizar Info
	NodoISBN *locateI(int, NodoISBN*);
	NodoISBN *previous(int);
};

#endif	/* ListaISBN_H */