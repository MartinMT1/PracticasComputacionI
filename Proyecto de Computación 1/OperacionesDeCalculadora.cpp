/*
*Authors: Martín Morales Trejo and Gabriel Peytral Borja
*e-mail: martin.mo.tre@comunidad.unam.mx//Gabrielpeytral@comunidad.unam.mx
*Oct 18, 2021
 Definición de las funciones miembro de la clase OperacionesDeCalculadora. Este archivo contiene
 implementaciones de las funciones miembreo (atributos) cuyo prototipo está
 en CalculadoraDeElectronica.h
*/

//Para usar las definiciones descritas brevemente en la clase CalculadoraDeElectronica
#include <iostream>
#include "CalculadoraDeElectronica.h"

using namespace std;

//Definición de funciones para Ley de Ohm

void OperacionesDeCalculadora::EstablecerValoresVRI(float Voltaje, float Resistencia,float Corriente) {
	V = Voltaje;
	R = Resistencia;
	I = Corriente;
} 
void OperacionesDeCalculadora::ResistenciaTotal(float V, float I) {
	R = V / I;
}
void OperacionesDeCalculadora::VoltajeTotal(float R, float I) {
	V = R * I;
		}
void OperacionesDeCalculadora::CorrienteTotal(float R, float V) {
	I = V / R;
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
double OperacionesDeCalculadora::ObtenerValorResistencia() {
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
	

//Calculadora de Capacitores
void OperacionesDeCalculadora::EstablecerCapacitanciaTotal(double capacitancia) {
	Capacitancia = capacitancia;
}
void OperacionesDeCalculadora::EstablecerValoresVCCe(float Voltaje, double capacitancia, double cargaElectrica) {
	V = Voltaje;
	Capacitancia = capacitancia;
	CargaElectrica = cargaElectrica;
}
void OperacionesDeCalculadora::CargaTotal(float V, double Capacitancia) {
	CargaElectrica = Capacitancia * V;
}
void OperacionesDeCalculadora::CapacitanciaEnCircuito(double CargaElectrica,float V) {
	Capacitancia = CargaElectrica / V;
}
void OperacionesDeCalculadora::VoltajeEnCapacitores(double Capacitancia,double CargaElectrica) {
	V= CargaElectrica / Capacitancia;
}
double OperacionesDeCalculadora::ObtenerCargaElectrica() {
	return CargaElectrica;
}
void OperacionesDeCalculadora::EstablecerCyR(double capacitancia, float Resistencia) {
	Capacitancia=capacitancia;
	R = Resistencia;
}
double OperacionesDeCalculadora::ObtenerCapacitancia() {
	return Capacitancia;
	}
void OperacionesDeCalculadora::CalculoTiempo() {
	TiempoDeCarga = (Capacitancia) * (R);
	}
double OperacionesDeCalculadora::ObtenerTiempoCarga() {
	return TiempoDeCarga;
	}

//Cálculos con Inductores
void OperacionesDeCalculadora::EstablecerInductanciaTotal(double inductancia) {
	Inductancia = inductancia;
}
double OperacionesDeCalculadora::ObtenerInductancia() {
	return Inductancia;
}


