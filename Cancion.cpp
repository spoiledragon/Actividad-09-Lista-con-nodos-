#include "Cancion.h"
#include <iostream>
#include <iomanip>

Cancion::Cancion() {}
Cancion::Cancion(const std::string &n, const std::string &i, const std::string &a, const int &r)
{
    nombre = n;
    interprete = i;
    artista = a;
    ranking = r;
}

Cancion::Cancion(const Cancion &c) : nombre(c.nombre), artista(c.artista), interprete(c.interprete), ranking(c.ranking) {}
/* 
    Cancion& Cancion::operator=(const Cancion& c){
    nombre=c.nombre;
    artista=c.artista;
    interprete=c.interprete;
    ranking=c.ranking;
    return *this;
}*/

string Cancion::getnombre() const { return nombre; }
string Cancion::getartista() const { return artista; }
string Cancion::getinterprete() const { return interprete; }
int Cancion::geranking() const { return ranking; }

void Cancion::setnombre(const string &n) { nombre = n; }
void Cancion::setartista(const string &a) { artista = a; }
void Cancion::setinterprete(const string &i) { interprete = i; }
void Cancion::setranking(const int &r) { ranking = r; }

string Cancion::tostr()
{
    string regreso;
    regreso = "";
    regreso += " || ";
    regreso += getnombre();
    regreso += " || ";
    regreso += getartista();
    regreso += " || ";
    regreso += getinterprete();
    regreso += " || ";
    regreso += to_string(geranking());
    regreso += " || ";
    return regreso;
}

void Cancion::mostrarcancion() const
{
    cout << setw(10) << left;
    cout << setw(10) << getnombre();
    cout << setw(10) << getartista();
    cout << setw(10) << getinterprete();
    cout << setw(5) << geranking();
}

int Cancion::comparanombre(const Cancion &c1, const Cancion &c2)
{
    if (c1.nombre < c2.nombre)
        return -1;
    if (c1.nombre == c2.nombre)
        return 0;
    if (c1.nombre > c2.nombre)
        return 1;
    return 0;
}

int Cancion::comparartista(const Cancion &c1, const Cancion &c2)
{
    if (c1.artista < c2.artista)
        return -1;
    if (c1.artista == c2.artista)
        return 0;
    if (c1.artista > c2.artista)
        return 1;
    return 0;
}

bool Cancion::operator==(const Cancion &c) const
{
        return nombre == c.nombre;
}
