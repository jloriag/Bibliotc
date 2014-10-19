#include"Tipo.h"
#include"Arbol.h"
#include<iostream>
using namespace std;
int main(){
    Arbol *a=new Arbol();
    Tipo *t =new Tipo();
    t->Captura();
    // Tipo *t2 =new Tipo();
    a->agregar(t);
  //  a->agregar(t2);
    
    cout<<a->getRaiz()->getObjeto()->toString()<<endl;
   // cout<<a->getRaiz()->getDer()->getObjeto()->toString()<<endl;
    cin.get();
return 0;
}
