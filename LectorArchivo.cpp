#include "LectorArchivo.h"
#include "Paciente.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void LectorArchivo::leerPacientes(string nombreArchivo, Queue<Paciente>& cola) {
    ifstream archivo;
    string linea;
    archivo.open(nombreArchivo);

    if (!archivo) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    cout << "Archivo abierto correctamente" << endl;

    while (getline(archivo, linea)) {
        Paciente paciente;
        stringstream partes(linea);

        string id, nombre, edad, temperatura, presionArterial, dolor;
        string tipoDolor, trauma, sintomasNeurologicos, necesitaCirugia, diasHospitalizado;

        getline(partes, id, '|');
        getline(partes, nombre, '|');
        getline(partes, edad, '|');
        getline(partes, temperatura, '|');
        getline(partes, presionArterial, '|');
        getline(partes, dolor, '|');
        getline(partes, tipoDolor, '|');
        getline(partes, trauma, '|');
        getline(partes, sintomasNeurologicos, '|');
        getline(partes, necesitaCirugia, '|');
        getline(partes, diasHospitalizado, '|');

        paciente.id = id;
        paciente.nombre = nombre;
        paciente.edad = stoi(edad);
        paciente.temperatura = stod(temperatura);
        paciente.presionArterial = stoi(presionArterial);
        paciente.dolor = stoi(dolor);
        paciente.tipoDolor = tipoDolor;
        paciente.trauma = stoi(trauma);
        paciente.sintomasNeurologicos = stoi(sintomasNeurologicos);
        paciente.necesitaCirugia = stoi(necesitaCirugia);
        paciente.diasHospitalizado = stoi(diasHospitalizado);

        cola.push(paciente);

        cout << "ID: " << paciente.id << endl;
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "Edad: " << paciente.edad << endl;
        cout << "Temperatura: " << paciente.temperatura << endl;
        cout << "Presion arterial: " << paciente.presionArterial << endl;
        cout << "Dolor: " << paciente.dolor << endl;
        cout << "Tipo de dolor: " << paciente.tipoDolor << endl;
        cout << "Trauma: " << paciente.trauma << endl;
        cout << "Sintomas neurologicos: " << paciente.sintomasNeurologicos << endl;
        cout << "Requiere cirugia: " << paciente.necesitaCirugia << endl;
        cout << "Dias hospitalizacion: " << paciente.diasHospitalizado << endl;
        cout << "--------------------------" << endl;
    }

    archivo.close();
}
