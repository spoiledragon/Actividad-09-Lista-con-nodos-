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

    public:
        //construcores de nodo
        Nodo();
        Nodo(const T &);
        //metodos de nodo
        T getData() const;
        Nodo *getNext() const;
        //setters de nodo
        void setData(const T &);
        void setNext(Nodo *);
    };
    Nodo *anchor; //apunta al primer nodo siempre
    bool isValid(Nodo *) const;
    void copyAll(const Lista<T> &);

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
    bool tavacio()const;
    bool talleno()const;
    //fake setters
    //Nombre    //pos           //interprete        //autor
    void insertar(const T &, Nodo *); //nombre de la canciono, la posicion la usaremos como rank, interprete, Artista, Auttor del artista
    void borrar(Nodo *);              //pos borra

    //void insertasiguiente(const T &);
    //fake getters
    Nodo *getfirst();         //la primera
    Nodo *getlastp();         //la ultima
    Nodo *getprev(Nodo *);    //anterior
    Nodo *getnext(Nodo *);    //la que sigue
    T recupera(const Nodo *); //retriueve = recupera

    std::string tostring();

    void borrador4k(); //podemos borrar aca bien piola o regresar a la primera posicion depende del caso

    Nodo *busquedalineal(const T &);

    Lista<T> &operator=(const Lista<T> &); //operador de asignacion}
};

using namespace std;
//implementacion de Nodos AQUI°°--------------------------------------------------------------------------------------------------------------------------------
template <class T>
Lista<T>::Nodo::Nodo() : next(nullptr) {}

template <class T>
Lista<T>::Nodo::Nodo(const T &e) : data(e), next(nullptr) {}

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
void Lista<T>::Nodo::setData(const T &e)
{
    data = e;
}

template <class T>
void Lista<T>::Nodo::setNext(Nodo *n)
{
    next = n;
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
bool Lista<T>::tavacio()const
{
    return anchor == nullptr;
}

template <class T>
bool Lista<T>::isValid(Nodo *p) const{   
    if (!tavacio()){
        Nodo *aux(anchor);
        do
        {
            if (aux == p)
            {
                return true;
            }
            aux = aux->getNext();
        }while (aux != anchor);
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
    { //inserta al principio
        if (tavacio())
        {
            aux->setNext(aux);
        }
        else
        {
            aux->setNext(anchor);
            getlastp()->setNext(aux);
        }
        anchor = aux;
    }
    else
    {
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

template <class T>
void Lista<T>::borrar(Nodo *p)
{
    if (!valida(p))
    {
        throw Exception("Posicion invalida en borrar");
    }
    if (p == anchor)
    { //eliminara al priomero
        if (p->getNext() == p)
        {
            anchor = nullptr;
        }
        else
        {
            getlastp()->setNext(anchor->getNext());
            anchor = anchor->getnext();
        }
    }
    else
    {
        getprev(p)->setNext(p->getNext());
    }
    delete p;
}

template <class T> //serviria pero el ancla ya hace este pedo
typename Lista<T>::Nodo *Lista<T>::getfirst()
{
    if (tavacio())
    {
        throw Exception("getElementAt() - Lista vacia");
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

    Nodo *aux(anchor);
    while (aux->getNext() != anchor)
    {
        aux = aux->getNext();
    }
    return aux;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::getprev(Nodo *p)
{
    if (p == anchor || tavacio())
    {
        return nullptr;
    }

    Nodo *aux(anchor);

    do
    {
        if (aux->getNext() == p)
        {
            return aux;
        }
        aux = aux->getNext();
    } while (aux != anchor);
    return nullptr;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::getnext(Nodo *p)
{
    if (!valida(p) || p->getNext() == anchor)
    {
        return nullptr;
    }

    return p->getNext();
}

template <class T>
T Lista<T>::recupera(const Nodo *p)
{
    if (!valida(p))
    {
        throw Exception("Posicion invalida en recupera");
    }
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
    } while (anchor != mark);
    anchor = nullptr;
}

template <class T>
typename Lista<T>::Nodo *Lista<T>::busquedalineal(const T &e)
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
    if (!tavacio())
    {
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
void Lista<T>::copyAll(const Lista<T> &l)
{
    if (l.tavacia())
    {
        return;
    }

    Nodo *aux(l.anchor);
    Nodo *last(nullptr);
    Nodo *newNodo;
    //la validacion que dijo el profe 
    if(newNodo==nullptr){
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
template<class T>
Lista<T>& Lista<T>::operator=(const Lista<T>&l){
    borrador4k();
    copyAll();
}
template <class T>
Lista<T>::~Lista()
{
    borrador4k();
}

#endif // LIST_H_INCLUDED
