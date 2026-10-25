#pragma once
#include <string>
#include "Estructura/AVL.h"
using namespace std;


class Servicio {
private:
    string nombre;
    AVL arbol;

public:
    Servicio(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() const {
        return nombre;
    }

    
    AVL& getArbol() {
        return arbol;
    }
};