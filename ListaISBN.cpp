#include"ListaISBN.h"

NodoISBN::NodoISBN(){
	setSig(NULL);
}
NodoISBN* NodoISBN::getSig()const {
	return _sig;
}

void NodoISBN::setSig(NodoISBN* NodoISBN) {
	_sig = NodoISBN;
}

int NodoISBN::getObjeto()const {
	return dato;
}

void NodoISBN::setObjeto(int d) {
	dato = d;
}

ListaISBN::ListaISBN() {
	setLargo(0);
}
void ListaISBN::setPrimero(NodoISBN* n){
	_primera = n;
}

NodoISBN* ListaISBN::getPrimero()const{
	return _primera;
}

int ListaISBN::getLargo()const{
	return _largo;
}
void ListaISBN::setLargo(int l){
	_largo = l;
}

void ListaISBN::Inserta(int datoNuevo) {
	NodoISBN *NodoISBNTemp, *NuevoNodoISBN;
	NuevoNodoISBN = new NodoISBN();
	NuevoNodoISBN->setObjeto(datoNuevo);
	if (getPrimero() == NULL)
		setPrimero(NuevoNodoISBN);
	else {
		NodoISBNTemp = getPrimero();
		while (NodoISBNTemp->getSig() != NULL)
			NodoISBNTemp = NodoISBNTemp->getSig();
		NodoISBNTemp->setSig(NuevoNodoISBN);
	}
	setLargo(getLargo() + 1);
}

string ListaISBN::toString() {

	NodoISBN *Actual = getPrimero();
	stringstream s;
	if (Actual != NULL){
		while (Actual != NULL) {
			s << Actual->getObjeto() << endl;
			Actual = Actual->getSig();
		}
	}
	else{
		s << "ListaISBN Vacia " << endl;
	}
	return s.str();

}

ListaISBN::~ListaISBN() {
	destruir();
}

NodoISBN *ListaISBN::locateInfo(int info){
	if (getPrimero() == NULL){
		return NULL;
	}
	else{
		return locateI(info, getPrimero());
	}
}

bool ListaISBN::borrar(int info){
	bool borrado = false;
	if (getPrimero() == NULL){
		return borrado;
	}
	else{
		NodoISBN *aux = locateInfo(info);
		if (aux != NULL){
			if (aux = getPrimero()){
				setPrimero(getPrimero()->getSig());
			}
			else {
				NodoISBN *temp = previous(info);
				temp->setSig(aux->getSig());
			}
			delete aux;
			borrado = true;
			setLargo(getLargo() - 1);
		}
		else{
			return borrado;
		}

	}
	return borrado;

}

void ListaISBN::destruir(){
	if (getPrimero() != NULL){
		while (getLargo()>0){
			borrar(getPrimero()->getObjeto());
		}
	}

}

/*Metodos Privados*/

NodoISBN *ListaISBN::locateI(int _info, NodoISBN* s){
	if (_info == s->getObjeto()){
		return s;
	}
	else{
		if (s->getSig() == NULL){
			return NULL;
		}
		else{
			return locateI(_info, s->getSig());
		}
	}

}

NodoISBN *ListaISBN::previous(int _info){
	//Devolver la dirrecion del NodoISBN que se encuentra antes del NodoISBN _info
	if (getPrimero() == NULL){
		return NULL;
	}
	else{
		NodoISBN *aux = getPrimero();
		if (aux->getObjeto() == _info){
			return NULL;
		}
		while (aux->getSig() != NULL){
			if (aux->getSig()->getObjeto() == _info)
				return aux;
			else
				aux = aux->getSig();
		}
		return NULL;

	}


}