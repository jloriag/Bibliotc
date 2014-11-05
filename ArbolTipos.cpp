#include"ArbolTipos.h"


/*Metodos de ArbolTipos*/


ArbolTipos::ArbolTipos() {
	setRaiz(NULL);
}

NodoTipo *&ArbolTipos::getRaiz() {
	return _raiz;
}

void ArbolTipos::setRaiz(NodoTipo *_raiz) {
	this->_raiz = _raiz;
}

bool ArbolTipos::esHoja(NodoTipo* A) {
	if ((A->getIzq() == NULL) && (A->getDer() == NULL))
		return true;
	else
		return false;
}

int ArbolTipos::Mayor(NodoTipo* A) {

	if (A->getDer() == NULL && A->getIzq() != NULL)
		return Mayor(A->getIzq());
	else
	if (esHoja(A))
		return A->getTipo()->getID();
	else
		return A->getDer()->getTipo()->getID();
}

bool ArbolTipos::agregar(Tipo *NuevoObjeto, NodoTipo*& a) {

	if (a == NULL) {
		a = new NodoTipo(NuevoObjeto);

		if (getRaiz() == NULL) {
			setRaiz(a);
		}
		return true;
	}
	else {
		if (a->getTipo()->getID() == NuevoObjeto->getID())
			return false;
		else
		if (a->getTipo()->getID() > NuevoObjeto->getCriterio())
			return agregar(NuevoObjeto, a->getIzq());
		else
			return agregar(NuevoObjeto, a->getDer());
	}

}

bool ArbolTipos::agregar(Tipo *NuevoObjeto) {
	return agregar(NuevoObjeto, getRaiz());
}

bool ArbolTipos::eliminar(int _dato, NodoTipo*& A) {
	// Busca el nodo que contiene a _dato
	if (A != NULL) {
		if (A->getTipo()->getID() == _dato)
			return removerNodo(A);

		else
		if (_dato < A->getTipo()->getID())
			return eliminar(_dato, A->getIzq());
		else
			return eliminar(_dato, A->getDer());
	}
	else
		return false;
}

bool ArbolTipos::eliminar(int _dato) {
	return eliminar(_dato, getRaiz());
}

bool ArbolTipos::removerNodo(NodoTipo*& A) {
	//Remover el nodo indicado
	//estoy bajo el supuesto que no es NULL
	NodoTipo *aux;
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
		NodoTipo* iz = A->getIzq();
		A->setTipo(iz->getTipo());
		eliminar(may, A->getIzq());
	}
	return true;
}

void ArbolTipos::desplegarNivel(int n, NodoTipo* A) {
	// desplegar los nodos del nivel n

	if (A != NULL) {
		if (n == 0) {
			cout << A->getTipo()->toString() << "\n ";

		}
		else {
			desplegarNivel(n - 1, A->getIzq());
			desplegarNivel(n - 1, A->getDer());
		}
	}

}

void ArbolTipos::desplegarNivel(int n) {
	cout << "------Mostrando Objetos del Nivel: " << n << "----- " << endl;
	desplegarNivel(n, getRaiz());

}

bool ArbolTipos::encuentraTipo(int id){
	NodoTipo* & a = encuentra(id);
	if (a){
		return true;
	}
	else{
		return false;
	}

}

ArbolTipos::~ArbolTipos() {
}

void ArbolTipos::preOrden(NodoTipo* A) {
	// Raiz, Izquierda, Derecha
	if (A != NULL) {
		cout << A->getTipo()->toString() << " - ";
		preOrden(A->getIzq());
		preOrden(A->getDer());
	}

}

void ArbolTipos::enOrden(NodoTipo* A) {
	// Izquierda, Raiz, Derecha
	if (A != NULL) {
		enOrden(A->getIzq());
		cout << A->getTipo()->toString() << " - ";
		enOrden(A->getDer());
	}

}

void ArbolTipos::postOrden(NodoTipo* A) {
	// Izquierda, Derecha, Raiz
	if (A != NULL) {
		postOrden(A->getIzq());
		postOrden(A->getDer());
		cout << A->getTipo()->toString() << " - ";

	}

}

