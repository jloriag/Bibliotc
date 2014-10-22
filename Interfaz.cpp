/* 
 * File:   Interfaz.cpp
 * Author: josue
 * 
 * Created on 21 de octubre de 2014, 07:47 PM
 */

#include "Interfaz.h"
#include "Arbol.h"
const string Interfaz::archivo = "libros.dat";
Interfaz::Interfaz() {
//	ifstream entrada(archivo.c_str());
//	Tipo *t = new Tipo(entrada);
//	cout << t->toString();
}
void Interfaz::menuPrinpicipal(){
//ofstream salida(archivo.c_str());
//Tipo* t=new Tipo();
//t->Captura();
//t->guardar(salida);
//salida.close();
    Arbol *a=new ArbolTipos();
    Tipo *t =new Tipo();
    t->Captura();
    Tipo *t2 =new Tipo();
    t2->Captura();
     Tipo *t3 =new Tipo();
    t3->Captura();
     //Tipo *t2 =new Tipo();
   a->agregar(t);
    a->agregar(t2);
     a->agregar(t3);
   a->desplegarNivel(1);
   a->eliminar(4);
   a->desplegarNivel(1);

}
Interfaz::Interfaz(const Interfaz& orig) {
}

Interfaz::~Interfaz() {
}

