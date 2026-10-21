
#include <iostream>
#include "Paciente.h"
#include "LectorArchivo.h"
#include "Estructura/Queue.h"
using namespace std;

int main() {

    Queue<Paciente> cola;

    LectorArchivo lector;
    lector.leerPacientes("pacientes.txt", cola);

    cout << "Pacientes en cola: " << cola.size() << endl;

    if (!cola.isEmpty()) {
        cout << "Primer paciente: " << cola.front().nombre << endl;
    }

    
    cout << "=== ATENDIENDO PACIENTES ===" << endl;

    while (!cola.isEmpty()) {
        Paciente atendido = cola.pop();

        cout << "Atendiendo a: " << atendido.nombre
            << " | ID: " << atendido.id << endl;
    }

    cout << "Pacientes restantes: " << cola.size() << endl;


    

    return 0;
}