void ArbolTipos::preOrden() {
	preOrden(getRaiz());
}

void ArbolTipos::enOrden() {
	enOrden(getRaiz());
}

void ArbolTipos::postOrden() {
	postOrden(getRaiz());
}

int ArbolTipos::numeroDeHojas(NodoTipo* A) {

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

int ArbolTipos::nodosInternos(NodoTipo* A) {
	if (A == NULL) {
		return 0;
	}
	else {
		if (A->getDer() == NULL && A->getIzq() == NULL) {
			return nodosInternos(A->getIzq()) + numeroDeHojas(A->getDer());
		}
		else {
			return 1 + nodosInternos(A->getIzq()) + nodosInternos(A->getDer());
		}
	}
}

int ArbolTipos::nodosInternos() {
	return nodosInternos(getRaiz());
}

int ArbolTipos::numeroDeHojas() {
	return numeroDeHojas(getRaiz());
}

int ArbolTipos::numerodeNodos(){
	return nodosInternos() + numeroDeHojas();
}

NodoTipo*& ArbolTipos::encuentra(int _dato, NodoTipo*& A){
	if (A != NULL) {
		if (A->getTipo()->getID() == _dato)
			return A;

		else
		if (_dato < A->getTipo()->getID())
			return encuentra(_dato, A->getIzq());
		else
			return encuentra(_dato, A->getDer());
	}
	else{
//		return A;
	}

}
NodoTipo*& ArbolTipos:: encuentra(int _dato){
	return encuentra(_dato,getRaiz());
}
bool ArbolTipos::insertaISBN(int id, int isbn){
	NodoTipo* & a = encuentra(id);
	if (a){
		a->agregarISBN(isbn);
		return true;
	}
	else{
		return false;
	}
}
ListaISBN* ArbolTipos::obtenerListaISBN(int id){
	NodoTipo* & a = encuentra(id);
	if (a){
		return a->getListaISBN();
	}
	else{
		return NULL;
	}
	
}
string ArbolTipos::mostrarListarISBN(int id){
	ListaISBN* l = obtenerListaISBN(id);
	if (l){
		return l->toString();
	}
	else{
		return "No se encontro el tipo! \n";
	}

}



void ArbolTipos::deserialize(ifstream &entrada, ArbolTipos* g) {
    int cantCl = -1;
    int i = 0;
    entrada.read((char*) &cantCl, sizeof (cantCl));

    while (entrada.good() && i < cantCl) {
        try {
            Tipo* pac = NULL;

            if (!entrada.good())
                throw -1;

            pac = new Tipo(entrada);

            if (pac != NULL)
                g->agregar(pac);
        } catch (int) {
            cout << "Ocurrio un error de lectura en el archivo" << endl;
        }
        i++;
    }
}

//Este método serializa(guarda) la informacion de cada uno 

bool ArbolTipos::serialize(ofstream &salida, ArbolTipos* g) {
    //int cantCitas = 0;
    //Iterador<Cita>* i = g->obtenerIterador();
    //cantCitas = g->totalCita();
    int cantidadNodos=numerodeNodos();
   
    salida.write((char*) &cantidadNodos, sizeof (cantidadNodos));

//    while (i->masElementos() && salida.good()) {
//
//        Cita* pac = (Cita*) i->proximoElemento();
//
//        pac->guardar(salida);
//    }
    cargaNodos(getRaiz(),salida);
    return salida.good();
}

void ArbolTipos::cargaNodos(NodoTipo* A,ofstream &salida) {
    if (A != NULL) {
        enOrden(A->getIzq());
		A->getTipo()->guardar(salida);
        enOrden(A->getDer());
    }
}
 ArbolTipos:: ArbolTipos(ifstream&entrada){
     deserialize(entrada,this);
}

 bool  ArbolTipos::guardar(ofstream& salida){
	 return serialize(salida, (ArbolTipos*)this);
 }