#include"Interfaz.h"
int main(){

	Interfaz *t = new Interfaz();
	t->Principal();
	/*ArbolTipos *t = new ArbolTipos();
	Tipo * t1 = new Tipo();
	t1->Captura();
	t->agregar(t1);
	t->insertaISBN(2,120);
	t->insertaISBN(1, 14);
	t->insertaISBN(1, 1410);
	cout << t->mostrarListarISBN(12);*/
    //Interfaz* i=new Interfaz();
   // i->menuPrinpicipal();
    //Arbol *a=new Arbol();
   // Tipo *t =new Tipo();
   // t->Captura();
    // Tipo *t2 =new Tipo();
  //  a->agregar(t);
  //  a->agregar(t2);
    
 //   cout<<a->getRaiz()->getObjeto()->toString()<<endl;
   // cout<<a->getRaiz()->getDer()->getObjeto()->toString()<<endl;
    
	delete t;
	cin.get();
      cin.get();
    
return 0;
}
