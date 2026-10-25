#pragma once
#include <string>
#include "Paciente.h"
#include "Servicio.h"
#include "Estructura/Queue.h"
#include "Estructura/ArbolDecision.h"
using namespace std;

// Resultado de atender a un paciente de la cola.
struct ResultadoAtencion {
    Paciente paciente;
    string servicio;   // servicio que asigno el arbol de decision
    bool insertado;    // true si quedo guardado en el AVL del servicio
    string motivo;     // si no se inserto, explica por que
};

// Conecta todo el flujo:  Cola -> Arbol de decision -> Servicio -> AVL
class Hospital {
private:
    static const int TOTAL_SERVICIOS = 8;

    Servicio* servicios[TOTAL_SERVICIOS];
    ArbolDecision arbol;

    // Devuelve el servicio con ese nombre, o nullptr si no existe.
    Servicio* buscarServicio(const string& nombre);

public:
    Hospital();

    ~Hospital();

    
    Hospital(const Hospital&) = delete;
    Hospital& operator=(const Hospital&) = delete;

    
    bool atenderSiguiente(Queue<Paciente>& cola, ResultadoAtencion& resultado);

    
    int atenderTodos(Queue<Paciente>& cola);

    bool existePaciente(const string& id);

    
    NodoAVL* buscarPaciente(const string& id, string& servicio, string& ruta);

    void mostrarDepartamentos();

    Servicio* getServicio(int posicion);

    int getTotalServicios() const;
};