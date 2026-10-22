#include <iostream>
#include "Paciente.h"
#include "LectorArchivo.h"
#include "Estructura/Queue.h"
#include "Estructura/ArbolDecision.h"
using namespace std;

int main() {
    ArbolDecision arbol;

    Queue<Paciente> cola;

    LectorArchivo lector;
    lector.leerPacientes("pacientes.txt", cola);

    cout << "pacientes en cola: " << cola.size() << endl;

    if (!cola.isEmpty()) {
        cout << "primer paciente: " << cola.front().nombre << endl;
    }

    
    cout << "---atendiendo pacientes---" << endl;

    while (!cola.isEmpty()) {
        Paciente atendido = cola.pop();

        cout << "Atendiendo a: " << atendido.nombre
            << " | ID: " << atendido.id << endl;
    }

    cout << "Pacientes restantes: " << cola.size() << endl;


    

    return 0;
}
