#include <iostream>
#include<conio.h>  
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<string.h>

using namespace std;

void Ayuda();
void Traduccion();
void Validacion();
void Estadisticas();
void Validar();

int AFD = 0, ingresadas = 0, validas = 0, invalidas = 0, traducidas = 0;
const int MAXPALABRA = 15, inicio = 80 - 47, cadenamax = 256;
char abc[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char palabra[cadenamax], ptraducida[cadenamax];

// lista encadenada para alfabetos
struct simbolo
{
    char letra;
    struct simbolo* siguiente;
};
typedef struct simbolo* alfabetot;
alfabetot sigmae = NULL;
alfabetot sigmas = NULL;

simbolo* ptr_palabra = NULL;
simbolo* inicio_posicion_palabra = NULL;
simbolo* ultima_posicion_palabra = NULL;
simbolo* nueva_palabra = NULL;

//lista encadenada para conjuntos
struct  estado
{
    char palabra[MAXPALABRA];
    struct estado* siguiente;
};
typedef struct estado* conjuntot;
conjuntot conjuntoq = NULL;
conjuntot conjunyoa = NULL;
conjuntot q0 = NULL;

// Lista encadenada para los nodos del grafo
struct nodo{
    char nonodo[MAXPALABRA];
    struct nodo* nodosiguiente;
    struct arista* aristaadyacente;
};
typedef struct nodo* Tnodo;
Tnodo grafo = NULL;

// Lista encadenada para las aristas de los nodos
struct MyStruct{
    char noarista;
    char traduccion;
    struct arista* aristasiguiente;
    struct nodo* nodoadyacente;
};
typedef struct arista* Tarista;

int main() {

    int opcion;
    bool ingresa = false;
    do {
        cout << " Menu: \n" << endl;
        cout << "1. Ayuda\n";
        cout << "2. AFD Traduccion\n";
        cout << "3. AFD Validacion\n";
        cout << "4. Estadisticas\n";
        cout << "5. Validar letra alfabeto general\n";        
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: Ayuda();
            break;
        case 2: Traduccion();
            cout << endl;
            break;
        case 3: Validacion();
            cout << endl;
            break;
        case 4: Estadisticas();
            cout << endl;
            break;
        case 5: Validar();
            cout << endl;
            break;
        case 6: cout << "Cerrando sistema\n";
            break;
        default: cout << "Opcion invalida\n";
        }
    } while (opcion != 6);

	return 0;
}

void Ayuda() {

    cout <<endl<< "Un AFD de traduccion recibe siete parametros y el AFD de validacion cinco" << endl;
    cout << "Los parametros posibles son:" << endl;
    cout << "AE = Alfabeto de entrada." << endl;
    cout << "AS = Alfabeto de saluda." << endl;
    cout << "Q = Conjunto de estados posibles." << endl;
    cout << "q0 = Estado incial." << endl;
    cout << "A = Conjunto de estados de aceptacion." << endl;
    cout << "F = Funcion de transcicion." << endl;
    cout << "G = Funcion de traduccion." << endl;
    cout << "EL AFD de traduccion recibe: AE, AS, Q, q0, A, F y G." << endl;
    cout << "El AFD de validacion recibe: AE, Q, q0, A y F." << endl << endl;

}

void Traduccion() {
    char simboloe;
    char sn;
    bool opcion;
    while (true){
        cout << "Indique el alfabeto de entrada" << endl;
        cin >> simboloe;
        //Exception
        nueva_palabra = new(simbolo);
        nueva_palabra->siguiente = NULL;
        if (inicio_posicion_palabra == NULL) {
            inicio_posicion_palabra = nueva_palabra;
            if (ultima_posicion_palabra == NULL)
                ultima_posicion_palabra = nueva_palabra;
        }
        else {
            ultima_posicion_palabra->siguiente = nueva_palabra;
            ultima_posicion_palabra = nueva_palabra;
        }
        cout << "Desea ingresar un nuevo producto? (s/n): " << endl;
        cin >> sn;
        if (sn == 'n') {
            break;
        }
    }

    cout << "El Alfabeto de entrada es el siguiente: " << endl;
    ptr_palabra = inicio_posicion_palabra;
    while (true) {
        cout << simbolo->ptr_palabra;
        cout << endl;
        if (ptr_palabra->siguiente == NULL) {
            break;
        }
        else {
            ptr_palabra = ptr_palabra->siguiente;
        }
    }
}

void Validacion() 
{
    struct simbolo *letra, *symbol;

      symbol = (struct simbolo*)malloc(sizeof(Tnodo));

      if(!symbol)
      {
        cout << "Desbordamiento de memoria";
        return;
	  }
      else
      {
      cout << endl << "Ingrese el simbolo del alfabeto: ";
      cin >> &symbol->letra;
      cout << "Memoria: " << symbol->letra << "+" << symbol;
	}
}

void Estadisticas() {
}

void Validar() {

}

