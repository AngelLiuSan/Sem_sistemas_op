#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <sstream>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include "Procesos.h"
using namespace std;

queue<proceso*> proceso::listos;
queue<proceso*> proceso::terminados;
queue<proceso*> proceso::nuevos;
queue<proceso*> proceso::bloqueados;
int proceso::reloj;
long long proceso::QU;
void imprimirF(queue<proceso*> &terminados){
    cout<<"\n\tTerminados: "<<endl;
    cout<<"\n\tID\t|\tOPE\t|\tResult\t|\tTLle\t|\tTFin\t|\tTRe\t|\tTRes\t|\tTEs\t|\tTSer\t|\tTiempo"<<endl;
    while(!terminados.empty()){
        auto proceso = terminados.front();
        proceso->TRET = proceso->TF - proceso->TL;
        cout<<"\n\t"<<proceso->getID()<<"\t|\t"<<proceso->geta()<<proceso->operation(proceso->getOperacion())<<proceso->getb()<<"\t|\t"<<proceso->getresul()<<"\t|\t"<<proceso->TL<<"\t|\t"<<proceso->TF<<"\t|\t"<<proceso->TRET<<"\t|\t"<<proceso->TRES<<"\t|\t"<<proceso->TE<<"\t|\t"<<proceso->TS<<"\t|\t"<<proceso->gettiempo()<<endl;
        terminados.pop();
    }
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
    srand((unsigned)time(NULL));
    string auxl;
    proceso* auxp;
    string input;
    int pro;
    gotoxy(3,1);
    cout<<"\n\tIngrese el quantum"<<endl;
    gotoxy(3,2);
    getline(cin, input);
    while (!esNumero(input)) {
        cout << "                                      "; // Limpiar línea
        cout << "\n\tALERTA: Por favor, ingrese un numero valido" << endl;
        cout << "\n\t";getline(cin, input);
    }
    stringstream ss(input);
    ss >> proceso::QU;
    while (proceso::QU <= 0) {
        cout << "                                      "; // Limpiar línea
        cout << "\n\tALERTA: El numero de quantum debe ser mayor a 0" << endl;
        cout << "\n\t";getline(cin, input);
        while (!esNumero(input)) {
            cout << "                                      "; // Limpiar línea
            cout << "\n\tALERTA: Por favor, ingrese un numero valido" << endl;
            cout << "\n\t";getline(cin, input);
        }
        ss.clear();
        ss.str(input);
        ss >> proceso::QU;
    }
    cout << "\n\tIngresar el no de procesos" << endl;
    gotoxy(3,4);
    getline(cin, input);
     while (!esNumero(input)) {
        cout << "                                      "; // Limpiar línea
        cout << "\n\tALERTA: Por favor, ingrese un numero valido" << endl;
        cout << "\n\t";getline(cin, input);
    }
    stringstream aa(input);
    aa >> pro;
    while (pro <= 0) {
        cout << "                                      "; // Limpiar línea
        cout << "\n\tALERTA: El numero de procesos debe ser mayor a 0" << endl;
        cout << "\n\t";getline(cin, input);

        while (!esNumero(input)) {
            cout << "                                      "; // Limpiar línea
            cout << "\n\tALERTA: Por favor, ingrese un numero valido" << endl;
            cout << "\n\t";getline(cin, input);
        }
        aa.clear();
        aa.str(input);
        aa >> pro;
    }
    system("cls");

   for(int i=0;i<pro;i++){
        auxp = auxp->nuevoProceso();
        proceso::nuevos.push(auxp);

        }
        system("PAUSE");
        system("cls");
////////////////////////////////////////////////////////////////
    proceso *proce = new proceso();
    while(!proceso::nuevos.empty() || !proceso::bloqueados.empty() || (!proceso::listos.empty() && proceso::listos.front()->getID()!=-1)){
        while(!proceso::nuevos.empty() && proceso::nuevos.front()->marcos < memory.marcosLibres()){
            memory.insertarEnMemoria(to_string(proceso::nuevos.front()->getID()),proceso::nuevos.front()->tam);
            proceso::nuevos.front()->TL = proceso::reloj;
            proceso::nuevos.front()->estado = 'L';
            proceso::listos.push(proceso::nuevos.front());
            proceso::nuevos.pop();
        }
        proce = proceso::listos.front();
        if(proceso::listos.size()>0 && proceso::listos.front()->getID() == -1){
            proce->imprimirVP();
            proceso::reloj++;
            if(proceso::listos.size()>1){
                proceso::listos.pop();
            }
        }else{
            proce->imprimir();
        }
    }
    proce->imprimirVP();
    imprimirF(proceso::terminados);
    system("pause");
	return 0;

    }

