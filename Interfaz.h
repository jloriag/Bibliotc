/* 
 * File:   Interfaz.h
 * Author: josue
 *
 * Created on 21 de octubre de 2014, 07:47 PM
 */

#ifndef INTERFAZ_H
#define	INTERFAZ_H
#include"Tipo.h"
class Interfaz {
public:
    Interfaz();
    Interfaz(const Interfaz& orig);
    virtual ~Interfaz();
    void menuPrinpicipal();
private:
    static const string archivo;
};

#endif	/* INTERFAZ_H */

