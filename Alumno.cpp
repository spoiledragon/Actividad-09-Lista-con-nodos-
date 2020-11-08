#include "Alumno.h"
#include <iostream>
#include <iomanip>

Alumno::Alumno() {}
Alumno::Alumno(const std::string &n, const std::string &c, const Date &N, const Date &I)
{
    nombre = n;
    codigo = c;
    Nacimiento = N;
    Ingreso = I;
}

Alumno::Alumno(const Alumno &c) : nombre(c.nombre), codigo(c.codigo), Nacimiento(c.Nacimiento), Ingreso(c.Ingreso) {}
/* 
    Alumno& Alumno::operator=(const Alumno& c){
    nombre=c.nombre;
    artista=c.artista;
    interprete=c.interprete;
    ranking=c.ranking;
    return *this;
}*/

string Alumno::getnombre() const { return nombre; }
string Alumno::getCodigo() const { return codigo; }
Date Alumno::getFechaNacimiento() const { return Nacimiento; }
Date Alumno::getFechaIngreso() const { return Ingreso; }

void Alumno::setnombre(const string &n) { nombre = n; }
void Alumno::setcodigo(const string &a) { codigo = a; }
void Alumno::setFechaNacimiento(const Date &i) { Nacimiento = i; }
void Alumno::setFechaIngreso(const Date &r) { Ingreso = r; }

string Alumno::tostr()
{
    string regreso;
    regreso = "";
    regreso += " || ";
    regreso += getnombre();
    regreso += " || ";
    regreso += getCodigo();
    regreso += " || ";

    return regreso;
}

void Alumno::mostrarAlumno() const
{
    cout << setw(10) << left;
    cout << setw(10) << getnombre();
    cout << setw(10) << getCodigo();
}

int Alumno::comparanombre(const Alumno &c1, const Alumno &c2)
{
    if (c1.nombre < c2.nombre)
        return -1;
    if (c1.nombre == c2.nombre)
        return 0;
    if (c1.nombre > c2.nombre)
        return 1;
    return 0;
}

bool Alumno::operator != (const Alumno& c) const {
    return nombre != c.nombre;
    }
bool Alumno::operator == (const Alumno& c) const {
    return nombre == c.nombre;
    }