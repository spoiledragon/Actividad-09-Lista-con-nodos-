#include "Menusito.h"
using namespace std;

int pos, opc, ran;

void Menu::ingreso()
{
    cin >> mySong;
    //se puede encerrar en un trycatch
    //primero inserto el estudihambre y luego su posicion
    myList.insertar(mySong, myList.getlastp());
}

void Menu::recuperar()
{
    cout << "Ingrese el nombre  de la cancion" << endl;
    fflush(stdin);
    getline(cin, mystring);
    mySong.setnombre(mystring);
    cout << myList.recupera(myList.busquedalinealNombre(mySong)) << endl;
    system("PAUSE");
}

void Menu::buscar()
{
    int n;

    cout << "Inserta el elemento  a buscar" << endl;
    fflush(stdin);
    getline(cin, mystring);
    mySong.setnombre(mystring);

    cout << myList.busquedalinealNombre(mySong);
    system("PAUSE");}

    void Menu::borrar()
    {
        cout << "Ingrese el nombre  de la cancion" << endl;
        fflush(stdin);
        getline(cin, mystring);
        mySong.setnombre(mystring);
        myList.borrar(myList.busquedalinealNombre(mySong));
    }
    void Menu::mostrar()
    {
        cout << myList.tostring();
        system("PAUSE");
    }

    void Menu::limpia()
    {
        system("CLS");
    }

    //pues implemente esta madre que jala ahi masomenos
    void Menu::menuact5()
    {
        int menu;
        Cancion temp;
        do
        {
            Menu::limpia();
            cout << "Bienvenido al menu de la actividad 9 (reutilizando la 5)" << endl;
            cout << "1.- Ingresar nueva cancion" << endl;
            cout << "2.- Mostrar todas las canciones" << endl;
            cout << "3.- Busqueda Lineal (regresa direccion de memoria)" << endl;
            cout << "4.- Borrar" << endl;
            cout << "5.- Recuperar" << endl;
            cout << "6.- Insertar al inicio" << endl;
            cout << "0.- salir" << endl;
            cin >> menu;

            switch (menu)
            {
            case 1:
                Menu::ingreso();
                break;

            case 2:
                Menu::mostrar();
                break;

            case 3:
                Menu::buscar();
                break;

            case 4:
                Menu::borrar();
                break;

            case 5:
                Menu::recuperar();
                break;

            case 6:

                cin >> mySong;
                myList.insertar(mySong, myList.getfirst());
                break;

            case 0:
                return;
                break;
            
            default:
            cout<<"eso no existe oiga"<<endl;
            break;
            }

        } while (true);
    }