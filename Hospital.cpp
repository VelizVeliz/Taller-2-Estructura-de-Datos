#include "Hospital.h"
#include <iostream>

using namespace std;


Hospital::Hospital() {
    const string nombres[TOTAL_SERVICIOS] = {
        "Urgencias",
        "Medicina General",
        "Cardiologia",
        "Neurologia",
        "Traumatologia",
        "Cirugia",
        "Pediatria",
        "Hospitalizacion"
    };

    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        servicios[i] = new Servicio(nombres[i]);
    }
}

Hospital::~Hospital() {
    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        delete servicios[i]; // el destructor del AVL libera sus nodos
        servicios[i] = nullptr;
    }
}

Servicio* Hospital::getServicio(int posicion) {
    if (posicion < 0 || posicion >= TOTAL_SERVICIOS) {
        return nullptr;
    }

    return servicios[posicion];
}

int Hospital::getTotalServicios() const {
    return TOTAL_SERVICIOS;
}

Servicio* Hospital::buscarServicio(const string& nombre) {
    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        if (servicios[i]->getNombre() == nombre) {
            return servicios[i];
        }
    }

    return nullptr;
}

bool Hospital::existePaciente(const string& id) {
    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        if (servicios[i]->getArbol().buscar(id) != nullptr) {
            return true;
        }
    }

    return false;
}

NodoAVL* Hospital::buscarPaciente(const string& id, string& servicio, string& ruta) {
    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        string rutaServicio;
        NodoAVL* nodo = servicios[i]->getArbol().buscar(id, rutaServicio);

        if (nodo != nullptr) {
            servicio = servicios[i]->getNombre();
            ruta = rutaServicio;
            return nodo;
        }
    }

    return nullptr;
}

bool Hospital::atenderSiguiente(Queue<Paciente>& cola, ResultadoAtencion& resultado) {

    if (cola.isEmpty()) {
        return false;
    }

    // 1. Se retira de la cola (orden de llegada)
    Paciente paciente = cola.pop();

    resultado.paciente = paciente;
    resultado.insertado = false;
    resultado.motivo = "";

    // 2 y 3. Se evalua con el arbol de decision y se obtiene el servicio
    resultado.servicio = arbol.clasificar(paciente);

    Servicio* servicio = buscarServicio(resultado.servicio);

    if (servicio == nullptr) {
        resultado.motivo = "el servicio '" + resultado.servicio + "' no existe en el hospital";
        return true;
    }

    // El ID es unico en todo el hospital, no solo dentro de un servicio:
    // si ya esta registrado en cualquier AVL, no se vuelve a insertar.
    if (existePaciente(paciente.id)) {
        resultado.motivo = "ya existe un paciente con el ID " + paciente.id;
        return true;
    }

    // 4. Se inserta en el AVL del servicio
    servicio->getArbol().insertar(paciente);
    resultado.insertado = true;

    return true;
}

int Hospital::atenderTodos(Queue<Paciente>& cola) {

    cout << "=== ATENDIENDO PACIENTES ===" << endl;

    if (cola.isEmpty()) {
        cout << "No hay pacientes en la cola." << endl;
        return 0;
    }

    int atendidos = 0;
    int insertados = 0;
    ResultadoAtencion resultado;

    while (atenderSiguiente(cola, resultado)) {
        atendidos++;

        // 5. Se informa el resultado
        cout << "ID: " << resultado.paciente.id << endl;
        cout << "Nombre: " << resultado.paciente.nombre << endl;
        cout << "Edad: " << resultado.paciente.edad << endl;
        cout << "Servicio asignado: " << resultado.servicio << endl;

        if (resultado.insertado) {
            insertados++;
            cout << "Paciente insertado en el AVL de " << resultado.servicio << "." << endl;
        }
        else {
            cout << "No se inserto: " << resultado.motivo << "." << endl;
        }

        cout << "-------" << endl;
    }

    cout << "Pacientes atendidos: " << atendidos
         << " | Insertados: " << insertados
         << " | Rechazados: " << (atendidos - insertados) << endl;

    return insertados;
}

void Hospital::mostrarDepartamentos() {

    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;

    for (int i = 0; i < TOTAL_SERVICIOS; i++) {
        cout << servicios[i]->getNombre() << endl;

        string pacientes = servicios[i]->getArbol().inOrden();

        if (pacientes.empty()) {
            cout << "Sin pacientes" << endl;
        }
        else {
            cout << "Pacientes: " << pacientes << endl;
        }

        cout << endl;
    }
}