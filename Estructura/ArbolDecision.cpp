#include "ArbolDecision.h"
using namespace std;

ArbolDecision::ArbolDecision() {
    raiz = new NodoDecision("Edad menor a 14?");

    raiz->si = new NodoDecision("", "Pediatria");
    raiz->no = new NodoDecision("Trauma == 1?");

    raiz->no->si = new NodoDecision("Requiere cirugia == 1?");
    raiz->no->si->si = new NodoDecision("", "Cirugia");
    raiz->no->si->no = new NodoDecision("", "Traumatologia");

    raiz->no->no = new NodoDecision("Sintomas neurologicos == 1?");
    raiz->no->no->si = new NodoDecision("", "Neurologia");

    raiz->no->no->no = new NodoDecision("Temperatura >= 39?");
    raiz->no->no->no->si = new NodoDecision("", "Urgencias");

    raiz->no->no->no->no = new NodoDecision("Presion arterial >= 140?");
    raiz->no->no->no->no->si = new NodoDecision("", "Cardiologia");

    raiz->no->no->no->no->no = new NodoDecision("Dias hospitalizado > 0?");
    raiz->no->no->no->no->no->si = new NodoDecision("", "Hospitalizacion");
    raiz->no->no->no->no->no->no = new NodoDecision("", "Medicina General");
}

ArbolDecision::~ArbolDecision() {
    liberar(raiz);
}

void ArbolDecision::liberar(NodoDecision* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->si);
    liberar(nodo->no);

    delete nodo;
}
