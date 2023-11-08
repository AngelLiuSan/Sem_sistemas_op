#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const size_t numMarcos = 44;
const size_t marcosSO = 4;
const size_t tamMarcos = 5;
class Memoria {
    private:
        int libre = 0;
    public:
        string marcos[numMarcos][tamMarcos] = {};
        void LESO() {
            for(size_t i=numMarcos-marcosSO; i<numMarcos; i++) {
                for(size_t j=0; j<tamMarcos; j++) {
                    marcos[i][j] = "S.O.";
                    }
                }
            }
        Memoria() {
            for(size_t i=0; i<numMarcos; i++) {
                for(size_t j=0; j<tamMarcos; j++) {
                    marcos[i][j] = "-1";
                    }
                }
            LESO();
            }
        void mostrarMemoria() {
            size_t contador = 0;
            cout<<"Marco\tEspacio\tProceso\t\tMarco\tEspacio\tProceso\t\tMarco\tEspacio\tProceso\t\tMarco\tEspacio\tProceso\t\tMarco\tEspacio\tProceso\t\t"<<endl;
            for(size_t i=0; i<numMarcos; i++) {
                contador = 0;
                for(size_t j=0; j<tamMarcos; j++) {
                    if(marcos[i][j]!="-1") {
                        contador++;
                        }
                    }
                if(contador == 0) {
                    cout<<i<<"\t0/"<<tamMarcos<<"\tN/A°°\t\t";
                    }
                else {
                    cout<<i<<"\t"<<contador<<"/"<<tamMarcos<<"\t"<<marcos[i][0]<<"°°\t\t";
                    }
                if((i+1)%5==0) {
                    cout<<endl;
                    }
                }
            cout<<endl;
            }
        void insertarEnMemoria(string id, size_t tam) {
            for(size_t i=0; i<numMarcos; i++) {
                if(marcos[i][0] == "-1") {
                    for(size_t j=0; j<tamMarcos; j++) {
                        if(tam == 0) {
                            return;
                            }
                        marcos[i][j] = id;
                        tam--;
                        }
                    }
                }
            marcosLibres();
            }
        void liberarMemoria(string id) {
            for(size_t i=0; i<numMarcos; i++) {
                if(marcos[i][0] == id) {
                    for(size_t j = 0; j<tamMarcos; j++) {
                        marcos[i][j] = "-1";
                        }
                    }
                }
            marcosLibres();
            }
        int marcosLibres() {
            size_t libres = 0;
            for(size_t i=0; i<numMarcos; i++) {
                if(marcos[i][0] == "-1") {
                    libres++;
                    }
                }
            libre = libres;
            return libres;
            }
    };




#endif // MEMORY_H_INCLUDED
