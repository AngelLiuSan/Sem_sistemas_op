#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED
#include "Procesos.h"
#include <vector>
#include <iostream>
using namespace std;
class proceso;
class Lote {
    public:
        size_t numLote;
        size_t tam;
        vector<proceso*> proce;

        Lote ();
        Lote(size_t);
        void agregar(proceso*);
    };
Lote::Lote () {
    tam = 0;
    }
Lote::Lote(size_t numLote) {
    tam = 0;
    this->numLote = numLote;
    }
void Lote::agregar(proceso *proce) {
    if (tam > 5) {
        return;
        }
    this->proce.push_back(proce);
    tam++;
    }
#endif // LOTES_H_INCLUDED
