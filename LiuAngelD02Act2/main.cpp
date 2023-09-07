#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <sstream>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include "Procesos.h"
#include "Lotes.h"
using namespace std;

bool Verificar(vector<Lote*> lotes, int id) {
    for (int i = 0; i < lotes.size(); i++) {
        for (int j = 0; j < lotes[i]->proce.size(); j++) {
            if (id == lotes[i]->proce[j]->getID()) {
                return true;
                }
            }
        }
    return false;
    }

bool esNumero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
            }
        }
    return true;
    }

void gotoxy(int x,int y) { //se acomoda donde se puede escribir en la consola
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
    }

int main() {
    int aux, pro, c = 0;
    vector<Lote*> l;
    vector<proceso*> t;
    proceso *auxp;
    Lote *auxl;
    string auxs;
    string input;
    gotoxy(3,1);
    cout << "Ingresar el no de procesos" << endl;
    gotoxy(3,2);
    getline(cin, input);
     while (!esNumero(input)) {
        cout << "                                      "; // Limpiar línea
        cout << "\n\tALERTA: Por favor, ingrese un numero valido" << endl;
        cout << "\n\t";getline(cin, input);
    }
    stringstream ss(input);
    ss >> pro;
    while (pro <= 0) {
        cout << "                                      "; // Limpiar línea
        cout << "\n\tALERTA: El numero de procesos debe ser mayor a 0" << endl;
        cout << "\n\t";getline(cin, input);

        while (!esNumero(input)) {
            cout << "                                      "; // Limpiar línea
            cout << "\n\tALERTA: Por favor, ingrese un numero valido" << endl;
            cout << "\n\t";getline(cin, input);
        }
        ss.clear();
        ss.str(input);
        ss >> pro;
    }
    system("cls");

    for (int i = 0; i < pro; i++) {
        if (i % 5 == 0) {
            auxl = new Lote((i / 5) + 1);
            l.push_back(auxl);
            }

        auxp = new proceso();

        cout << "\n\tIngrese el Nombre:" << endl;
        cout << "\n\t";
        cin.ignore();
        cout << "\n\t";getline(cin, auxs);
        auxp->setnombre(auxs);

        cout << "\n\tIngrese el ID:" << endl;
        cout << "\n\t";
        getline(cin, input);
         while (!esNumero(input)) {
        cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
        cout << "\n\tEscribir otro:" << endl;
        cout << "\n\t";getline(cin, input);
        }
        aux = stoi(input);
        while (Verificar(l, aux)) {
            cout << "\n\tALERTA ID ya registrado." << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);
            while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);
        }
        aux = stoi(input);
            }
        auxp->setID(aux);

        /////////////////////////////////////////////////
        cout << "\n\tElija la operacion." << endl;
        cout << "\n\t1)Suma" << endl;
        cout << "\n\t2)Resta" << endl;
        cout << "\n\t3)Multiplicacion" << endl;
        cout << "\n\t4)Division" << endl;
        cout << "\n\t5)Residuo" << endl;
        cout << "\n\t6)Potencia" << endl;
        cout << "\n\t";
        cout << "\n\t";getline(cin, input);
         while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
        aux = stoi(input);
        while (aux < 1 || aux > 6) {
            cout << "\n\tALERTA opcion no valida" << endl;
            cout << "\n\t";
            getline(cin, input);
            while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
            aux = stoi(input);
            }
        auxp->setOperacion(aux);
        /////////////////////////////////////////////////
        cout << "\n\tIngrese a:" << endl;
        cout << "\n\t";
        getline(cin, input);
        while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
        aux = stoi(input);
        auxp->seta(aux);
        /////////////////////////////////////////////////
        cout << "\n\tIngrese b:" << endl;
        cout << "\n\t";
        getline(cin, input);
        while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
        aux = stoi(input);
        while (aux == 0 && (auxp->getOperacion() == 4 || auxp->getOperacion() == 5)) {
            cout << "\n\tEl dividendo no puede ser 0." << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";
            getline(cin, input);
            while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
            aux = stoi(input);
            }
        auxp->setb(aux);
        /////////////////////////////////////////////////
        cout << "\n\tIngrese el tiempo:" << endl;
        cout << "\n\t";
        getline(cin, input);
        while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
        aux = stoi(input);
        while (aux <= 0) {
            cout << "\n\tALERTA el tiempo > 0" << endl;
            cout << "\n\t";
            getline(cin, input);
        while (!esNumero(input)) {
            cout << "\n\tALERTA: Por favor, ingrese solo numeros" << endl;
            cout << "\n\tEscribir otro:" << endl;
            cout << "\n\t";getline(cin, input);;
            }
        aux = stoi(input);
            }
        auxp->settiempo(aux);
        /////////////////////////////////////////////////
        auxl->agregar(auxp);

        system("cls");
        }
////////////////////////////////////////////////////////////////
    proceso *proce = new proceso();
    proce->settiempo(1);
    Lote *lote = l[0];

    proce->imprimirV(*lote, l.size()-lote->numLote, t, c);
    system("cls");
    for(int i = 0; i<l.size(); i++) {
        lote = l[i];
        for(int j=0; j<lote->proce.size();) {
            proce = lote->proce[0];
            proce->imprimir(*lote,l.size()-lote->numLote, t, c);
            c += proce->gettiempo();
            }
        }

    proce->imprimirV(*lote, l.size()-lote->numLote, t, c);
    system("PAUSE");

    return 0;
    }

