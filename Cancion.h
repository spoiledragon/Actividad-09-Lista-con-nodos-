#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
class Cancion
{
private:
    std::string nombre;
    std::string artista;
    std::string interprete;
    std::string nombrearch;
    int ranking;

public:
    std::string tostr();
    Cancion();
    Cancion(const std::string &, const std::string &, const std::string &, const int &);
    Cancion(const Cancion &);

    void setnombre(const std::string &);
    void setartista(const std::string &);
    void setinterprete(const std::string &);
    void setranking(const int &);
    void setnombrearch(const std::string &);

    void mostrarcancion() const;

    std::string getnombre() const;
    std::string getartista() const;
    std::string getinterprete() const;
    std::string getnombrearch() const;
    int geranking() const;

    static int comparanombre(const Cancion &c1, const Cancion &c2);
    static int comparartista(const Cancion &c1, const Cancion &c2);

    Cancion &operator=(const Cancion c1)
    {
        nombre = c1.nombre;
        artista = c1.artista;
        interprete = c1.interprete;
        ranking = c1.ranking;
        nombrearch = c1.nombrearch;
    }

    bool operator==(const Cancion &) const;

    friend std::ostream &operator<<(std::ostream &out, const Cancion &co)
    {
        out << left;
        out << setw(20) << co.nombre << "||";
        out << setw(20) << co.artista << "||";
        out << setw(5) << co.interprete << "||";
        out << setw(20) << to_string(co.ranking) << "||";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Cancion &c)
    {
        string temp;
        cout << "Nombre: " << endl;
        fflush(stdin);
        getline(cin, c.nombre);

        cout << "Artista " << endl;
        fflush(stdin);
        getline(cin, c.artista);

        cout << "Interprete:" << endl;
        fflush(stdin);
        getline(cin, c.interprete);

        cout << "Ranking: " << endl;
        fflush(stdin);
        cin >> c.ranking;
    }
};

#endif
