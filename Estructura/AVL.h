#pragma once

#include <string>
#include "NodoAVL.h"

using namespace std;

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

    // --- Busqueda y eliminacion ---
 
    // Devuelve el nodo con ese ID (o nullptr). Va armando la ruta recorrida.
    NodoAVL* buscar(NodoAVL* nodo, const string& id, string& ruta);
 
    // Nodo con el menor ID de un subarbol (el mas a la izquierda).
    NodoAVL* minimo(NodoAVL* nodo);
 
    // Actualiza la altura del nodo y aplica la rotacion que corresponda.
    NodoAVL* rebalancear(NodoAVL* nodo);
 
    // Eliminacion recursiva. 'eliminado' indica si el ID existia.
    NodoAVL* eliminar(NodoAVL* nodo, const string& id, bool& eliminado);

    // --- Recorridos y memoria ---
 
    // Agrega "Nombre (ID)" al final de 'salida', separado por ", " del anterior.
    void agregarPaciente(NodoAVL* nodo, string& salida);
 
    void inOrden(NodoAVL* nodo, string& salida);
    void preOrden(NodoAVL* nodo, string& salida);
    void postOrden(NodoAVL* nodo, string& salida);
 
    // Libera todos los nodos del subarbol (en postorden).
    void liberar(NodoAVL* nodo);


public:

    AVL();

    ~AVL();

    
    AVL(const AVL&) = delete;
    AVL& operator=(const AVL&) = delete;

    void insertar(Paciente paciente);
    
    string inOrden();
    
    string preOrden();
    
    string postOrden();

    // Busca un paciente por ID. Devuelve el nodo o nullptr si no existe.
    NodoAVL* buscar(const string& id);
 
    // Igual que la anterior, pero ademas entrega la ruta
    NodoAVL* buscar(const string& id, string& ruta);
 
    // Elimina un paciente por ID manteniendo el balance. true si existia.
    bool eliminar(const string& id);

    NodoAVL* getRaiz();
};