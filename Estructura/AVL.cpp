#include "AVL.h"
#include <algorithm>

using namespace std;

AVL::AVL() {
    raiz = nullptr;
}

NodoAVL* AVL::getRaiz() {
    return raiz;
}

void AVL::insertar(Paciente paciente) {
    raiz = insertar(raiz, paciente);
}

NodoAVL* AVL::insertar(
    NodoAVL* nodo,
    Paciente paciente
) {

    if (nodo == nullptr) {
        return new NodoAVL(paciente);
    }

    if (paciente.id < nodo->paciente.id) {

        nodo->izquierda =
            insertar(
                nodo->izquierda,
                paciente
            );
    }

    else if (paciente.id > nodo->paciente.id) {

        nodo->derecha =
            insertar(
                nodo->derecha,
                paciente
            );
    }

    else {
        return nodo;
    }

    nodo->altura =
        1 + max(
            altura(nodo->izquierda),
            altura(nodo->derecha)
        );

    int balance = factorBalance(nodo);

    // Caso Izquierda-Izquierda (LL)
    if (balance > 1 &&
        paciente.id < nodo->izquierda->paciente.id)
    {
        return rotacionDerecha(nodo);
    }

    // Caso Derecha-Derecha (RR)
    if (balance < -1 &&
        paciente.id > nodo->derecha->paciente.id)
    {
        return rotacionIzquierda(nodo);
    }

    // Caso Izquierda-Derecha (LR)
    if (balance > 1 &&
        paciente.id > nodo->izquierda->paciente.id)
    {
        return rotacionIzquierdaDerecha(nodo);
    }

    // Caso Derecha-Izquierda (RL)
    if (balance < -1 &&
        paciente.id < nodo->derecha->paciente.id)
    {
        return rotacionDerechaIzquierda(nodo);
    }

    return nodo;
}

int AVL::altura(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }

    return nodo->altura;
}

int AVL::factorBalance(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }

    return altura(nodo->izquierda)
         - altura(nodo->derecha);
}

NodoAVL* AVL::rotacionDerecha(NodoAVL* y)
{
    NodoAVL* x = y->izquierda;
    NodoAVL* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura =
        max(
            altura(y->izquierda),
            altura(y->derecha)
        ) + 1;

    x->altura =
        max(
            altura(x->izquierda),
            altura(x->derecha)
        ) + 1;

    return x;
}

NodoAVL* AVL::rotacionIzquierda(NodoAVL* x)
{
    NodoAVL* y = x->derecha;
    NodoAVL* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura =
        max(
            altura(x->izquierda),
            altura(x->derecha)
        ) + 1;

    y->altura =
        max(
            altura(y->izquierda),
            altura(y->derecha)
        ) + 1;

    return y;
}

NodoAVL* AVL::rotacionIzquierdaDerecha(NodoAVL* nodo)
{
    nodo->izquierda =
        rotacionIzquierda(
            nodo->izquierda
        );

    return rotacionDerecha(nodo);
}

NodoAVL* AVL::rotacionDerechaIzquierda(NodoAVL* nodo)
{
    nodo->derecha =
        rotacionDerecha(
            nodo->derecha
        );

    return rotacionIzquierda(nodo);
}