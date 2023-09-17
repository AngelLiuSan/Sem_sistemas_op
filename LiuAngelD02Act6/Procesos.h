#ifndef PROCESOS_H_INCLUDED
#define PROCESOS_H_INCLUDED
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <limits>
#include <bits/stdc++.h>
using namespace std;
class proceso {
    private:
        long long ID;
        int Operacion;
        long long a;
        long long b;
        long long tiempo;
        long long tt;
        long long tr;
        string resul;
    public:
        static queue<proceso*> listos;
        static queue<proceso*> terminados;
        static queue<proceso*> nuevos;
        static queue<proceso*> bloqueados;
        static int reloj;
        bool band;
        long long ttb;
        long long TL;
        long long TF;
        long long TRET;
        long long TRES;
        long long TE;
        long long TS;

        proceso();
        void setID(long long);
        void setOperacion(int);
        void seta(long long);
        void setb(long long);
        void settiempo(long long);
        void settt(long long);
        void settr(long long);
        void setresul(string);


        long long getID();
        int getOperacion();
        long long geta();
        long long getb();
        long long gettiempo();
        long long gettt();
        long long gettr();
        string getresul();

        long long operacioness(long long,long long,long long);
        char operation(int);

        void imprimirP() {//CAMBIO
            tt++;
            TS++;
            tr--;
            reloj++;
            band = true;
            cout << endl << "\n\tEjecucion:" << endl;
            cout << endl << "\n\tProceso en ejecucion:" << endl;
            cout << "\n\tID: " << getID() << endl;
            cout << "\n\tOperacion: " << geta() << operation(getOperacion()) << getb() << endl;
            cout << "\n\tTiempo: " << gettiempo() << endl;
            cout << "\n\tTT: " << gettt() << endl;
            cout << "\n\tTR: " << gettr() << endl << endl;
            }

        void imprimirT() {///////////////////CAMBIO
            auto terminadosAux = terminados;
            cout << "\n\tTerminados" << endl;
            cout << "\n\tID\t|\tOpe\t|\tRes" << endl;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            while(!terminadosAux.empty()) {
                cout << "\n\t" << terminadosAux.front()->getID() <<"\t|\t"<<terminadosAux.front()->geta()<<terminadosAux.front()->operation(terminadosAux.front()->getOperacion())<<terminadosAux.front()->getb()<<"\t|\t"<<terminadosAux.front()->getresul() << endl;
                terminadosAux.pop();
                }
            cout << endl;
            }

        void imprimirB() { ///////////////////NUEVO
            auto bloqueadosAux = bloqueados;
            bloqueados = {};
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            cout<<"\n\tBloqueados"<<endl;
            cout<<"\n\tID\t|\tTT en bloqueado"<<endl;
            while(!bloqueadosAux.empty()) {
                cout<<"\n\t"<<bloqueadosAux.front()->getID()<<"\t|\t"<<bloqueadosAux.front()->ttb<<endl;
                bloqueadosAux.front()->ttb++;
                bloqueadosAux.front()->TE++;
                if(bloqueadosAux.front()->ttb==8) {
                    bloqueadosAux.front()->ttb=0;
                    listos.push(bloqueadosAux.front());
                    bloqueadosAux.pop();
                    }
                else {
                    bloqueados.push(bloqueadosAux.front());
                    bloqueadosAux.pop();
                    }
                }
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            }

        void imprimirPL() {///////////////////NUEVO
            auto memoriaAux = listos;
            cout << "\n\tNuevo: " << nuevos.size() << endl;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            cout<<"\n\tListos: "<<endl;
            cout<<"\n\tID\t|\tTME\t|\tTT"<<endl;
            while(!memoriaAux.empty()) {
                auto proceso = memoriaAux.front();
                if(proceso!=this) {
                    if(proceso->band == false) {
                        proceso->TRES++;
                        }
                    proceso->TE++;
                    cout<<"\n\t"<<proceso->getID()<<"\t|\t"<<proceso->gettiempo()<<"\t|\t"<<proceso->gettt()<<endl;
                    }
                memoriaAux.pop();
                }
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            }


