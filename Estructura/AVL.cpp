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

//  BUSQUEDA POR ID
 

NodoAVL* AVL::buscar(NodoAVL* nodo, const string& id, string& ruta)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }
 
    if (!ruta.empty())
    {
        ruta += " -> ";
    }
    ruta += nodo->paciente.id;
 
    if (id == nodo->paciente.id)
    {
        return nodo;
    }
 
    if (id < nodo->paciente.id)
    {
        return buscar(nodo->izquierda, id, ruta);
    }
 
    return buscar(nodo->derecha, id, ruta);
}
 
NodoAVL* AVL::buscar(const string& id, string& ruta)
{
    ruta = "";
    return buscar(raiz, id, ruta);
}
 
NodoAVL* AVL::buscar(const string& id)
{
    string ruta;
    return buscar(raiz, id, ruta);
}
 

//  ELIMINACION POR ID
 
NodoAVL* AVL::minimo(NodoAVL* nodo)
{
    while (nodo != nullptr && nodo->izquierda != nullptr)
    {
        nodo = nodo->izquierda;
    }
 
    return nodo;
}
 
// Recalcula la altura del nodo y, si |balance| > 1, aplica la rotacion adecuada.
// En la eliminacion no se puede decidir el caso comparando el ID eliminado
// (como en la insercion), asi que se mira el balance del hijo mas cargado.
// Si el hijo esta equilibrado (balance 0) se prefiere la rotacion simple.
NodoAVL* AVL::rebalancear(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return nullptr;
    }
 
    nodo->altura =
        1 + max(
            altura(nodo->izquierda),
            altura(nodo->derecha)
        );
 
    int balance = factorBalance(nodo);
 
    // Cargado a la izquierda
    if (balance > 1)
    {
        // Caso LL: rotacion simple derecha
        if (factorBalance(nodo->izquierda) >= 0)
        {
            return rotacionDerecha(nodo);
        }
 
        // Caso LR: rotacion doble izquierda-derecha
        return rotacionIzquierdaDerecha(nodo);
    }
 
    // Cargado a la derecha
    if (balance < -1)
    {
        // Caso RR: rotacion simple izquierda
        if (factorBalance(nodo->derecha) <= 0)
        {
            return rotacionIzquierda(nodo);
        }
 
        // Caso RL: rotacion doble derecha-izquierda
        return rotacionDerechaIzquierda(nodo);
    }
 
    return nodo;
}
 
NodoAVL* AVL::eliminar(NodoAVL* nodo, const string& id, bool& eliminado)
{
    // El ID no existe en el arbol
    if (nodo == nullptr)
    {
        return nullptr;
    }
 
    if (id < nodo->paciente.id)
    {
        nodo->izquierda = eliminar(nodo->izquierda, id, eliminado);
    }
    else if (id > nodo->paciente.id)
    {
        nodo->derecha = eliminar(nodo->derecha, id, eliminado);
    }
    else
    {
        // Encontramos el nodo a eliminar
        eliminado = true;
 
        // Caso 1 y 2: hoja o con un solo hijo
        if (nodo->izquierda == nullptr || nodo->derecha == nullptr)
        {
            NodoAVL* hijo =
                (nodo->izquierda != nullptr) ? nodo->izquierda : nodo->derecha;
 
            delete nodo;
            return hijo; 
        }
 
        // Caso 3: dos hijos
        NodoAVL* sucesor = minimo(nodo->derecha);
        nodo->paciente = sucesor->paciente;
 
        bool aux = false;
        nodo->derecha = eliminar(nodo->derecha, sucesor->paciente.id, aux);
    }
 
    // Al volver de la recursion se revisa el balance de cada nodo del camino
    return rebalancear(nodo);
}
 
bool AVL::eliminar(const string& id)
{
    bool eliminado = false;
    raiz = eliminar(raiz, id, eliminado);
    return eliminado;
}