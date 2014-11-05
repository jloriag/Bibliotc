/* 
 * File:   Libros.h
 * Author: josue
 *
 * Created on 25 de octubre de 2014, 09:43 PM
 */

#ifndef LIBROS_H
#define	LIBROS_H
#include "objeto.h"

class Libros : public Objeto {
public:
    Libros();
    string getTitilo()const;
    string getAutor()const;
    string getDescrpcion()const;
    int getTipo()const;

    void setTitulo(string);
    void setAutor(string);
    void setDescripcion(string);
    void setTipo(int);

    int getISBN()const;
    void setISBN(int);

    virtual string toString();
    virtual void Captura();

    //Archivos
    Libros(ifstream&);
    virtual void deserialize(ifstream&, Libros*);
    virtual bool serialize(ofstream&, Libros*);
    virtual bool guardar(ofstream&);
    virtual ~Libros();
private:
    // int _isbn Criterio
    string _titulo;
    string _autor;
    string _descripcion;
    int _tipo;

};

#endif	/* LIBROS_H */

