#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <cstdlib>
#include <string>
#include <iostream>
//#include "listexception.h" //para los fallos
#include <exception>

template <class T>
class Lista
{
private:
    // clase nodo
    class Nodo
    {
    private:
        T data;
        Nodo *next;
        Nodo *prev;

    public:
        //construcores de nodo
        Nodo();
        Nodo(const T &);

        //metodos de nodo
        Nodo *getNext() const;
        Nodo *getPrev() const;

        //setters de nodo
        void setData(const T &);
        void setNext(Nodo *);
        void setPrev(Nodo *);

        T getData() const;
    };
    Nodo *anchor; //apunta al primer nodo siempre
    void copyAll(const Lista<T> &) const;

public:
    typedef Nodo *Position;
    void copiar(const Lista<T> &);
    void swapData(int, int);
    //Clase exepcion
    class Exception : public std::exception
    {
    private:
        std::string msg;

    public:
        //constructores
        //ancii
        explicit Exception(const char *message) : msg(message) {}
        //c++
        explicit Exception(const std::string &message) : msg(message) {}
        //destructor
        virtual ~Exception() throw() {}
        //devuelve la cadena
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
    };
    //fin de la clase exepcion

    //constructores
    Lista();
    Lista(const Lista<T> &);
    ~Lista();

    //comprobadores globales
    bool tavacio() const;
    bool talleno() const;
    bool isValid(Nodo *p)const;

    void insertar(const T &, Nodo *);
    void borrar(Nodo *); //pos borra

    //void insertasiguiente(const T &);
    //fake getters
    Nodo *getfirst();               //la primera
    Nodo *getlastp();               //la ultima
    Nodo *getprev(Nodo *);          //anterior
    Nodo *getnext(Nodo *);          //la que sigue
    T recupera(const Nodo *) const; //retriueve = recupera

    std::string tostring();

    void borrador4k(); //podemos borrar aca bien piola o regresar a la primera posicion depende del caso

    Nodo *busquedalinealNombre(const T &);
    Nodo *busquedalinealArtista(const T &);

    Lista<T> &operator=(const Lista<T> &); //operador de asignacion}
};

using namespace std;
//implementacion de Nodos AQUI°°--------------------------------------------------------------------------------------------------------------------------------
template <class T>
Lista<T>::Nodo::Nodo() : next(nullptr), prev(nullptr) {}

template <class T>
Lista<T>::Nodo::Nodo(const T &e) : data(e), next(nullptr), prev(nullptr) {}

