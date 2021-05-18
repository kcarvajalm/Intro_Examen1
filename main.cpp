/*
Curso Introducción a la Programación UNED -
PROYECTO - EXAMEN 1
KENNETH CARVAJAL MESEN
1-1183-0218
*/


#include <iostream>
#include <cstdlib>//srand
#include <time.h> //numeros aleatorios

using namespace std;

int const fila = 4;
int const columna= 6;
int tablero[fila][columna];
string tableroTrampas[fila][columna];


int menuPrincipal();
void generaTablero();
void trampas();
void imprimeTablero(string nombre, int posicionJugador, int posicionCompu);
int dado(int posicion);
int revisarTrampa(int posicion,int tablero[fila][columna], string tableroTrampas[fila][columna]);



int main()
{
    menuPrincipal();
}


int menuPrincipal()
{
    setlocale(LC_ALL, "");// Funcion que permite el uso de tildes en el texto de impresion a consola
    int Opcion=0;
    string nombre;
    int posicionJugador=0;
    int posicionCompu=0;
    do
    {
        cout <<"########################" << endl;
        cout <<"# Bienvenido al Juego  #" << endl;
        cout <<"#      Figuras         #" << endl;
        cout <<"########################" << endl;
        cout <<"" << endl;
        cout <<"Seleccione un número según la opción deseada"<< endl;
        cout <<"" << endl;
        cout <<"1. Juego Nuevo" << endl;
        cout <<"2. Salir" << endl;
        cout <<"" << endl;
        cout << "Por Favor ingrese la opción: ";
        cin >> Opcion;

        switch (Opcion)
        {
        case 1:
            posicionJugador=1;
            posicionCompu=1;

            system("cls");
            generaTablero();
            trampas();
            cout <<"1. Juego Nuevo " << endl;
            cout <<"" << endl;

            cout <<"Por favor ingrese su nombre:" << endl;
            cin >> nombre;
            system("cls");
            imprimeTablero(nombre,posicionJugador,posicionCompu);

            do
            {
                //Turno Jugador
                cout <<"Turno:" << nombre << endl;
                system("pause");
                posicionJugador= dado(posicionJugador);
                posicionJugador = revisarTrampa(posicionJugador,tablero,tableroTrampas);
                system("cls");
                imprimeTablero(nombre,posicionJugador,posicionCompu);

                if (posicionJugador >24)
                {
                    cout << "\n" << endl;
                    cout <<"Felicidades!!!!!" << " " + nombre <<" has GANADO!!!" <<endl;
                    break;
                }
                //Turno Computadora
                cout <<"Turno:" << "Computadora"  << endl;
                system("pause");
                posicionCompu= dado(posicionCompu);
                posicionCompu = revisarTrampa(posicionCompu,tablero,tableroTrampas);
                system("cls");
                imprimeTablero(nombre,posicionJugador,posicionCompu);

            }
            while(posicionCompu<=24);

            if (posicionCompu >24)
            {
                cout << "\n" << endl;
                cout <<"Lástima!!!!!" << " " + nombre <<" has Perdido!!!" <<endl;
            }

            system("pause");
            system("cls");

            break;

        case 2:
            system("cls");
            cout << "Juego Figuras por Kenneth Carvajal" << endl;
            cout << "Curso Introducción a la Programación UNED - Examen 1" << endl;
            cout << "Gracias!" << endl;
            system("pause");
            break;

        default:
            system("cls");
            cout << "Error" << endl;
            cout << "" << endl;
            cout << "ATENCIÓN: OPCIÓN NO VÁLIDA" << endl;
            cout << "Por favor ingrese el digito según la opción" << endl;
            cout << "La opción a seleccionar debe ser entre 1 o  2" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(Opcion!= 2 );
    return 0;
}



//Genera el a arreglo de numeros para el tablero del 1-24
void generaTablero()
{
    int numeroCasilla=0;
    for (int i=0; i<fila; i++)
    {
        for (int j=0; j<columna; j++)
        {
            tablero[i][j] = (numeroCasilla = numeroCasilla + 1);
            //cout << "\t"<< tablero[i][j] ;
        }
        //cout << "\n";
    }
}

//Genera el tablero de trampas, y al azar se setean las 10 trampas dentro del tablero
// si en el  tablero ya existe una trampa el contador se devuelve 1 para asi tener las 10
void trampas()
{
    srand(time(NULL));
    int cantidadTrampas=10;
    int tipoTrampa = 0;
    string letraTrampa="";
    int k =0;

    for (int i=0; i<fila; i++)
    {
        for (int j=0; j<columna; j++)
        {
            tableroTrampas[i][j] = ">|<";
        }
    }

    for ( k=0; k<cantidadTrampas; k++)
    {
        int filaT = rand()%4;
        int columnaT = rand()%6;

        tipoTrampa=rand()%4;
        //cout << fila << "\t"<< columna<< "\t" << tipoTrampa << "\n";

        if (tipoTrampa == 0)
        {
            letraTrampa= "-C-";
        }
        if (tipoTrampa == 1)
        {
            letraTrampa="-T-";
        }
        if (tipoTrampa ==2)
        {
            letraTrampa="-R-";
        }
        if (tipoTrampa == 3)
        {
            letraTrampa="-P-";
        }
        if ( tableroTrampas[filaT][columnaT] == ">|<")
        {
            tableroTrampas[filaT][columnaT] =letraTrampa;
        }
        else
        {
            k--;
        }
    }
}


//Gerena el valor del Dado del 1-5, mueve a la siguiente posicion
//y revisa si en esa posicion existe una trampa retorna la posicion
int dado(int posicion)
{
    srand(time(NULL));
    int vDado = rand()%5 + 1;
    cout <<"Dados : " << vDado << endl;
    cout <<"Pasa de posicion: " << posicion << "  a  la posicion: " << vDado  + posicion << endl;
    system("pause");
    posicion = vDado  + posicion;
    posicion = revisarTrampa(posicion,tablero,tableroTrampas);
    return posicion;

}


//Imprime en pantalla el tablero de numeros y el tablero de trampas
void imprimeTablero(string nombre, int posicionJugador, int posicionCompu )
{
    cout <<"    Bienvenido a Figuras:  " << nombre <<endl;
    cout <<"------------------------------------------------" <<endl;
    cout <<"Reglas:  " <<endl;
    cout <<"Círculo   – Avanza una posición más" <<endl;
    cout <<"Triángulo – Vuelve a tirar el dado." <<endl;
    cout <<"Rombo     – Retrocede dos posiciones." <<endl;
    cout <<"Puerta    – Vuelve a comenzar desde el inicio." <<endl;
    cout <<"\n" <<endl;

    for (int i=0; i<fila; i++)
    {
        for (int j=0; j<columna; j++)
        {
            cout << "\t"<< tableroTrampas[i][j] ;
        }
        cout << "\n";

        for (int k=0; k<columna; k++)
        {
            cout << "\t "<< tablero[i][k] ;
        }
        cout << "\n\n";
    }

    cout  << "Posición: " << nombre << " :" << posicionJugador <<"\t" << "Computadora:" << posicionCompu <<endl ;
    cout << "\n";

}


// Revisa y ejecuta si la posicion tiene trampa, retorna la posicion
int revisarTrampa(int posicion, int tablero[fila][columna], string tableroTrampas[fila][columna])
{

    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (tablero[i][j] == posicion)
            {
                //cout << "posicion" << posicion << "encontrada en :"<< i << " y en :" <<  j <<endl;

                //Círculo – avanza una posición más.
                if(tableroTrampas[i][j] == "-C-")
                {
                    cout << "Posicion: " << posicion << "\t"<<"Círculo – avanza una posición más." <<endl;
                    cout <<"Pasa de posicion: " << posicion << "  a  la posicion: " << posicion +1 << endl;
                    system("pause");
                    return posicion = posicion +1;

                }

                //Triángulo – vuelve a tirar el dado.
                if(tableroTrampas[i][j] == "-T-")
                {
                    cout << "Posicion: " << posicion << "\t"<<"Triángulo – vuelve a tirar el dado." <<endl;
                    system("pause");
                    return posicion = dado(posicion);

                }

                //Rombo – retrocede dos posiciones
                if(tableroTrampas[i][j] == "-R-")
                {
                    cout << "Posicion: " << posicion << "\t"<<"Rombo – retrocede dos posiciones." <<endl;
                    cout <<"Pasa de posicion: " << posicion << "  a  la posicion: " << posicion -2 << endl;
                    system("pause");
                    return posicion = posicion -2 ;

                }

                //Puerta – Vuelve a comenzar desde el inicio.
                if(tableroTrampas[i][j] == "-P-")
                {
                    cout << "Posicion: " << posicion << "\t"<<"Puerta – Vuelve a comenzar desde el inicio." <<endl;
                    cout <<"Pasa de posicion: " << posicion << "  a  la posicion: 1" << endl;
                    system("pause");
                    return posicion = 1 ;

                }
            }
        }
    }
    return posicion;
}


