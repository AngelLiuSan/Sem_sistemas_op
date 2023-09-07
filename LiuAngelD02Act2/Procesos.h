#ifndef PROCESOS_H_INCLUDED
#define PROCESOS_H_INCLUDED
#include <math.h>
#include "Lotes.h"
using namespace std;
class proceso {
    private:
        string nombre;
        int ID;
        int Operacion;
        int a;
        int b;
        int tiempo;
        int tt;
        int tr;
        int resul;
    public:
        proceso();
        void setnombre(string);
        void setID(int);
        void setOperacion(int);
        void seta(int);
        void setb(int);
        void settiempo(int);
        void settt(int);
        void settr(int);
        void setresul(int);

        string getnombre();
        int getID();
        int getOperacion();
        int geta();
        int getb();
        int gettiempo();
        int gettt();
        int gettr();
        int getresul();

        int operacioness(int,int,int);
        char operation(int);

        void imprimirP() {
            cout << endl << "\n\tProceso en ejecucion:" << endl;
            cout << "\n\tNombre: " << getnombre() << endl;
            cout << "\n\tID: " << getID() << endl;
            cout << "\n\tOperacion: " << geta() << operation(getOperacion()) << getb() << endl;
            cout << "\n\tTiempo: " << gettiempo() << endl;
            cout << "\n\tTT: " << gettt() << endl;
            cout << "\n\tTR: " << gettr() << endl << endl;
            }

        void imprimirT(vector<proceso*> terminados) {
            cout << "\n\tTerminados" << endl;
            cout << "\n\tID\t|\tOpe\t|\tRes" << endl;
            int i = 1;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            for (auto proce:terminados) {
                cout << "\n\t" << proce->getID() <<"\t|\t"<<proce->geta()<<proce->operation(proce->getOperacion())<<proce->getb()<<"\t|\t"<<proce->getresul() << endl;
                if (i % 5 == 0) {
                    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
                    }
                i++;
                }
            cout << endl;
            }


        void imprimirL(Lote lote) {
            cout << "\n\tLote trabajando: " << lote.numLote << endl;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            cout << "\n\tNombre\t|\tTiempo" << endl;
            auto it= lote.proce.begin()+1;
            for (; it != lote.proce.end(); ++it) {
                cout << "\n\t" << (*it)->getnombre() << "\t|\t" << (*it)->gettiempo() << endl;
                }
            }
        void imprimirLV(Lote lote) {
            cout << "\n\tLote trabajando: " << lote.numLote << endl;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            cout << "\n\tNombre\t|\tTiempo" << endl;
            for (auto proce:lote.proce) {
                cout << "\n\t" << proce->getnombre() << "\t|\t" << proce->gettiempo() << endl;
                }
            }

        void imprimirV(Lote &lote, int lp, vector<proceso*> &t, int reloj) {
            imprimirLV(lote);
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            cout<<"\n\tNo. lotes pendientes: "<<lp<<endl<<endl;
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            cout<<endl<<"\n\tProceso en ejecucion:"<<endl;
            cout<<"\n\tNombre: "<<endl;
            cout<<"\n\tId: "<<endl;
            cout<<"\n\tOperacion: "<<endl;
            cout<<"\n\tTME: "<<endl;
            cout<<"\n\tTT: "<<endl;
            cout<<"\n\tTR: "<<endl<<endl;
            imprimirT(t);
            cout<<"\n\tReloj global: "<<reloj<<endl;
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
            Sleep(1000);

            }

        void imprimir(Lote &lote, int lp, vector<proceso*> &t, int c) {
            tr = gettiempo();
            tt = 0;
            while(tr > -1) {
                imprimirL(lote);
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                cout<<"\n\tNo. lotes pendientes: "<<lp<<endl<<endl;
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                imprimirP();
                imprimirT(t);
                cout<<"\n\tReloj global: "<<c+tt<<endl;
                cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                tt++;
                tr--;
                Sleep(1000);
                system("cls");
                }
            setresul(operacioness(getOperacion(),geta(),getb()));

            if(lote.proce.size()>0) {
                lote.proce.erase(lote.proce.begin());
                }

            t.push_back(this);
            }

    };
proceso::proceso() {
    nombre = "";
    ID = -1;
    a  = -1;
    b  = -1;
    Operacion = '\x0';
    tiempo = -1;
    tt = -1;
    tr = -1;
    }
void proceso::setnombre(string name) {
    nombre=name;
    }
void proceso::setID(int ide) {
    ID=ide;
    }
void proceso::setOperacion(int ope) {
    Operacion=ope;
    }
void proceso::seta(int aa) {
    a=aa;
    }
void proceso::setb(int bb) {
    b=bb;
    }
void proceso::settiempo(int time) {
    tiempo=time;
    }
void proceso::settt(int ttt) {
    tt=ttt;
    }
void proceso::settr(int trr) {
    tr=trr;
    }
void proceso::setresul(int result) {
    resul=result;
    }
//-----------------------------------------
string proceso::getnombre() {
    return nombre;
    }
int proceso::getID() {
    return ID;
    }
int proceso::getOperacion() {
    return Operacion;
    }
int proceso::geta() {
    return a;
    }
int proceso::getb() {
    return b;
    }
int proceso::gettiempo() {
    return tiempo;
    }
int proceso::gettt() {
    return tt;
    }
int proceso::gettr() {
    return tr;
    }
int proceso::getresul() {
    return resul;
    }
//-----------------------------------------
int proceso::operacioness(int ope,int a,int b) {
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
