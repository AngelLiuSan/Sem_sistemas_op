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

   for(int i=0;i<pro;i++){
        auxp = new proceso();

        //cout << "\n\tIngrese el ID:" << endl;
        auxp->setID(i+1);

        //cout << "\n\tElija la operacion." << endl;

        auxp->setOperacion(rand()%6+1);
        /////////////////////////////////////////////////
        /*cout << "\n\tIngrese a:" << endl;*/

        auxp->seta(0 + rand() % 100);
        /////////////////////////////////////////////////
        /*cout << "\n\tIngrese b:" << endl;*/

        auxp->setb(0 + rand() % 100);
        while(auxp->getb() == 0 && (auxp->getOperacion()==4 || auxp->getOperacion()==5)||auxp->getb() >2 && (auxp->getOperacion()==6)){
            auxp->setb(0 + rand() % 2);
        }
        //cout << "\n\tIngrese el tiempo:" << endl;
        int numeroAleatorio = 6 + rand() % 13;
        auxp->settiempo(numeroAleatorio);
        /////////////////////////////////////////////////
        proceso::nuevos.push(auxp);

        }
        system("PAUSE");
        system("cls");
////////////////////////////////////////////////////////////////
    proceso *proce = new proceso();
    while(!proceso::nuevos.empty() || !proceso::bloqueados.empty() || (!proceso::listos.empty() && proceso::listos.front()->getID()!=-1)){
        for(int i=proceso::listos.size()+proceso::bloqueados.size();i<5;i++){
            if(!proceso::nuevos.empty()){
                proceso::nuevos.front()->TL = proceso::reloj;
                proceso::listos.push(proceso::nuevos.front());
                proceso::nuevos.pop();
            }
        }
        do{
            proce = proceso::listos.front();
            if(proceso::listos.size()>0 && proceso::listos.front()->getID() == -1){
                proce->imprimirV();
                proceso::reloj++;
                if(proceso::listos.size()>1){
                    proceso::listos.pop();
                }
            }else{
                proce->imprimir();

            }
        }while((proceso::listos.size()+proceso::bloqueados.size()>4));
    }
    proce->imprimirVP();
    imprimirF(proceso::terminados);
    system("pause");
	return 0;
    }

