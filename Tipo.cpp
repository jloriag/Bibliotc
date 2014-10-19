/* 
 * File:   Tipo.cpp
 * Author: josue
 * 
 * Created on 19 de octubre de 2014, 03:06 PM
 */

#include "Tipo.h"

Tipo::Tipo(int id,string descripcion):Objeto(id) {
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
  cout << "ID del Tipo:" << endl;
  cin >> _id;
  cout << "Descripcion:" << endl;
  cin >> _descripcion;
}

Tipo::~Tipo() {
}

