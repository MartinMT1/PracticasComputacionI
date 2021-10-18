/*
*Author: Martín Morales Trejo
*martin.mo.tre@comunidad.unam.mx
*Oct 15, 2021
 Definición de las funciones miembro de la clase Punto2D. Este archivo contiene
 implementaciones de las funciones miembreo (atributos) cuyo prototipo está
 en Punto.h
*/

 //Para usar las definiciones descritas brevemente en la clase Puntos 2D
#include <iostream>
#include "Punto.h"
#define pi 3.1416 //Se define el valor de pi para las operaciones de rotación

using namespace std;


void Punto2D::SetPosicion(double X, double Y) {
    x = X;
    y = Y;
}

void Punto2D::Trasladar(float temp1, float temp2) {
    x = x + (temp1);
    y = y + (temp2);
    
}

void Punto2D::RotarRespectoAlOrigen(float temp1) {
    temp1 = temp1 * pi / 180;
    float x2  = x;
    x = (x * cos(temp1)) - (y * sin(temp1));
    y = (y * cos(temp1))+ (x2 * sin(temp1));
   
}

void Punto2D::Escalar(float temp1, float temp2) {
    x = x * temp1;
    y = y * temp2;

}

float Punto2D::GetX() const {
    return x;
}
float Punto2D::GetY() const {
    return y;
}