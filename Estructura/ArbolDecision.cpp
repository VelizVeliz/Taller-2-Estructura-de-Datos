#include "ArbolDecision.h"
#include <iostream>

using namespace std;

// Funciones auxiliares para recorridos
void preOrdenAux(NodoDecision* nodo);
void inOrdenAux(NodoDecision* nodo);
void postOrdenAux(NodoDecision* nodo);

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

string ArbolDecision::clasificar(Paciente paciente) {

    if (paciente.edad < 14) {
        return "Pediatria";
    }

    if (paciente.trauma == 1) {

        if (paciente.necesitaCirugia == 1) {
            return "Cirugia";
        }

        return "Traumatologia";
    }

    if (paciente.sintomasNeurologicos == 1) {
        return "Neurologia";
    }

    if (paciente.temperatura >= 39) {
        return "Urgencias";
    }

    if (paciente.presionArterial >= 140) {
        return "Cardiologia";
    }

    if (paciente.diasHospitalizado > 0) {
        return "Hospitalizacion";
    }

    return "Medicina General";
}

//Como preorden, inorden y postorden son recursivos y no necesitan parámetros 
//se crean funciones auxiliares para que el usuario pueda llamarlas sin necesidad de pasarle un nodo como parámetro.

void ArbolDecision::preOrden() {
    preOrdenAux(raiz);
}

void ArbolDecision::inOrden() {
    inOrdenAux(raiz);
}

void ArbolDecision::postOrden() {
    postOrdenAux(raiz);
}

// Funciones auxiliares para los recorridos

void preOrdenAux(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    if (nodo->pregunta != "") {
        cout << nodo->pregunta << endl;
    }
    else {
        cout << nodo->servicio << endl;
    }

    preOrdenAux(nodo->si);
    preOrdenAux(nodo->no);
}

void inOrdenAux(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    inOrdenAux(nodo->si);

    if (nodo->pregunta != "") {
        cout << nodo->pregunta << endl;
    }
    else {
        cout << nodo->servicio << endl;
    }

    inOrdenAux(nodo->no);
}

void postOrdenAux(NodoDecision* nodo) {

    if (nodo == nullptr) {
        return;
    }

    postOrdenAux(nodo->si);
    postOrdenAux(nodo->no);

    if (nodo->pregunta != "") {
        cout << nodo->pregunta << endl;
    }
    else {
        cout << nodo->servicio << endl;
    }
}

