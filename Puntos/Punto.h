/*
*Author: Mart�n Morales Trejo
*martin.mo.tre@comunidad.unam.mx
*Oct 15, 2021
 Definici�n de la clase Punto2D. Este archivo representa la interf�z public de
 la clase Punto2D sin revelar las implementaciones de las funciones miembro, las
 cuales est�n definidas en Puntos.cpp
*/

#include <iostream>
#include <stdlib.h>
#ifndef PUNTO_2D
#define PUNTO_2D 


 //Definimos la clase Punto2D
class Punto2D {

	//Definimos los prototipos de funciones que tendr� la clase
public:

	void SetPosicion(double X, double Y); //Funci�n para darle el valor iniccial a X y Y
	void Trasladar(float temp1, float temp2);//va a trasladar el punto a otra coordenada 
	void RotarRespectoAlOrigen(float temp1); //Funci�n que rotar� un punto con respecto al origen
	void Escalar(float temp1, float temp2); //Funci�n que requiere 2 valores flotantes como escalares
	float GetX() const; //Para obtener el valor de x
	float GetY() const; //para obtener el valor de y
   //Definimos las "variables atributo" o los "datos miembros"
/*
Nota: Estas variablews se encuentran en una o m�s implementaciones, por lo que
establecerlas aqui genera que esta tome un valor diferecte (significativo) cada
que se llame alguna funci�n miembro que la incluya.
*/
private:

	float x = 0;
	float y = 0;

};

#endif //PUNTO_2D
