/* 
 * File:   Interfaz.cpp
 * Author: josue
 * 
 * Created on 21 de octubre de 2014, 07:47 PM
 */

#include "Interfaz.h"
const string Interfaz::archivo = "libros.dat";
Interfaz::Interfaz() {
	_arboltipos = new ArbolTipos();
	_arbollibros = new ArbolLibros();
//	ifstream entrada(archivo.c_str());
//	Tipo *t = new Tipo(entrada);
//	cout << t->toString();
}

char Interfaz::MenuPrincipal() {
	cin.clear();
	_flushall();
	system("cls");
	cout << "[1] Gestion de Tipos " << endl;
	cout << "[2] Gestion de Libros " << endl;
	cout << "[3] Consultas " << endl;
	cout << "[4] Listados " << endl;
	cout << "[5] Salir" << endl;
	cin >> opcion;
	return opcion;
}

char Interfaz::MenuTipos(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "[1] Agregar Tipo " << endl;
	cout << "[2] Eliminar Tipo " << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;

}
void Interfaz:: MenuAgregarTipos(){
	if (_arboltipos->agregar(_lectura.LeeTipo())){
		cout << "Se AGREGO un Nuevo Tipo" << endl;
		insert = true;
		
	}
	else{
		cout << "No se puede Agregar" << endl;
	}
	system("pause");
}
char Interfaz::MenuLibros(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "[1] Agregar Libro " << endl;
	cout << "[2] Eliminar Libro " << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}
void Interfaz::MenuBorrarLibroCodigo(){
	_flushall();
	system("cls");
	cout << "Inserte el codigo del Libro: " << endl;
	cin >> opcionNum;
	if (_arbollibros->eliminar(opcionNum)){
		cout << "Se elimino Correctamente" << endl;
		insert = true;
	}
	else{
	
	
	}
	system("pause");

}
void Interfaz::MenuBorrarLibrosTipos(){
	_flushall();
	system("cls");
	cout << "Inserte el ID del Tipo: " << endl;
	cout << "SE ELIMINARAN TODOS LOS LIBROS DE ESTE TIPO: " << endl;
	cin >> opcionNum;
	int n = _arbollibros->eliminarTodosTipos(opcionNum);
	if (n>0){
		cout << "Se eliminaron: "<<n <<" libros"<< endl;
		insert = true;
	}
	else{
		cout << "No se encontro el ID" << endl;

	}
	system("pause");

}
char Interfaz::MenuEliminarLibros(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "[1] Eliminar Libro por Codigo " << endl;
	cout << "[2] Eliminar Libros por Tipo " << endl;
	cout << "[3] Regresar" << endl;
	cin >> opcion;
	return opcion;
}

void Interfaz::MenuAgregarLibros(){
	_flushall();
	system("cls");
	if (_arbollibros->agregar(_lectura.LeeLibro(_arboltipos))){
		cout << "Se AGREGO un Nuevo Libro" << endl;
		insert = true;
		system("pause");
	}
	else{
	
	}
}

void Interfaz::MenuBorrarTipoCodigo(){
	_flushall();
	system("cls");
	cout << "Inserte el codigo del Tipo: " << endl;
	cin >> opcionNum;
	if (_arboltipos->eliminar(opcionNum)){
		cout << "Se elimino Correctamente"<<endl;
		insert = true;
	}
	else{
		cout << "No se encontro"<<endl;
	}
	system("pause");
}

void Interfaz::Tipos(){
	do{
		opcionPrincipal = MenuTipos();
		switch (opcionPrincipal)
		{
		case'1':
			MenuAgregarTipos();
			opcionPrincipal = NULL;
			break;
		case'2':
			MenuBorrarTipoCodigo();
			opcionPrincipal = NULL;
			break;
		case'3':

			break;
		default:
			break;
		}
	} while (opcion != '3'&&!insert);
}

char Interfaz::MenuConsultas(){
	cin.clear();
	_flushall();
	system("cls");
	cout << "[1] Consultar Datos Libro por ISBN " << endl;
	cout << "[2] Todos los libros de un mismo tipo  " << endl;
	cout << "[3] Todos los libros de un autor" << endl;
	cin >> opcion;
	return opcion;


}

void Interfaz::Libros(){
	do{
		opcionPrincipal = MenuLibros();
		switch (opcionPrincipal)
		{
		case'1':

			MenuAgregarLibros();
			opcionPrincipal = NULL;
			break;
		case'2':
			BorrarLibros();
			opcionPrincipal = NULL;
			break;
		case'3':

			break;
		default:
			break;
		}
	} while (opcion != '3'&&!insert);

}

void Interfaz::BorrarLibros(){
	do{
		opcionPrincipal = MenuEliminarLibros();
		switch (opcionPrincipal)
		{
		case'1':
			MenuBorrarLibroCodigo();
			opcionPrincipal = NULL;
			break;
		case'2':
			MenuBorrarLibrosTipos();
			opcionPrincipal = NULL;
			break;
		case'3':

			break;
		default:
			break;
		}
	} while (opcion != '3'&&!insert);

}

void Interfaz::Principal(){
	do{
		insert = false;
		opcionPrincipal = MenuPrincipal();
		switch (opcionPrincipal)
		{
		case'1':
			Tipos();
			break;
		case'2':
			Libros();
			break;
		case'3':
	
			break;
		case'4':

			break;
		case'5':

			break;
		default:
			break;
		}
	} while (opcion != '5');
}
void Interfaz::menuPrinpicipal(){
//ofstream salida(archivo.c_str());
//Libros *b=new Libros();
//b->setISBN(1);
//b->setTipo(1);
//b->guardar(salida);
 
   ifstream entrada(archivo.c_str());
   ArbolTipos *at = new ArbolTipos(entrada);
   at->enOrden();
   entrada.close();
   //Tipo *t=new Tipo();
   // t->setID(10);
   //t->setDescripcion("kakakaaa");
   //at->agregar(t);
   //at->guardar(salida);
   // salida.close();
//Tipo *t=new Tipo(entrada);
//cout<<t->toString();
//salida.close();
//Tipo* t=new Tipo();
//t->Captura();
//t->guardar(salida);
//salida.close();
//    Arbol *a=new ArbolTipos();
//    Tipo *t =new Tipo();
//    t->Captura();
//    Tipo *t2 =new Tipo();
//    t2->Captura();
//     Tipo *t3 =new Tipo();
//    t3->Captura();
//     //Tipo *t2 =new Tipo();
//   a->agregar(t);
//    a->agregar(t2);
//     a->agregar(t3);
//   a->desplegarNivel(1);
//   a->eliminar(4);
//   a->desplegarNivel(1);hgh

}

Interfaz::~Interfaz() {
	delete _arboltipos;
}

