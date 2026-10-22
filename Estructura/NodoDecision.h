#pragma once
#include <string>
using namespace std;

class NodoDecision {
public:
    string pregunta;
    string servicio;

    NodoDecision* si;
    NodoDecision* no;

    NodoDecision(string pregunta, string servicio = "") {
        this->pregunta = pregunta;
        this->servicio = servicio;
        this->si = nullptr;
        this->no = nullptr;
    }
};
