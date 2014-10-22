/* 
 * File:   Tipo.cpp
 * Author: josue
 * 
 * Created on 19 de octubre de 2014, 03:06 PM
 */

#include "Tipo.h"

Tipo::Tipo():Objeto() {
_id=0;
setDescripcion("");
}

Tipo::Tipo(int id,string descripcion):Objeto() {
    setID(id);
    setDescripcion(descripcion);
}

int Tipo::getID()const {
    return _id;
}

string Tipo::getDescripcion()const {
    return _descripcion;
}

void Tipo::setID(int id) {
    this->setCriterio(id);
    _id = id;
}

void Tipo::setDescripcion(string d) {
    _descripcion = d;
    
}
string Tipo::toString() {
  stringstream s;
  s << "ID del Tipo: " << getID() << endl << "Descripcion: " << getDescripcion() << endl;		
  return s.str();
}

void Tipo::Captura() {
   int id; 
  cout << "ID del Tipo:" << endl;
  cin >> id;
  setID(id);
  cout << "Descripcion:" << endl;
  cin >> _descripcion;
}

void Tipo::deserialize(ifstream &entrada,Tipo* tipo) {
	entrada.read((char*)&tipo->_id, sizeof(tipo->_id));
	tipo->_criterio = tipo->_id;
    tipo->_descripcion=sstring::deserialize(entrada);	
	if(!entrada.good())
		throw -1;
}


//Este método serializa(guarda) la informacion 
//en el archivo
bool Tipo::serialize(ofstream &salida,Tipo* tipo) {
	salida.write((char*)&tipo->_id, sizeof(tipo->_id));
	sstring::serialize(salida,tipo->_descripcion);
	return salida.good();
}
bool Tipo::guardar(ofstream& salida)
{
    return serialize(salida, (Tipo*)this);
}

Tipo::Tipo(ifstream& entrada)
{
    deserialize(entrada, this);
}

Tipo::~Tipo() {
}

