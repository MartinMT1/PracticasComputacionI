/*
*Authors: Martín Morales Trejo and Gabriel Peytral Borja
*e-mail: martin.mo.tre@comunidad.unam.mx//Gabrielpeytral@comunidad.unam.mx
*Dic 05, 2021
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
	~OperacionesDeCalculadora(); //destructor

	void EstablecerValoresVRI(float Voltaje, float Resistencia, float Corriente); //Función para darle el valor a las variables de VRI
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
	double ObtenerValorResistencia();
	char ObtenerEscala();
	std::string ObtenerTolerancia();
	//Con 5 bandas
	void EstablecerValoresDeBanda(double primer, double segunda, double tercera, double cuarta); //Función para darle el valor a las variables
	void ValorDeResistencia(double primer, double segunda, double tercera, double cuarta);


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


	//Cálculos con Capacitores
	void EstablecerValoresVCCe(float Voltaje, double capacitancia, double cargaElectrica);
	void CargaTotal(float Voltaje, double capacitancia);
	void CapacitanciaEnCircuito(double cargaElectrica, float Voltaje);
	void VoltajeEnCapacitores(double capacitancia, double cargaElectrica);
	double ObtenerCargaElectrica();
	double ObtenerCapacitancia();
	void CalculoTiempo();
	void EstablecerCyR(double capacitancia, float Resistencica);
	double ObtenerTiempoCarga();
	void EstablecerCapacitanciaTotal(double capacitancia);

	//Cálculos con Inductores
	void EstablecerInductanciaTotal(double inductancia);
	double ObtenerInductancia();



	//Definimos las "variables atributo" o los "datos miembros"
	/*
	Nota: Estas variables se encuentran en una o más implementaciones, por lo que
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
	double TercerBanda = 0;
	double CuartaBanda = 0;
	char Escala = 0;
	std::string Tolerancia;

	//Definir valor de resistenica para Diodo LED
	double Fuente = 0;
	double CorrienteEsperada = 0;
	double VoltajeDiodo = 0;
	double VoltajeResistencia = 0;
	double ResistenciaSugeridaLED = 0;

	//Calculadora de tiempo de carga de capacitor
	double CargaElectrica = 0;
	double Capacitancia=0;
	double TiempoDeCarga = 0;

	//Calculos con inductores
	double Inductancia = 0;

};

#endif //OPERACIONES_ELECTRONICA

