#include"Tipo.h"
#include"Arbol.h"
#include<iostream>
using namespace std;
int main(){
    Arbol *a=new Arbol();
    Tipo *t =new Tipo(1,"UNana");
     Tipo *t2 =new Tipo(2,"UNana");
    a->agregar(t);
    a->agregar(t2);
    //
    cout<<a->getRaiz()->getObjeto()->getCriterio()<<endl;
    cout<<a->getRaiz()->getDer()->getObjeto()->getCriterio()<<endl;
    cin.get();
return 0;
}
