#ifndef MENUSITO_H_INCLUDED
#define MENUSITO_H_INCLUDED
#include "List.h"
#include <iostream>
#include "Cancion.h"
#include "Date.h"

class Menu{
private: 
Lista<Cancion>myList;
Cancion mySong;
Date myIngreso;
Date myBirdthday;

Lista<Cancion>::Position pos;


std::string mystring;


public:


    void ingreso();
    void mostrar();
    void limpia();
    void buscar();
    void borrar();
    void recuperar();
    std::string capturab() const;
    void insertar_inicio();
    void menuact5();
    
    
};


#endif // MENUSITO_H_INCLUDED
