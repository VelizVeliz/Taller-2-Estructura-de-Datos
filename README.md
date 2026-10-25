Taller 2 - Estructura de Datos

Integrantes
Maximiliano Castillo
Vicente Veliz
Christian Mardones

Descripción
Este proyecto corresponde al desarrollo del Taller N°2 de la asignatura Estructura de Datos.

El sistema permite gestionar pacientes de un hospital mediante la utilización de estructuras de datos dinámicas. Los pacientes son cargados desde un archivo de texto, clasificados mediante un árbol de decisión y almacenados en árboles AVL según el servicio médico correspondiente.

Estructuras Implementadas
Árbol de Decisión
Se utiliza para clasificar a los pacientes según distintos criterios médicos, los cuales son:

Edad
Trauma
Necesidad de cirugía
Síntomas neurológicos
Temperatura corporal
Presión arterial
Días de hospitalización


Árbol AVL
Se implementa un árbol AVL para cada servicio médico con el objetivo de almacenar los pacientes de manera ordenada y balanceada.

Operaciones implementadas:

Inserción
Búsqueda
Eliminación
Balanceo automático
Rotaciones simples
Rotaciones dobles
Servicios Médicos


Los pacientes pueden ser clasificados en:

Pediatría
Cirugía
Traumatología
Neurología
Cardiología
Urgencias
Hospitalización
Medicina General


/Estructura
    NodoDecision.h
    ArbolDecision.h
    ArbolDecision.cpp
    NodoAVL.h
    AVL.h
    AVL.cpp


Funcionalidades
Lectura de pacientes desde archivo.
Clasificación automática mediante árbol de decisión.
Inserción de pacientes en árboles AVL.
Búsqueda de pacientes por ID.
Eliminación de pacientes.
Balanceo automático de árboles AVL.
Gestión eficiente de la información hospitalaria.
