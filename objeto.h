/* 
 * File:   objeto.h
 * Author: josue
 *
 * Created on 19 de octubre de 2014, 03:19 PM
 */

#ifndef OBJETO_H
#define	OBJETO_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// CLASE ABSTRACTA

class Objeto {
private:
    int _criterio;
public:

    Objeto(int c) {
        setCriterio(c);
    }
    // Método Virtual Puro
    virtual string toString() = 0;

    // Método Virtual Puro
    virtual void Captura() = 0;

    int getCriterio()const {
        return _criterio;
    }

    void setCriterio(int c) {
        _criterio = c;
    }
};

#endif	/* OBJETO_H */

