#ifndef MENUSITO_H_INCLUDED
#define MENUSITO_H_INCLUDED
#include "List.h"
#include <iostream>
#include "Alumno.h"
#include "Date.h"

class Menu{
private: 
Lista<Alumno>myList;
Alumno myStudent;
Date myIngreso;
Date myBirdthday;

Lista<Alumno>::Position pos;


std::string mystring;


public:


    void ingreso();
    void mostrar();
    void limpia();
    void menuact5();
    
    
};


#endif // MENUSITO_H_INCLUDED
