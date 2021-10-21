/*
*Authors: Martín Morales Trejo and Gabriel Peytral Borja
*e-mail: martin.mo.tre@comunidad.unam.mx//Gabrielpeytral@comunidad.unam.mx
*Oct 18, 2021
 Definición de las funciones miembro de la clase OperacionesDeCalculadora. Este archivo contiene
 implementaciones de las funciones miembreo (atributos) cuyo prototipo está
 en CalculadoraDeElectronica.h
*/

//Para usar las definiciones descritas brevemente en la clase Puntos 2D
#include <iostream>
#include "CalculadoraDeElectronica.h"

using namespace std;

//Definición de funciones para Ley de Ohm
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
//Definición de funciones para el cálculo de resistencias por código de colores

void OperacionesDeCalculadora::EstablecerValoresDeBanda(double primer, double segunda, double tercera) {//Función para darle el valor a las variables
	PrimerBanda = primer;
	SegundaBanda = segunda;
	TercerBandaMultiplicadora = tercera;	
}
void OperacionesDeCalculadora::EstablecerValorTolerancia(string tolerancia) {
	Tolerancia = tolerancia;
}
void OperacionesDeCalculadora::EstablecerEscala(char escalaOhms) {
	Escala = escalaOhms;
}
void OperacionesDeCalculadora::ValorDeResistencia(double primer, double segunda, double tercera){
	ValorResistencia = ((10 * primer + segunda) * tercera);
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
double OperacionesDeCalculadora::ObtenerVoltajeResistencia() {
	return VoltajeResistencia;
}

double OperacionesDeCalculadora::ObtenerValorDeFuente() {
	return Fuente;
}
double OperacionesDeCalculadora::ObtenerValorDeCorrienteDelCircuito() {
	return CorrienteEsperada;
}
double OperacionesDeCalculadora::ObtenerValorDeVoltajeLED() {
	return VoltajeDiodo;
}
double OperacionesDeCalculadora::ObtenerValorResistenciaSugerida() {
	return ResistenciaSugeridaLED;
}
void OperacionesDeCalculadora::EstablecerValorDeFuente(double fuente) {
	Fuente = fuente;
}

void OperacionesDeCalculadora::EstablecerValorDeCorrienteDelCircuito(double corrienteEsperada) {
	CorrienteEsperada = corrienteEsperada;
}
void OperacionesDeCalculadora::EstablecerVoltajeDiodo(double voltajeDiodo) {
	VoltajeDiodo = voltajeDiodo;
}
void OperacionesDeCalculadora::CalculoVoltajeResistencia(double fuente, double voltajeDiodo) {
	VoltajeResistencia = (fuente-voltajeDiodo);
}

void OperacionesDeCalculadora::ResistenciaSugerida(double VoltajeResistencia, double corrienteEsperada) {
	ResistenciaSugeridaLED = (VoltajeResistencia / corrienteEsperada);
}
	