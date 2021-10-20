#include <iostream>
#include <array>

// Incluimos nuestro encabezado con la definici�n de la clase Punto2D
#include "CalculadoraDeElectronica.h"

using namespace std;

// Declaraci�n de funciones
//void PedirValores(float& x, float& y)

//Funciones para Ley de Ohm
char PedirOpcion();//Para seleccionar la operaci�n
char ElegirVariante();
char ElegirValoresConocidos();//Para definir los valores cococidos para aplicar la ley de ohm
char DefinirNResistencias();
void EstablecerValoresResistencias();

//Funciones para calcular valor de resistencia por sus bandas de color
char SeleccionarColor();

//Se definen variable globales para el c�lculo de la ley de Ohm
float R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0, R6 = 0;


//array<float, 6> EstablecerValoresResistencias(void); ---Agregar uso de array

int main()
{
    //Creamos un objeto de la clase OperacionesDeCalculadora
    OperacionesDeCalculadora miClase;
    

    //Variables de las operaciones con Ley de Ohm
    char NResis;
    char option;
    char Variante;
    char ValoresConocidosOhm;
    float Voltaje = 0;
    float Corriente = 0;
    float Resistencia = 0;

    //Variables del c�lfulo de resistencia por c�digo de colores
    int ValorResistencia = 0;
    int PrimerBanda = 0;
    int SegundaBanda = 0;
    int TercerBandaMultiplicadora = 0;
    char escala;
    string tolerancia;
  
	
        do {
            printf("Bienvenido a la calculadora de electr�nica :)\n Aqu� podr�s realizar operaciones para reforzar tus conociemitos en electr�nica\n");
            printf("Selecciona la operaci�n que deseas realizar\n");
            printf("1). C�lculo de circuitos con ley de Ohm\n");
            printf("2). Definir el valor de una resistencia por su c�digo de colores\n");
            printf("3). Definir el valor de la resistencia para un Diodo LED\n");
            printf("4). C�lculos con capacitores\n");
            printf("5). C�lculos con inductores\n");
            printf("6). SALIR\n\n");

            option = PedirOpcion();
            switch (option)
            {
                // Si operacion == '1' entonces realiza lo siguiente:

            case '1'://C�lculo de circuitos con ley de Ohm
                //Agregar do-while si se desea salir de la calculadora en cada operaci�n 
                    printf("Selecciona la operaci�n que deseas realizar\n");
                    printf("1). C�lculo de circuitos en serie\n");
                    printf("2). C�lculo de circuitos en paralelo\n\n");
                    /*FUNCION OPCIONAL: la funci�n scanf permite introducir cualquier combinaci�n de valores num�ricos, caracteres sueltos y cadenas de caracteres
                    a trav�s del teclado. En este caso el argumento es ("%d, &TipoCitcuito") -> %d imprime una variable int en formato decimal,
                    mientras que se toma una valor por referencia de Tipocircuito*/
                    //scanf("%d, &TipoCitcuito"); //Esperamos un valor decimal (%d) que se guardar� en la variable option (&TipoCitcuito)
                    
                    Variante = ElegirVariante();         
                    switch (Variante)
                    {
                    case '1': //Circuito en serie
                       
                        printf("Car�cteristicas de un circuiuto en serie:\n");   
                        printf("** La corriente es constante en todos los elementos pasivos\n");
                        printf("** Hay una ca�da de tensi�n en cada elemento\n");
                        printf("** La suma de las resistencias nos da la resistencia total del circuito\n");
                        printf("NOTA: Para este c�lculo requieres conocer el valor de 2 de las 3 variables (Voltaje, Corriente y Resistencias)\n\n");
                        printf("�Qu� valores conoces?\n");
                        printf("1). Voltaje y Corriente\n");
                        printf("2). Voltaje y Resistencia/s\n");
                        printf("3). Corriente y Resistencia/s\n\n");
                       
                        ValoresConocidosOhm = ElegirValoresConocidos();                     
                        switch (ValoresConocidosOhm)
                        {
                        case '1'://Voltaje y corriente
                            cout << "Introduce el valor del voltaje (en volts)\n";
                            cin >> Voltaje;
                            cout << "Introduce el valor de la Corriente (en amperes)\n";
                            cin >> Corriente;                           
                            //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                           //Para Realizar la Operaci�n
                            //Resistencia=0;
                            miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                            miClase.ResistenciaTotal(Voltaje, Corriente);

                                break;
                        case '2'://Voltaje y resistencias
                            cout << "Introduce el valor del voltaje (en volts)\n";
                            cin >> Voltaje; 
                            NResis = DefinirNResistencias(); 
                            Resistencia = R1 + R2 + R3 + R4 + R5 + R6;
                            //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                            //Para Realizar la Operaci�n
                            miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                            miClase.CorrienteTotal(Resistencia, Voltaje);
                            //Voltaje / (R1 + R2 + R3 + R4 + R5 + R6) << " Amperes\n\n\a";///Aqui se llama funci�n miembro);
                            break;

                        case '3': //Corriente y resistencias
                            cout << "Introduce el valor de la Corriente (en amperes)";
                            cin >> Corriente;                         
                            NResis = DefinirNResistencias();
                            Resistencia = R1 + R2 + R3 + R4 + R5 + R6;
                            //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                           //Para Realizar la Operaci�n
                            miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                            miClase.VoltajeTotal(Resistencia, Corriente);
                                break;

                        default:
                            cout << "Operacion no valida\n";
                            break;
                        }
                    
                        break;

                    case '2': //Circuito Paralelo

                        printf("Car�cteristicas de un circuiuto en Paralelo:\n");
                        printf("** La corriente es distinta en cada elemento pasivo conectado en paralelo\n");
                        printf("** El voltaje de alimentaci�n es el mismo en cada elemento\n");
                        printf("** La resistencia total se calcula por medio de la siguiente expresi�n:\n\n");
                        printf("                               1          \n");
                        printf("Resistencia Total = ----------------------\n");
                        printf("                       1     1         1  \n");
                        printf("                      --- + --- ... + --- \n");
                        printf("                       R1    R2        Rn \n\n");
                        printf("NOTA: Para este c�lculo requieres conocer el valor de 2 de las 3 variables (Voltaje, Corriente y Resistencias)\n\n");
                        printf("�Qu� valores conoces?\n");
                        printf("1). Voltaje y Corriente\n");
                        printf("2). Voltaje y Resistencia/s\n");
                        printf("3). Corriente y Resistencia/s\n\n");

                        ValoresConocidosOhm = ElegirValoresConocidos();
                        switch (ValoresConocidosOhm)
                        {
                        case '1'://Voltaje y corriente
                            cout << "Introduce el valor del voltaje (en volts)\n";
                            cin >> Voltaje;
                            cout << "Introduce el valor de la Corriente (en amperes)\n";
                            cin >> Corriente;
                           
                            //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                           //Para Realizar la Operaci�n
                            miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                            miClase.ResistenciaTotal(Voltaje, Corriente);
                            break;
                        case '2'://Voltaje y resistencias
                            cout << "Introduce el valor del voltaje (en volts)\n";
                            cin >> Voltaje;
                            NResis = DefinirNResistencias();
                            Resistencia = 1 / ((1 / R1) + (1 / R2) + (1 / R3) + (1 / R4) + (1 / R5) + (1 / R6));
                            //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                           //Para Realizar la Operaci�n
                            miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                            miClase.CorrienteTotal(Resistencia, Voltaje);
                            break;

                        case '3': //Corriente y resistencias
                            cout << "Introduce el valor de la Corriente (en amperes)";
                            cin >> Corriente;
                            NResis = DefinirNResistencias();
                            Resistencia = 1 / ((1 / R1) + (1 / R2) + (1 / R3) + (1 / R4) + (1 / R5) + (1 / R6));
                            //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                           //Establecemos valores a las variables de Voltaje, Corriente y Resistencia
                            miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                            //Para Realizar la Operaci�n
                            miClase.VoltajeTotal(Resistencia, Corriente);
                            break;

                        default:
                            cout << "Operacion no valida\n";
                            break;
                        }

                        break;

                    default:
                        cout << "Operacion no valida\n";
                        break;

                    }
                    printf("RESUMEN FINAL:\n\n");
                    cout << "**La Corriente Total es: " << miClase.ObtenerI() << " Amperes\a\n" << endl;
                    cout << "**La Resistencia Total es: " << miClase.ObtenerR() << " Ohms\n" << endl;
                    cout << "**El Voltaje Total es: " << miClase.ObtenerV() << " Volts\n" << endl;
            break;
                   

            case '2'://Definir el valor de una resistencia por su c�digo de colores\n");
                printf("Selecciona la operaci�n que deseas realizar\n");
                printf("1). Determinar el valor de una resistencia con 4 bandas.\n");
                printf("2). Determinar el valor de una resistencia con 5 bandas.\n\n");
                Variante = ElegirVariante();
                switch (Variante)
                {
                case '1': //resistencia con 4 bandas

                    printf("A continuaci�n podr�s conocer el valor de una resistencia mediante la interpretaci�n de sus bandas de colores:\n");
                    printf("NOTA: Para obtener un resultado correcto debes orientar tu resistencia de la siguiente manera: \n\n");
                    printf("** Localiza el extremo donde las bandas de colores se encuentren m�s juntas \n");
                    printf("** Una vez localizado, mant�n ese estremo a tu izquierda\n");
                    printf("** Por �ltimo es importante que identifiques los colores de izquierda a derecha\n\n");
                    printf("Para definir un color tendr�s que teclear la letra asociada que le corresponde:\n");
                    printf("**Negro = B\n**Caf� = N\n**Rojo = R\n**Naranja = O\n**Amarillo = Y\n**Verde = E\n**Azul = U\n");
                    printf(" **Violeta = V\n **Gris = G\n **Blanco = W\n **Dorado = L\n **Plata = S\n\n");

                     //Primer Banda
                    cout << "Presiona Enter si entendiste las instrucciones" << endl;
                    printf("�Cu�l es el color de la primer banda?\n\n");
                    char SeleccionarColor();

                    printf("�Cu�l es el color de la segunda banda?\n\n");
                    char SeleccionarColor();

                    printf("�Cu�l es el color de la tercer banda?\n\n");
                    char SeleccionarColor();

                    printf("�Cu�l es el color de la cuarta banda?\n\n");
                    char SeleccionarColor();


                    ValoresConocidosOhm = ElegirValoresConocidos();
                    switch (ValoresConocidosOhm)
                    {
                    case '1'://Voltaje y corriente
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        cout << "Introduce el valor de la Corriente (en amperes)\n";
                        cin >> Corriente;
                        //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operaci�n
                        //Resistencia=0;
                        miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                        miClase.ResistenciaTotal(Voltaje, Corriente);

                        break;
                    case '2'://Voltaje y resistencias
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        NResis = DefinirNResistencias();
                        Resistencia = R1 + R2 + R3 + R4 + R5 + R6;
                        //LLamamos una funci�n miembro de la clase mediante el objeto miclase
                        //Para Realizar la Operaci�n
                        miClase.EstablecerValoresVRI(Voltaje, Corriente, Resistencia);
                        miClase.CorrienteTotal(Resistencia, Voltaje);
                        //Voltaje / (R1 + R2 + R3 + R4 + R5 + R6) << " Amperes\n\n\a";///Aqui se llama funci�n miembro);
                        break;
                    default:
                        cout << "Operacion no valida\n";
                        break;
                    }

                    break;

                case '2': //resistencia con 5 bandas

                    break;
                    }

                 printf("RESUMEN FINAL:\n\n");
                 cout << "**La Corriente Total es: " << miClase.ObtenerI() << " Amperes\a\n" << endl;
                 cout << "**La Resistencia Total es: " << miClase.ObtenerR() << " Ohms\n" << endl;
                 cout << "**El Voltaje Total es: " << miClase.ObtenerV() << " Volts\n" << endl;
                 break;


                
            case '3'://Definir el valor de la resistencia para un Diodo LED

             
                break;
            case '4'://C�lculos con capacitores

                
                break;
            case '5': // C�lculos con inductores
     
                break;
            case '6': //SALIR
                break;
                // Si ninguno de los casos anteriores se cumpli�, entonces realiza lo siguiente
            default:
                cout << "Operacion no valida\n";
                break;
            }

               
        }
        while (option != 6);
        system("pause");
        return 0;
}
//DEFINICI�N DE FUNCIONES:


