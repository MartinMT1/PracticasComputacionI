/*
*Authors: Mart�n Morales Trejo and Gabriel Peytral Borja
*e-mail: martin.mo.tre@comunidad.unam.mx
*Oct 18, 2021
 Definici�n de las funciones miembro de la clase OperacionesDeCalculadora. Este archivo contiene
 implementaciones de las funciones miembreo (atributos) cuyo prototipo est�
 en CalculadoraDeElectronica.h
*/

//Para usar las definiciones descritas brevemente en la clase Puntos 2D
#include <iostream>
#include "CalculadoraDeElectronica.h"

using namespace std;

//Definici�n de funciones para Ley de Ohm
void OperacionesDeCalculadora::EstablecerValoresVRI(float v, float i,float r) {
	V = v;
	R = r;
	I = i;
}
void OperacionesDeCalculadora::ResistenciaTotal(float Voltaje, float Corriente) {
	R = Voltaje / Corriente;
}
void OperacionesDeCalculadora::VoltajeTotal(float Resistencia, float Corriente) {
	V = Resistencia * Corriente;
		}
void OperacionesDeCalculadora::CorrienteTotal(float Resistencia, float Voltaje) {
	I = Voltaje / Resistencia;
		}
	float OperacionesDeCalculadora::ObtenerV() {
	return V;
}
float OperacionesDeCalculadora::ObtenerR() {
	return R;
		}
float OperacionesDeCalculadora::ObtenerI() {
	return I;
		}
//Definici�n de funciones para el c�lculo de resistencias por c�digo de colores

void OperacionesDeCalculadora::EstablecerValoresDeBanda(int primer, int segunda, int tercera) {//Funci�n para darle el valor a las variables
	PrimerBanda = primer;
	SegundaBanda = segunda;
	TercerBandaMultiplicadora = tercera;	
}
void OperacionesDeCalculadora::EstablecerValorTolerancia(string tolerancia) {
	Tolerancia = tolerancia;
}
void OperacionesDeCalculadora::EstablecerEscala(char escala) {
	Escala = escala;
}
void OperacionesDeCalculadora::ValorDeResistencia(int primer, int segunda, int tercera){
	ValorResistencia = (10 * primer + segunda) * tercera;
}
int OperacionesDeCalculadora::ObtenerValorResistencia() {
	return ValorResistencia;
}
char OperacionesDeCalculadora::ObtenerEscala() {
	return Escala;
}
string OperacionesDeCalculadora::ObtenerTolerancia() {
	return Tolerancia;
}

		//Definir valor de resistenica para Diodo LED

		//C�lculos con capacitores

		//C�lculos con inductores

		

