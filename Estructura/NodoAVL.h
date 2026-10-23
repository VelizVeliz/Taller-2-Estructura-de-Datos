#pragma once

#include "../Paciente.h"

class NodoAVL {
public:

    Paciente paciente;

    NodoAVL* izquierda;
    NodoAVL* derecha;

    int altura;

    NodoAVL(Paciente paciente) {
        this->paciente = paciente;

        izquierda = nullptr;
        derecha = nullptr;

        altura = 1;
    }
};