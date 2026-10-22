#include "ArbolDecision.h"
using namespace std;


ArbolDecision::ArbolDecision() {
    raiz = new NodoDecision("Edad menor a 14?");
    raiz->si = new NodoDecision("", "Pediatria");

    NodoDecision* trauma = new NodoDecision("Trauma == 1?");
    raiz->no = trauma;

    NodoDecision* cirugia = new NodoDecision("Requiere cirugia == 1?");
    trauma->si = cirugia;

    cirugia->si = new NodoDecision("", "Cirugia");
    cirugia->no = new NodoDecision("", "Traumatologia");

    NodoDecision* neurologia = new NodoDecision("Sintomas neurologicos == 1?");
    trauma->no = neurologia;

    neurologia->si = new NodoDecision("", "Neurologia");

    NodoDecision* temperatura = new NodoDecision("Temperatura >= 39?");
    neurologia->no = temperatura;

    temperatura->si = new NodoDecision("", "Urgencias");

    NodoDecision* presion = new NodoDecision("Presion arterial >= 140?");
    temperatura->no = presion;

    presion->si = new NodoDecision("", "Cardiologia");

    NodoDecision* hospitalizacion = new NodoDecision("Dias hospitalizado > 0?");
    presion->no = hospitalizacion;

    hospitalizacion->si = new NodoDecision("", "Hospitalizacion");
    hospitalizacion->no = new NodoDecision("", "Medicina General");
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
