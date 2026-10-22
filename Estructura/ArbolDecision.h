#pragma once
#include <string>
#include "NodoDecision.h"
#include "../Paciente.h"
using namespace std;

class ArbolDecision {
private:
    NodoDecision* raiz;
    void liberar(NodoDecision* nodo);

public:
    ArbolDecision();
    ~ArbolDecision();

    string clasificar(Paciente paciente);

    void preOrden();
    void inOrden();
    void postOrden();
};
