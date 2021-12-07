/*
 * Author: Martín Morales Trejo
 * martin.mo.tre@comunidad.unam.mx
 * Sept 30, 2021
 */
#include <iostream>
#include <array>
#include "Grupo.h"

//Descripción de métodos

Grupo::Grupo() { //inicializamos los atributos por medio del constructor
    nombre = " ";
    pka = 0;
    carga = 0;
}

Grupo::Grupo(string nombreGrupo, float pkGrupo, int cargaGrupo) { //Asignamos valores a los atributos por medio de los argumentos provenientes del código main
    nombre = nombreGrupo;
    pka = pkGrupo;
    carga = cargaGrupo;
}

//En este caso omitimos el uso de funciones Set, ta que el constructor se encarga de eso
int Grupo::ObtenerCarga() {
    return carga;
}

float Grupo::ObtenerPkr() {
    return pka;
}