template <class T>
T Lista<T>::Nodo::getData() const
{
    return data;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::Nodo::getNext() const
{
    return next;
}
template <class T>
typename Lista<T>::Nodo *Lista<T>::Nodo::getPrev() const
{
    return prev;
}

template <class T>
void Lista<T>::Nodo::setData(const T &e)
{
    data = e;
}

template <class T>
void Lista<T>::Nodo::setNext(Nodo *n)
{
    next = n;
}
template <class T>
void Lista<T>::Nodo::setPrev(Nodo *p)
{
    prev = p;
}

//implementacion de Lista
//AQUI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-----------------------------------------------------------------------------------------------------------------
//constructores
template <class T>
Lista<T>::Lista() : anchor(nullptr) {} //aqui parametramos por default que estara en -1

template <class T>
Lista<T>::Lista(const Lista<T> &l) : anchor(nullptr) { copyAll(l); }

//implementacion

template <class T>
bool Lista<T>::tavacio() const
{
    return anchor == nullptr;
}

template <class T>
bool Lista<T>::isValid(Nodo *n) const
{
    if (!tavacio())
    {
        Nodo *aux(anchor);
        do
        {
            if (aux == n)
            {
                return true;
            }
            aux = aux->getNext();
        } while (aux != anchor);
    }

    return false;
}

template <class T>
void Lista<T>::insertar(const T &e, Nodo *p)
{
    if (p != nullptr && !isValid(p))
    {
        throw Exception("Posicion invalida en la insercion");
    }
    //nuevo nodo que sera igual al anterior
    Nodo *aux(new Nodo(e));
    //si no se puede crear el espacio se le inserta el nulo
    if (aux == nullptr)
    {
        throw Exception("Memoria no disponible en la insercion de datos");
    }
    if (p == nullptr)
    { //inserta al principio de los tiempos
        if (anchor == nullptr)
        {
            aux->setPrev(aux);
            aux->setNext(aux);
        }
        else
        {
            //si yua hay mas nodos entonces
            aux->setPrev(anchor->getPrev());
            aux->setNext(anchor);

            anchor->getPrev()->setNext(aux);
            anchor->setPrev(aux);
        }
        anchor = aux;
    }
    else //insercion en cualquier lugar de la memori
    {
        aux->setPrev(p);
        aux->setNext(p->getNext());

        p->getNext()->setPrev(aux);
        p->setNext(aux);
    }
}

template <class T>
void Lista<T>::borrar(Nodo *p)
{
    if (!isValid(p))
    {
        throw Exception("Posicion invalida en borrar");
    }
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    if (p == anchor)
    { //eliminacion al firsto
        if (p->getNext() == p)
        { //solo hay uno en la lista
            anchor = nullptr;
        }
        else
        {
            anchor = anchor->getNext();
        }
    }
    delete p;
}

template <class T> //serviria pero el ancla ya hace este pedo
typename Lista<T>::Nodo *Lista<T>::getfirst()
{
    if (tavacio())
    {
        throw Exception("getElementAt() - Lista vacia");
        return nullptr;
    }
    return anchor;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::getlastp()
{
    if (tavacio())
    {
        return nullptr;
    }

    return anchor->getPrev();
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::getprev(Nodo *p)
{
    if (p == anchor || !isValid(p))
    {
        return nullptr;
    }

    return p->getPrev();
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::getnext(Nodo *p)
{
    if (!valida(p) || anchor->getPrev() == p)
    {
        return nullptr;
    }

    return p->getNext();
}

template <class T>
T Lista<T>::recupera(const Nodo *p) const
{
    return p->getData();
}

template <class T>
void Lista<T>::borrador4k()
{
    if (tavacio())
    {
        return;
    }
    Nodo *mark(anchor);
    Nodo *aux;

    do
    {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    } while (anchor != mark);
    anchor = nullptr;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::busquedalinealNombre(const T &e)
{
    if (!tavacio())
    {
        Nodo *aux(anchor);
        do
        {
            if (aux->getData() == e)
            {
                return aux;
            }
            aux = aux->getNext();

        } while (aux != anchor);
    }

    return nullptr;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::busquedalinealArtista(const T &e)
{
    if (!tavacio())
    {
        Nodo *aux(anchor);
        do
        {
            if (aux->getData() == e)
            {
                return aux;
            }
            aux = aux->getNext();

        } while (aux != anchor);
    }

    return nullptr;
}

template <class T>
std::string Lista<T>::tostring()
{
    string resultado;
    resultado = "No hay elementos";
    if (!tavacio())
    {
        resultado = "";
        Nodo *aux(anchor);
        do
        {
            resultado += aux->getData().tostr() + "\n";
            aux = aux->getNext();
        } while (aux != anchor);
    }

    return resultado;
}

template <class T>
void Lista<T>::copyAll(const Lista<T> &l) const
{
    if (l.tavacia())
    {
        return;
    }

    Nodo *aux(l.anchor);
    Nodo *last(nullptr);
    Nodo *newNodo;
    //la validacion que dijo el profe
    if (newNodo == nullptr)
    {
        return;
    }

    do
    {
        newNodo = new Nodo(aux->getData());
        if (last == nullptr)
        {
            anchor = newNodo;
        }
        else
        {
            last->setNext(newNodo);
        }
        last = newNodo;
        aux = aux->getNext();

    } while (aux != l.anchor);
}
template <class T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l)
{
    borrador4k();
    copyAll();
    return *this;
}
template <class T>
Lista<T>::~Lista()
{
    borrador4k();
}

#endif // LIST_H_INCLUDED
