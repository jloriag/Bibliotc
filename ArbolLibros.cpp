#include "ArbolLibros.h"


ArbolLibros::ArbolLibros() {
	setRaiz(NULL);
}

NodoLibro *&ArbolLibros::getRaiz() {
	return _raiz;
}

void ArbolLibros::setRaiz(NodoLibro *_raiz) {
	this->_raiz = _raiz;
}

bool ArbolLibros::esHoja(NodoLibro* A) {
	if ((A->getIzq() == NULL) && (A->getDer() == NULL))
		return true;
	else
		return false;
}

int ArbolLibros::Mayor(NodoLibro* A) {

	if (A->getDer() == NULL && A->getIzq() != NULL)
		return Mayor(A->getIzq());
	else
	if (esHoja(A))
		return A->getLibros()->getISBN();
	else
		return A->getDer()->getLibros()->getISBN();
}

bool ArbolLibros::agregar(Libros *NuevoObjeto, NodoLibro*& a) {

	if (a == NULL) {
		a = new NodoLibro(NuevoObjeto);

		if (getRaiz() == NULL) {
			setRaiz(a);
		}
		return true;
	}
	else {
		if (a->getLibros()->getISBN() == NuevoObjeto->getCriterio())
			return false;
		else
		if (a->getLibros()->getISBN() > NuevoObjeto->getCriterio())
			return agregar(NuevoObjeto, a->getIzq());
		else
			return agregar(NuevoObjeto, a->getDer());
	}

}

bool ArbolLibros::agregar(Libros *NuevoObjeto) {
	return agregar(NuevoObjeto, getRaiz());
}

bool ArbolLibros::eliminar(int _dato, NodoLibro*& A) {
	// Busca el NodoLibro que contiene a _dato
	if (A != NULL) {
		if (A->getLibros()->getISBN() == _dato)
			return removerNodoLibro(A);

		else
		if (_dato < A->getLibros()->getISBN())
			return eliminar(_dato, A->getIzq());
		else
			return eliminar(_dato, A->getDer());
	}
	else
		return false;
}

bool ArbolLibros::eliminar(int _dato) {
	return eliminar(_dato, getRaiz());
}
bool ArbolLibros::eliminarPorTipo(int  _dato, NodoLibro*& A){
	if (A != NULL) {
		if (A->getLibros()->getTipo() == _dato)
			return removerNodoLibro(A);

		else
		if (_dato < A->getLibros()->getTipo())
			return eliminar(_dato, A->getIzq());
		else
			return eliminar(_dato, A->getDer());
	}
	else
		return false;

}

bool ArbolLibros::eliminarPorTipo(int tipo){
	return eliminarPorTipo(tipo, getRaiz());
}

int ArbolLibros::eliminarTodosTipos(int tipo){
	int cont=0;
	while (eliminarPorTipo(tipo)){
		cont++;
	}
	return cont;
}

bool ArbolLibros::removerNodoLibro(NodoLibro*& A) {
	//Remover el NodoLibro indicado
	//estoy bajo el supuesto que no es NULL
	NodoLibro *aux;
	if (A->getIzq() == NULL) {
		aux = A;
		A = A->getDer();
		delete aux;
		return true;
	}
	else
	if (A->getDer() == NULL) {
		aux = A;
		A = A->getIzq();
		delete aux;

	}
	else {
		int may = Mayor(A->getIzq());
		NodoLibro* iz = A->getIzq();
		A->setLibros(iz->getLibros());
		eliminar(may, A->getIzq());
	}
	return true;
}

void ArbolLibros::desplegarNivel(int n, NodoLibro* A) {
	// desplegar los NodoLibros del nivel n

	if (A != NULL) {
		if (n == 0) {
			cout << A->getLibros()->toString() << "\n ";

		}
		else {
			desplegarNivel(n - 1, A->getIzq());
			desplegarNivel(n - 1, A->getDer());
		}
	}

}

void  ArbolLibros::eliminarNivel(int nivel, NodoLibro* A){
	if (A != NULL) {
		if (nivel == 0) {
			removerNodoLibro(A);

		}
		else {
			desplegarNivel(nivel - 1, A->getIzq());
			desplegarNivel(nivel - 1, A->getDer());
		}
	}
}

void ArbolLibros::desplegarNivel(int n) {
	cout << "------Mostrando Objetos del Nivel: " << n << "----- " << endl;
	desplegarNivel(n, getRaiz());

}

ArbolLibros::~ArbolLibros() {
}

void ArbolLibros::preOrden(NodoLibro* A) {
	// Raiz, Izquierda, Derecha
	if (A != NULL) {
		cout << A->getLibros()->toString() << " - ";
		preOrden(A->getIzq());
		preOrden(A->getDer());
	}

}

void ArbolLibros::enOrden(NodoLibro* A) {
	// Izquierda, Raiz, Derecha
	if (A != NULL) {
		enOrden(A->getIzq());
		cout << A->getLibros()->toString() << " - ";
		enOrden(A->getDer());
	}

}

void ArbolLibros::postOrden(NodoLibro* A) {
	// Izquierda, Derecha, Raiz
	if (A != NULL) {
		postOrden(A->getIzq());
		postOrden(A->getDer());
		cout << A->getLibros()->toString() << " - ";

	}

}

void ArbolLibros::preOrden() {
	preOrden(getRaiz());
}

void ArbolLibros::enOrden() {
	enOrden(getRaiz());
}

void ArbolLibros::postOrden() {
	postOrden(getRaiz());
}

int ArbolLibros::numeroDeHojas(NodoLibro* A) {

	if (A == NULL) {
		return 0;
	}
	else {
		if (A->getDer() == NULL && A->getIzq() == NULL) {
			return 1 + numeroDeHojas(A->getIzq()) + numeroDeHojas(A->getDer());
		}
		else {
			return numeroDeHojas(A->getIzq()) + numeroDeHojas(A->getDer());
		}
	}
}

int ArbolLibros::NodoLibrosInternos(NodoLibro* A) {
	if (A == NULL) {
		return 0;
	}
	else {
		if (A->getDer() == NULL && A->getIzq() == NULL) {
			return NodoLibrosInternos(A->getIzq()) + numeroDeHojas(A->getDer());
		}
		else {
			return 1 + NodoLibrosInternos(A->getIzq()) + NodoLibrosInternos(A->getDer());
		}
	}
}

int ArbolLibros::nodosInternos() {
	return NodoLibrosInternos
		(getRaiz());
}

int ArbolLibros::numeroDeHojas() {
	return numeroDeHojas(getRaiz());
}

int ArbolLibros::numerodeNodos(){
	return nodosInternos() + numeroDeHojas();
}
int ArbolLibros::minivel(int a,int i, NodoLibro* n){

	if (n != NULL) {
		if (n->getLibros()->getISBN() == a) {
			return i;

		}
		else {
			return minivel(a, i + 1, n->getDer());
			return minivel(a, i + 1, n->getIzq());
		}
	}

}