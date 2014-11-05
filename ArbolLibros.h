#ifndef ARBOLLIBROS_H
#define	ARBOLLIBROS_H
#include"NodoLibro.h"
class ArbolLibros
{
private:
	NodoLibro* _raiz;
	int Mayor(NodoLibro*);
	bool agregar(Libros *, NodoLibro*&);
	bool eliminar(int, NodoLibro*&);
	bool eliminarPorTipo(int, NodoLibro*&);
	bool removerNodoLibro(NodoLibro*&);
	bool esHoja(NodoLibro*);
	void desplegarNivel(int, NodoLibro*);

	int numeroDeHojas(NodoLibro*);
	int NodoLibrosInternos(NodoLibro*);
public:
	void eliminarNivel(int, NodoLibro*);
	ArbolLibros();
	bool agregar(Libros *);
	bool eliminar(int);
	bool eliminarPorTipo(int);
	int eliminarTodosTipos(int);
	NodoLibro *&getRaiz();
	void setRaiz(NodoLibro *);
	//Despliegues
	void desplegarNivel(int);
	void preOrden();
	void enOrden();
	void postOrden();
	int numeroDeHojas();
	int nodosInternos();

	int numerodeNodos();
	void preOrden(NodoLibro*);
	void enOrden(NodoLibro*);
	void postOrden(NodoLibro*);
	~ArbolLibros();
	int minivel(int,int, NodoLibro*);

};
#endif
