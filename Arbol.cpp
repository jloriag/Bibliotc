/* 
 * File:   Arbol.cpp
 * Author: josue
 * 
 * Created on 19 de octubre de 2014, 03:40 PM
 */

#include "Arbol.h"

Arbol::Arbol() {
    setRaiz(NULL);
}

Nodo *&Arbol::getRaiz() {
    return _raiz;
}

void Arbol::setRaiz(Nodo *_raiz) {
    this->_raiz = _raiz;
}
bool Arbol::esHoja(Nodo* A){
	if((A->getIzq() == NULL) && (A->getDer() == NULL) )
		return true;
	else 
		return false;
}
int Arbol::Mayor(Nodo* A){

	if(A->getDer() == NULL && A->getIzq() != NULL)
		return Mayor(A->getIzq());
	else 
		if(esHoja(A))
			return A->getObjeto()->getCriterio();
		else 
			return A->getDer()->getObjeto()->getCriterio();
}

bool Arbol::agregar(Objeto *NuevoObjeto, Nodo*& a) {
    
    if(a == NULL){
		a = new Nodo(NuevoObjeto);
              
		if(getRaiz()==NULL){
			setRaiz(a);
		}
		return true;
	}
	else{
		if (a->getObjeto()->getCriterio() == NuevoObjeto->getCriterio())
			return false;
		else
			if (a->getObjeto()->getCriterio()  > NuevoObjeto->getCriterio())
				return agregar (NuevoObjeto, a->getIzq());
			else
				return agregar (NuevoObjeto, a->getDer());
	}

}

bool Arbol::agregar(Objeto *NuevoObjeto){
	return agregar(NuevoObjeto,getRaiz());
}
bool Arbol::eliminar(int _dato, Nodo*& A){
	// Busca el nodo que contiene a _dato
	if(A != NULL){
		if(A->getObjeto()->getCriterio() == _dato)
			return removerNodo(A);

		else
			if(_dato < A->getObjeto()->getCriterio())
				return eliminar(_dato, A->getIzq());
			else
				return eliminar(_dato, A->getDer());		     
	}else
		return false;
}
bool Arbol::eliminar(int _dato){
	return eliminar(_dato, getRaiz());
}


bool Arbol::removerNodo(Nodo*& A){
	//Remover el nodo indicado
	//estoy bajo el supuesto que no es NULL
	Nodo *aux;
	if(A->getIzq() == NULL){
		aux = A;
		A = A->getDer();
		delete aux;
		return true;
	}
	else
		if(A->getDer() == NULL){
			aux = A;
			A = A->getIzq();
			delete aux;		

		}else{
			int may = Mayor( A->getIzq());
                        Nodo* iz=A->getIzq();
			A->setObjeto(iz->getObjeto());
			eliminar(may, A->getIzq());
		}
		return true;
}

void Arbol::desplegarNivel(int n,Nodo* A){
	// desplegar los nodos del nivel n

	if(A != NULL){
		if (n == 0){
			cout<<A->getObjeto()->toString()<<"\n ";
                        
                }
		else
		{
			desplegarNivel(n-1,A->getIzq());
			desplegarNivel(n-1,A->getDer());
		}
	}

}
void Arbol::desplegarNivel(int n){
     cout<<"------Mostrando Objetos del Nivel: "<<n<<"----- "<<endl;
	desplegarNivel(n,getRaiz());

}
Arbol::~Arbol() {
}

/*Metodos de ArbolTipos*/

ArbolTipos::ArbolTipos():Arbol() {

}
//void ArbolTipos::deserialize(ifstream &entrada,ArbolTipos* g) {
//	int cantCl = -1;
//	int i = 0;
//	entrada.read((char*)&cantCl, sizeof(cantCl));
//
//	while(entrada.good() && i < cantCl) {
//		try {
//			Tipo* pac = NULL;
//
//			if(!entrada.good())
//				throw -1;
//
//			pac = new Tipo(entrada);
//
//			if(pac!= NULL)
//				g->agregar(pac); 
//		}
//		catch(int) {
//			cout<<"Ocurrio un error de lectura en el archivo"<<endl;
//		}
//		i++;
//	}
//}

//Este método serializa(guarda) la informacion de cada uno 
//bool ArbolTipos::serialize(ofstream &salida, ArbolTipos* g) {
//	int cantCitas = 0;
//	Iterador<Cita>* i = g->obtenerIterador();
//	cantCitas = g->totalCita();
//	
//	salida.write((char*)&cantCitas,sizeof(cantCitas));
//	
//	while(i->masElementos() && salida.good()) {
//
//		Cita* pac= (Cita*)i->proximoElemento();
//
//		pac->guardar(salida);
//	}
//	return salida.good();
//}