//LEY DE OHM

    // Solicita una operaci�n v�lida al usuario
    char PedirOpcion()
    {
        char option;
        do {
            cout << "Digita el n�mero de la operaci�n: ";
            cin >> option;
        } while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6' && option != '7' && option != '8');
        return option;
    }

    char ElegirVariante()
    {
        char Variante;
        do {
            cout << "Digita el n�mero de la operaci�n: ";
            cin >> Variante;
        } while (Variante != '1' && Variante != '2' );
        return Variante;
    }
   
    char ElegirValoresConocidos()
    {
        char ValoresConocidosOhm;
        do {
            cout << "Digita el n�mero de la operaci�n: ";
            cin >> ValoresConocidosOhm;
        } while (ValoresConocidosOhm != '1' && ValoresConocidosOhm != '2' && ValoresConocidosOhm != '3');
        return ValoresConocidosOhm;
    }

    char    DefinirNResistencias()
    {
        char NResis;
        do {
            printf("Introduce el valor de las resistencias (en ohms)\n");
            printf( "�Cu�ntas resistencias tiene tu circuito�?\n  Respuesta: ");
            cin >> NResis;
           
        } while (NResis != '1' && NResis != '2' && NResis != '3' && NResis != '4' && NResis != '5' && NResis != '6');
        if (NResis == '1') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
        }
        else if (NResis == '2') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
        }
        else if (NResis == '3') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
            cout << "Valor resistencia 3: ";
            cin >> R3;
        }
        else if (NResis == '4') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
            cout << "Valor resistencia 3: ";
            cin >> R3;
            cout << "Valor resistencia 4: ";
            cin >> R4;
        }
        else if (NResis == '5') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
            cout << "Valor resistencia 3: ";
            cin >> R3;
            cout << "Valor resistencia 4: ";
            cin >> R4;
            cout << "Valor resistencia 5: ";
            cin >> R5;
        }
        else if (NResis == '6') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
            cout << "Valor resistencia 3: ";
            cin >> R3;
            cout << "Valor resistencia 4: ";
            cin >> R4;
            cout << "Valor resistencia 5: ";
            cin >> R5;
            cout << "Valor resistencia 6: ";
            cin >> R6;
        }
        return NResis;
    }


    //C�LCULO DE RESISTENCIA POR C�DIGO DE COLORES

    char SeleccionarColor()
    {
        int Negro = 0;
        int Cafe = 1;
        int Rojo = 2;
        int Naranja = 3;
        int Amarillo = 4;
        int Verde = 5;
        int Azul = 6;
        int Violeta = 7;
        int Gris = 8;
        int Blanco = 9;
        int Dorado = 0;
        int Plata = 0;
        char color;

        cout << "Teclea el c�digo correspondiente:";
            cin >> color;
        
            if (color == 'B') {
                color = Negro;
        }
            else if (color == 'N') {
                color = Cafe;
            }
            else if (color == 'R') {
                color = Rojo;
            }
            else if (color == 'O') {
                color = Naranja;
            }
            else if (color == 'Y') {
                color = Amarillo;
            }
            else if (color == 'E') {
                color = Verde;
            }
            else if (color == 'U') {
                color = Azul;
            }
            else if (color == 'V') {
                color = Violeta;
            }
            else if (color == 'G') {
                color = Gris;
            }
            else if (color == 'W') {
                color = Blanco;
            }
            else if (color == 'L') {
                color = Dorado;
            }
            else if (color == 'S') {
                color = Plata;
            }

        return color;
    }

  

  /*  array<float, 6> EstablecerValoresResistencias() //La funcion LlenarArreglo consiste en el llenado de un arreglo con 3 posiciones
    {
        array<float, 6> Arreglo = { 0 }; //primeramente se inicializa el arreglo a llenar llamado "Arreglo"
        for (int i = 0; i < 6; i++) { //Posteriormente se hace una iteraci�n con la fucni�n for desde la posici�n i= 0 hasta LEN
            cout << "Valor Elemento [" << i << "]: "; // Se imprime en pantalla los valores que fue tomando i mientras se ejecut� la iteraci�n
            cin >> Arreglo[i];// Se guardan los valores en el Arreglo
        }
        return Arreglo;
    }


    //void EstablecerValoresResistencias();

   

	//Operaciones:
Ley de Ohm
	void OperacionesDeCalculadora::MostrarInfoLeyOhm() const

		cout << "La ley de Ohm establece la relaci�n entre el voltaje. la corriente y la resistencia de un\n" << "circuito electr�nico"
        */