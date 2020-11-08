#ifndef Alumno_H_INCLUDED
#define Alumno_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Date.h"
using namespace std;
class Alumno
{
private:
    Date Nacimiento;
    Date Ingreso;
    std::string nombre;
    std::string codigo;


public:
    std::string tostr();
    Alumno();
    Alumno(const std::string &, const std::string &, const Date&, const Date&);
    Alumno(const Alumno &);

    void setnombre(const std::string &);
    void setcodigo(const std::string &);
    void setFechaNacimiento(const Date&);
    void setFechaIngreso(const Date&);

    void mostrarAlumno() const;

    std::string getnombre() const;
    std::string getCodigo() const;
    Date getFechaNacimiento() const;
    Date getFechaIngreso() const;
    int geranking() const;

    static int comparanombre(const Alumno &c1, const Alumno &c2);

    Alumno &operator=(const Alumno c1)
    {
        nombre = c1.nombre;
        codigo=c1.codigo;
        Nacimiento=c1.Nacimiento;
        Ingreso=c1.Ingreso;
    }

    bool operator==(const Alumno &) const;

    friend std::ostream &operator<<(std::ostream &out, const Alumno &co)
    {
        out << left;
        out << setw(20) << co.nombre << "||";
        out << setw(20) << co.codigo << "||";
       
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Alumno &c)
    {
        string temp;
        cout << "Nombre: " << endl;
        fflush(stdin);
        getline(cin, c.nombre);

        cout << "Artista " << endl;
        fflush(stdin);
        getline(cin, c.codigo);

    }

    bool operator != (const Alumno&) const;
};

#endif
