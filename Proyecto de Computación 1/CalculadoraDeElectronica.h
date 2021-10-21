/*
*Authors: Martín Morales Trejo and Gabriel Peytral Borja
*e-mail: martin.mo.tre@comunidad.unam.mx//Gabrielpeytral@comunidad.unam.mx
*Oct 18, 2021
 Definición de la clase OperacionesDeCalculadora. Este archivo representa la interfáz public de
 la clase "OperacionesDeCalculadora" sin revelar las implementaciones de las funciones miembro, las
 cuales están definidas en OperacionesDeCalculadora.cpp
*/

#include <iostream>
#include <stdlib.h>
#ifndef OPERACIONES_ELECTRONICA
#define OPERACIONES_ELECTRONICA


//Definimos la clase OperacionesDeCalculadora
class OperacionesDeCalculadora {

	//Definimos los prototipos de funciones que tendrá la clase
public:										
		//Operaciones:
	//Ley de Ohm
	void EstablecerValoresVRI(float v, float i, float r); //Función para darle el valor a las variables de VRI
	void ResistenciaTotal(float Voltaje, float Corriente);
	void VoltajeTotal(float Resistencia, float Corriente);
	void CorrienteTotal(float Resistencia, float Voltaje);
	float ObtenerV();
	float ObtenerR();
	float ObtenerI();

	//Valor de resistencias por código de colores
	void EstablecerValoresDeBanda(double primer, double segunda, double tercera); //Función para darle el valor a las variables
	void EstablecerValorTolerancia(std::string tolerancia);
	void EstablecerEscala(char escala);
	void ValorDeResistencia(double primer, double segunda, double tercera);
	int ObtenerValorResistencia();
	char ObtenerEscala();
	std::string ObtenerTolerancia();

	//Definir valor de resistenica para Diodo LED

	double ObtenerVoltajeResistencia();
	double ObtenerValorDeFuente();
	double ObtenerValorDeCorrienteDelCircuito();
	double ObtenerValorDeVoltajeLED();
	double ObtenerValorResistenciaSugerida();
	void EstablecerValorDeFuente(double fuente);
	void EstablecerValorDeCorrienteDelCircuito(double corrienteEsperada);
	void EstablecerVoltajeDiodo(double VoltajeDiodo);
	void CalculoVoltajeResistencia(double fuente, double VoltajeDiodo);
	void ResistenciaSugerida(double VoltajeResistencia, double corrienteEsperada);



	

//Definimos las "variables atributo" o los "datos miembros"
/*
Nota: Estas variablews se encuentran en una o más implementaciones, por lo que
establecerlas aqui genera que esta tome un valor diferecte (significativo) cada
que se llame alguna función miembro que la incluya.
*/
private:

	//Operaciones:
		//Ley de Ohm
		float V = 0;
		float R = 0;
		float I = 0;
		//Valor de resistencias por bandas de colores
		double ValorResistencia = 0;
		double PrimerBanda = 0;
		double SegundaBanda = 0;
		double TercerBandaMultiplicadora = 0;
		char Escala=0;
		std::string Tolerancia;

		//Definir valor de resistenica para Diodo LED
		double Fuente = 0;
		double CorrienteEsperada = 0;
		double VoltajeDiodo = 0;
		double VoltajeResistencia=0;
		double ResistenciaSugeridaLED=0;
};

#endif //OPERACIONES_ELECTRONICA

