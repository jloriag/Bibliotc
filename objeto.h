/* 
 * File:   objeto.h
 * Author: josue
 *
 * Created on 19 de octubre de 2014, 03:19 PM
 */

#ifndef OBJETO_H
#define	OBJETO_H
#include"sstring.h"// Clase AMIGA
// CLASE ABSTRACTA

class Objeto {
protected:
    int _criterio;
public:

    Objeto() {
    }

    Objeto(int c) {
        setCriterio(c);
    }
    // Método Virtual Puro
	virtual string toString() { return ""; }

    // Método Virtual Puro
    virtual void Captura() {}

    int getCriterio()const {
        return _criterio;
    }

    void setCriterio(int c) {
        _criterio = c;
    }

    Objeto(ifstream& entrada) {
        deserialize(entrada, this);
    }

    virtual void deserialize(ifstream& entrada, Objeto* ob) {
        entrada.read((char*) &ob->_criterio, sizeof (ob->_criterio));
        if (!entrada.good())

            throw -1;
    }

    virtual bool serialize(ofstream& salida, Objeto* ob) {
        salida.write((char*) &ob->_criterio, sizeof (ob->_criterio));
        return salida.good();
    }

    virtual bool guardar(ofstream& salida) {
        return serialize(salida, (Objeto*)this);
    }

    //Archivos

};

#endif	/* OBJETO_H */

