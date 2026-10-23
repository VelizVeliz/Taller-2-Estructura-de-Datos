#pragma once

#include "NodoAVL.h"

class AVL {

private:

    NodoAVL* raiz;

    NodoAVL* insertar(NodoAVL* nodo, Paciente paciente);

    int altura(NodoAVL* nodo);

    int factorBalance(NodoAVL* nodo);

    NodoAVL* rotacionDerecha(NodoAVL* y);

    NodoAVL* rotacionIzquierda(NodoAVL* x);

    NodoAVL* rotacionIzquierdaDerecha(NodoAVL* nodo);

    NodoAVL* rotacionDerechaIzquierda(NodoAVL* nodo);


public:

    AVL();

    void insertar(Paciente paciente);

    NodoAVL* getRaiz();
};