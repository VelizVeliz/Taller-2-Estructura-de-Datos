#pragma once
#include <string>
using namespace std;

struct Paciente {
    string id;
    string nombre;
    int edad;
    double temperatura;
    int presionArterial;
    int dolor;
    string tipoDolor;
    int trauma;
    int sintomasNeurologicos;
    int necesitaCirugia;
    int diasHospitalizado;
};