        void imprimirV() {
            system("cls");
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            imprimirPL();
            cout<<endl<<"\n\tEjecucion:"<<endl;
            cout<<endl<<"\n\tProceso en ejecucion:"<<endl;
            cout<<"\n\tId: "<<endl;
            cout<<"\n\tOperacion: "<<endl;
            cout<<"\n\tTME: "<<endl;
            cout<<"\n\tTT: "<<endl;
            cout<<"\n\tTR: "<<endl<<endl;
            imprimirB();
            imprimirT();
            cout<<"\n\tReloj global: "<<reloj<<endl;
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            Sleep(1000);
            system("cls");
            }
         void imprimirVP() {
            system("cls");
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            imprimirPL();
            cout<<endl<<"\n\tEjecucion:"<<endl;
            cout<<endl<<"\n\tProceso en ejecucion:"<<endl;
            cout<<"\n\tId: "<<endl;
            cout<<"\n\tOperacion: "<<endl;
            cout<<"\n\tTME: "<<endl;
            cout<<"\n\tTT: "<<endl;
            cout<<"\n\tTR: "<<endl<<endl;
            imprimirB();
            imprimirT();
            cout<<"\n\tReloj global: "<<reloj<<endl;
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            Sleep(1000);
            system("PAUSE");
            system("cls");
            }
        void imprimir() {//CAMBIO
            system("cls");
            tr = gettiempo()-tt;
            while(tr > -1) {
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                imprimirPL();
                imprimirP();
                imprimirB();
                imprimirT();
                cout<<"\n\tReloj global: "<<reloj+tt<<endl;
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                if ( kbhit() ) {
                    char tecla  = getch();
                    switch(tecla ) {
                        case 'i':
                            if(listos.size()>0) {
                                bloqueados.push(this);
                                listos.pop();
                                if(listos.size()==0) {
                                    auto procesoA = new proceso();
                                    listos.push(procesoA);
                                    }
                                return;
                                }
                            break;
                        case 'e':
                            setresul("ERROR");
                            if(listos.size()>0) {
                                TF = reloj;
                                terminados.push(this);
                                listos.pop();
                                }
                            return;
                            break;
                        case 'p':
                            while(tecla!='c') {
                                tecla = getch();
                                }
                        }
                    }
                Sleep(1000);
                system("cls");
                }
            TF = reloj;
            setresul(to_string(operacioness(getOperacion(),geta(),getb())));;
            terminados.push(this);
            if(listos.size()>0) {
                listos.pop();
                }
            }

    };
proceso::proceso() {//CAMBIO
    ID = -1;
    a  = -1;
    b  = -1;
    Operacion = '\x0';
    tiempo = -1;
    tt = 0;
    tr = -1;
    ttb = 0;

    TL = 0;
    TF = 0;
    TRET = 0;
    TRES = 0;
    TE = 0;
    TS = -1;
    band = false;
    }
void proceso::setID(long long ide) {
    ID=ide;
    }
void proceso::setOperacion(int ope) {
    Operacion=ope;
    }
void proceso::seta(long long aa) {
    a=aa;
    }
void proceso::setb(long long bb) {
    b=bb;
    }
void proceso::settiempo(long long time) {
    tiempo=time;
    }
void proceso::settt(long long ttt) {
    tt=ttt;
    }
void proceso::settr(long long trr) {
    tr=trr;
    }
void proceso::setresul(string result) {
    resul=result;
    }
//-----------------------------------------
long long proceso::getID() {
    return ID;
    }
int proceso::getOperacion() {
    return Operacion;
    }
long long proceso::geta() {
    return a;
    }
long long proceso::getb() {
    return b;
    }
long long proceso::gettiempo() {
    return tiempo;
    }
long long proceso::gettt() {
    return tt;
    }
long long proceso::gettr() {
    return tr;
    }
string proceso::getresul() {
    return resul;
    }
//-----------------------------------------
long long proceso::operacioness(long long ope,long long a,long long b) {
    switch(ope) {
        case 1:
            return a+b;
            break;
        case 2:
            return a-b;
            break;
        case 3:
            return a*b;
            break;
        case 4:
            return a/b;
            break;
        case 5:
            return a%b;
            break;
        case 6:
            return pow(a,b);
            break;
        default:
            return '\x0';
        }
    }
char proceso::operation(int ope) {
    switch(ope) {
        case 1:
            return '+';
            break;
        case 2:
            return '-';
            break;
        case 3:
            return '*';
            break;
        case 4:
            return '/';
            break;
        case 5:
            return '%';
            break;
        case 6:
            return '^';
            break;
        default:
            return '\x0';
        }
    }
#endif // PROCESOS_H_INCLUDED
