/*
*Authors: Martín Morales Trejo and Gabriel Peytral Borja
*e-mail: martin.mo.tre@comunidad.unam.mx
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
	void EstablecerValoresDeBanda(int primer, int segunda, int tercera); //Función para darle el valor a las variables
	void EstablecerValorTolerancia(std::string tolerancia);
	void EstablecerEscala(char escala);
	void ValorDeResistencia(int primer, int segunda, int tercera);
	int ObtenerValorResistencia();
	char ObtenerEscala();
	std::string ObtenerTolerancia();


	//Definir valor de resistenica para Diodo LED

	//Cálculos con capacitores

	//Cálculos con inductores


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
		int ValorResistencia = 0;
		int PrimerBanda = 0;
		int SegundaBanda = 0;
		int TercerBandaMultiplicadora = 0;
		char Escala;
		std::string Tolerancia;

		//Definir valor de resistenica para Diodo LED

		//Cálculos con capacitores

		//Cálculos con inductores

		//Ley de kirchoff

		//Amplicadores operacionales
};

#endif //PUNTO_2D

