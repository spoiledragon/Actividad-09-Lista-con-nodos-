#include "Menusito.h"
using namespace std;

int pos, opc, ran;

void Menu::ingreso()
{

    cout << "Nombre:" << endl;
    fflush(stdin);
    getline(cin, mystring); //el cin se va al pilin por el espacio
    myStudent.setnombre(mystring);

    cout << "Codigo:" << endl;
    fflush(stdin);
    getline(cin, mystring);
    myStudent.setcodigo(mystring);
    cout << "Interprete:" << endl;
    fflush(stdin);

    //se puede encerrar en un trycatch
    //primero inserto el estudihambre y luego su posicion
    myList.insertar(myStudent, myList.getlastp());
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
    Alumno temp;
    do
    {
        Menu::limpia();
        cout << "Bienvenido al menu de la actividad 5" << endl;
        cout << "Solo podras ingresar datos asi que x" << endl;
        cout << "1.- Ingresar nueva cancion" << endl;
        cout << "2.- Mostrar todas las canciones" << endl;
        cout << "3.- Busqueda Lineal" << endl;
        cout << "4.- Borrar" << endl;
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

        default:

        case 3:
            cout << "Ingrese el nombre a buscar del Artista o de la cancion" << endl;
            
            fflush(stdin);
            cin>>mystring;
            temp.setnombre(mystring);
            cout << myList.busquedalineal(temp);
            system("PAUSE");
            break;

        case 4:
            cout << "Ingrese el nombre a buscar del Artista o de la cancion" << endl;
            fflush(stdin);
            temp.getnombre();
            //cout << myList.borrar()
        break;

        case 0:
            return;
            break;
        }

    } while (true);
}