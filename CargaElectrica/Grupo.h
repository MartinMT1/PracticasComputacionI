/*
 * Author: Martín Morales Trejo
 * martin.mo.tre@comunidad.unam.mx
 * Sept 30, 2021
 */


#ifndef CARGAELECTRICA_GRUPO_H
#define CARGAELECTRICA_GRUPO_H

#include <string>
#include <iostream>
#include <array>
using namespace std;

class Grupo {

public:
    Grupo(string, float, int); //constructor con 3 argumentos
    Grupo(); //Constructor vacío

    //Métodos
    //En este caso omitimos el uso de funciones Set, ta que el constructor se encarga de eso
    int ObtenerCarga();
    float ObtenerPkr();

private:
    //Atributos
    string nombre;
    float pka;
    int carga;

};

#endif


