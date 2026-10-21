#pragma once
#include <string>
#include "Paciente.h"
#include "Estructura/Queue.h"
using namespace std;

class LectorArchivo {
public:
    void leerPacientes(string nombreArchivo, Queue<Paciente>& cola);
};
