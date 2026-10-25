#include <iostream>
#include <string>
#include "Hospital.h"
#include "LectorArchivo.h"
using namespace std;

int main() {
    Queue<Paciente> cola;
    LectorArchivo lector;
    Hospital hospital;
    ArbolDecision arbol;

    lector.leerPacientes("pacientes.txt", cola);

    int opcion;

    do {
        cout << "=== menu hospital ===" << endl;
        cout << "1. atender pacientes de la cola" << endl;
        cout << "2. mostrar servicios y pacientes" << endl;
        cout << "3. buscar paciente por ID" << endl;
        cout << "4. eliminar paciente por ID" << endl;
        cout << "5. recorridos del arbol de decision" << endl;
        cout << "6. recorridos de los AVL" << endl;
        cout << "7. salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            hospital.atenderTodos(cola);
            break;

        case 2:
            hospital.mostrarDepartamentos();
            break;

        case 3: {
            string id, servicio, ruta;

            cout << "Id del paciente: ";
            cin >> id;

            NodoAVL* encontrado = hospital.buscarPaciente(id, servicio, ruta);

            if (encontrado != nullptr) {
                cout << "Nombre: " << encontrado->paciente.nombre << endl;
                cout << "Servicio: " << servicio << endl;
                cout << "Ruta: " << ruta << endl;
            }
            else {
                cout << "Paciente no encontrado." << endl;
            }
            break;
        }

        case 4: {
            string id;
            bool eliminado = false;

            cout << "ID del paciente: ";
            cin >> id;

            for (int i = 0; i < hospital.getTotalServicios(); i++) {
                Servicio* servicio = hospital.getServicio(i);

                if (servicio->getArbol().eliminar(id)) {
                    cout << "paciente eliminado de "<< servicio->getNombre() << endl;
                    eliminado = true;
                    break;
                }
            }

            if (!eliminado) {
                cout << "Paciente no encontrado" << endl;
            }
            break;
        }

        case 5:
            cout << "Preorden" << endl;
            arbol.preOrden();

            cout << "Inorden" << endl;
            arbol.inOrden();

            cout << "Postorden" << endl;
            arbol.postOrden();
            break;

        case 6:
            for (int i = 0; i < hospital.getTotalServicios(); i++) {
                Servicio* servicio = hospital.getServicio(i);

                cout << servicio->getNombre() << endl;
                cout << "preorden: "<< servicio->getArbol().preOrden() << endl;
                cout << "inorden: "<< servicio->getArbol().inOrden() << endl;
                cout << "postorden: "<< servicio->getArbol().postOrden() << endl;
            }
            break;

        case 7:
            cout << "saliendo" << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 7);

    return 0;
}
