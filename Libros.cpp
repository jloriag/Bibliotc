/* 
 * File:   Libros.cpp
 * Author: josue
 * 
 * Created on 25 de octubre de 2014, 09:43 PM
 */

#include "Libros.h"

Libros::Libros() : Objeto() {
    setISBN(0);
    setAutor("Autor No Definido");
    setDescripcion("Descripcion No definida");
    setTitulo("Titulo No definido");
    setTipo(0);
}

string Libros::getTitilo()const {
    return _titulo;
}

string Libros::getAutor()const {
    return _autor;
}

string Libros::getDescrpcion()const {
    return _descripcion;
}

int Libros::getTipo()const {
    return _tipo;
}

void Libros::setTitulo(string t) {
    _titulo = t;
}

void Libros::setAutor(string a) {
    _autor = a;
}

void Libros::setDescripcion(string d) {
    _descripcion = d;

}

void Libros::setTipo(int t) {
    _tipo = t;
}

int Libros::getISBN()const {
    return getCriterio();
}

void Libros::setISBN(int cr) {
    setCriterio(cr);
}

Libros::Libros(ifstream& entrada):Objeto(entrada) {
    deserialize(entrada, this);
}

 void Libros::deserialize(ifstream& entrada, Libros* libro) {
    libro->_titulo = sstring::deserialize(entrada);
    libro->_autor = sstring::deserialize(entrada);
    libro->_descripcion = sstring::deserialize(entrada);
    entrada.read((char*) &libro->_tipo, sizeof (libro->_tipo));
    if (!entrada.good())
        throw -1;
}

 bool Libros::serialize(ofstream& salida, Libros* libro) {
    sstring::serialize(salida, libro->_titulo);
    sstring::serialize(salida, libro->_autor);
    sstring::serialize(salida, libro->_descripcion);
    salida.write((char*) &libro->_tipo, sizeof (libro->_tipo));
    return salida.good();
}

bool Libros::guardar(ofstream& salida)
{
    return Objeto::guardar(salida)&&serialize(salida, (Libros*)this);
}


string Libros::toString() {
  stringstream s;
  s <<"ISBN: "<<getISBN()<<endl << "Titulo del Libro: " << getTitilo() << endl << "Autor: " << getAutor() << endl;
  s<<"Descripcion"<<getDescrpcion()<<endl<<"Tipo: "<<getTipo()<<endl;
  return s.str();
}

void Libros::Captura() {
	_flushall();
  cout << "ISBN del Libro:" << endl;
  cin >> _criterio;
  cout << "Titulo:"<<endl;
  cin >> _titulo;
  cout << "Autor:" << endl;
  cin >> _autor;
  cout << "Descripcion:" << endl;
  cin >> _descripcion;
  cout << "Tipo:"<<endl;
  cin >> _tipo;
}

Libros::~Libros() {
}

