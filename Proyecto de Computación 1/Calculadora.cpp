#include <iostream>
#include <stdlib.h>

// Incluimos nuestro encabezado con la definición de la clase CalculadoraDeElectronica
#include "CalculadoraDeElectronica.h"

using namespace std;

// Declaración de funciones
// 
//Funciones para Ley de Ohm
char PedirOpcion();//Para seleccionar la operación
char ElegirVariante();
char ElegirValoresConocidos();//Para definir los valores cococidos para aplicar la ley de ohm
char DefinirNResistencias();
void EstablecerValoresResistencias();

//Funciones para calcular valor de resistencia por sus bandas de color
double SeleccionarColor();
double VoltajeUmbral();

//Se definen variables globales para el cálculo de la ley de Ohm
float R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0, R6 = 0;
float Rserie = 0;
float Rparalelo = 0;

//Se definen variables globales 
double color=0;
double multiplicador = 0;
char escala;
string tol;
double codigo = 0;
double voltajeUmbral = 0;


int main()
{
    //Creamos un objeto de la clase OperacionesDeCalculadora
    OperacionesDeCalculadora miClase;
    

    //Variables de las operaciones con Ley de Ohm
    char NResis;
    char option;
    char Variante;
    char ValoresConocidosOhm;
    float Voltaje = 1;
    float Corriente = 1;
    float Resistencia=1;


    //Variables del cálfulo de resistencia por código de colores
    double ValorResistencia = 0;
    double PrimerBanda = 0;
    double SegundaBanda = 0;
    double TercerBandaMultiplicadora = 0;
    char escalaOhms=0;
    string tolerancia;
    char continuar;
    float omitir=0;
    
    //Calculo resoistencia para diodo

    double fuente = 0;
    double corrienteEsperada = 0;
    double voltajeDiodo = 0;

  
	
        do {
            printf("\n\n           Bienvenido a la calculadora de electrónica :)\n\nAquí podrás realizar operaciones para reforzar tus conociemitos en electrónica\n");
            printf("Selecciona la operación que deseas realizar\n\n");
            printf("1). Cálculo de circuitos con ley de Ohm\n");
            printf("2). Definir el valor de una resistencia por su código de colores\n");
            printf("3). Definir el valor de la resistencia para un Diodo LED\n");
            printf("4). SALIR\n\n");

            option = PedirOpcion();
            switch (option)
            {
                // Si operacion == '1' entonces realiza lo siguiente:

            case '1'://Cálculo de circuitos con ley de Ohm
                //Agregar do-while si se desea salir de la calculadora en cada operación 
                printf("Selecciona la operación que deseas realizar\n");
                printf("1). Cálculo de circuitos en serie\n");
                printf("2). Cálculo de circuitos en paralelo\n\n");
                /*FUNCION OPCIONAL: la función scanf permite introducir cualquier combinación de valores numéricos, caracteres sueltos y cadenas de caracteres
                a través del teclado. En este caso el argumento es ("%d, &TipoCitcuito") -> %d imprime una variable int en formato decimal,
                mientras que se toma una valor por referencia de Tipocircuito*/
                //scanf("%d, &TipoCitcuito"); //Esperamos un valor decimal (%d) que se guardará en la variable option (&TipoCitcuito)

                Variante = ElegirVariante();
                switch (Variante)
                {
                case '1': //Circuito en serie

                    printf("Carácteristicas de un circuiuto en serie:\n");
                    printf("** La corriente es constante en todos los elementos pasivos\n");
                    printf("** Hay una caída de tensión en cada elemento\n");
                    printf("** La suma de las resistencias nos da la resistencia total del circuito\n");
                    printf("NOTA: Para este cálculo requieres conocer el valor de 2 de las 3 variables (Voltaje, Corriente y Resistencias)\n\n");
                    printf("¿Qué valores conoces?\n");
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
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje,Resistencia, Corriente);
                        miClase.ResistenciaTotal(Voltaje, Corriente);

                        break;
                    case '2'://Voltaje y resistencias
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        NResis = DefinirNResistencias();
                        Resistencia = Rserie;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                        //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.CorrienteTotal(miClase.ObtenerR(), miClase.ObtenerV());
                        break;

                    case '3': //Corriente y resistencias
                        cout << "Introduce el valor de la Corriente (en amperes)";
                        cin >> Corriente;
                        NResis = DefinirNResistencias();
                        Resistencia = Rserie;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.VoltajeTotal(Resistencia, Corriente);
                        break;

                    default:
                        cout << "Operacion no valida\n";
                        break;
                    }

                    break;

                case '2': //Circuito Paralelo

                    printf("Carácteristicas de un circuiuto en Paralelo:\n");
                    printf("** La corriente es distinta en cada elemento pasivo conectado en paralelo\n");
                    printf("** El voltaje de alimentación es el mismo en cada elemento\n");
                    printf("** La resistencia total se calcula por medio de la siguiente expresión:\n\n");
                    printf("                               1          \n");
                    printf("Resistencia Total = ----------------------\n");
                    printf("                       1     1         1  \n");
                    printf("                      --- + --- ... + --- \n");
                    printf("                       R1    R2        Rn \n\n");
                    printf("NOTA: Para este cálculo requieres conocer el valor de 2 de las 3 variables (Voltaje, Corriente y Resistencias)\n\n");
                    printf("¿Qué valores conoces?\n");
                    printf("1). Voltaje y Corriente\n");
                    printf("2). Voltaje y Resistencias\n");
                    printf("3). Corriente y Resistencias\n\n");

                    ValoresConocidosOhm = ElegirValoresConocidos();
                    switch (ValoresConocidosOhm)
                    {
                    case '1'://Voltaje y corriente
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        cout << "Introduce el valor de la Corriente (en amperes)\n";
                        cin >> Corriente;

                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.ResistenciaTotal(miClase.ObtenerV(), miClase.ObtenerI());

                        break;

                    case '2'://Voltaje y resistencias
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        NResis = DefinirNResistencias();
                        Resistencia = Rparalelo; 
                        omitir = 1;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.CorrienteTotal(miClase.ObtenerR(), miClase.ObtenerV());

                        break;

                    case '3': //Corriente y resistencias
                        cout << "Introduce el valor de la Corriente (en amperes)";
                        cin >> Corriente;
                        NResis = DefinirNResistencias();
                        Resistencia = Rparalelo; 
                        omitir = 1;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Establecemos valores a las variables de Voltaje, Corriente y Resistencia
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        //Para Realizar la Operación
                        miClase.VoltajeTotal(miClase.ObtenerR(), miClase.ObtenerI());

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
                printf("\nRESUMEN FINAL:\n\a");
                

                 
                if ((Rparalelo == R1)&&(omitir==1)) {
                    printf("** Seleccionaste que cuentas con una sola resistencia en tu circuito paralelo.\n\a");
                    printf("Recuerda que si solo tienes una resistencia en tu circuito, su configuración es equivalente a un circuto serie\n");
                    printf("SOLUCIÓN: Selecciona la opción para calcular circuitos en serie e introduce el valor de tu única resistencia\n\n");

                    printf("Reinicia la calculadora y vulve a intentarlo :)\n\n\n\n");
                    exit(0);

                }
                             
                else if((Resistencia == 0) || (Voltaje == 0) || (Corriente == 0)) {
                    printf("El valor de una variable introducida NO ES VÁLIDO, esto pasa cuando:\n\n\a");
                    printf("** Has proporcionado un valor 0 a alguna de las variables de Voltaje, Corriente o Resistencia\n");
                    printf("Recuerda que para los cálculos con ley de ohm requieres los valores de 2 variables que sean disferentes a 0\n");
                    printf("SOLUCIÓN: Selecciona la opción para cálculos con ley de ohm y en el apartado de ´variables con las que cuentas´ \n");
                    printf("Digita valores válidos diferentes a 0 \n\n\n\n");

                    printf("Reinicia la calculadora y vulve a intentarlo :)\n\n\n\n");
                    exit(0);

                }
                else{
                    cout << "**La Corriente Total es: " << miClase.ObtenerI() << " Amperes\n" << endl;
                    cout << "**La Resistencia Total es: " << miClase.ObtenerR() << " Ohms\n" << endl;
                    cout << "**El Voltaje Total es: " << miClase.ObtenerV() << " Volts\n\n\n\n" << endl;
                }
                break;


            case '2'://Definir el valor de una resistencia por su código de colores\n");
                printf("Selecciona la operación\n\n");
                printf("1). Calculadora de resistencia con 4 bandas.\n\n");
                printf("2). SALIR.\n\n");

                Variante = ElegirVariante();
                switch (Variante)
                {
                case '1': //resistencia con 4 bandas

                    printf("A continuación podrás conocer el valor de una resistencia mediante la interpretación de sus bandas de colores:\n");
                    printf("NOTA: Para obtener un resultado correcto debes orientar tu resistencia de la siguiente manera: \n\n");
                    printf("** Localiza el extremo donde las bandas de colores se encuentren más juntas \n");
                    printf("** Una vez localizado, mantén ese estremo a tu izquierda\n");
                    printf("** Por último es importante que identifiques los colores de izquierda a derecha\n\n");
                    printf("Para definir un color tendrás que introducir el número asociado que le corresponde:\n");
                    printf("**Negro = 0\n**Café = 1\n**Rojo = 2\n**Naranja = 3\n**Amarillo = 4\n**Verde = 5\n**Azul = 6\n");
                    printf("**Violeta = 7\n**Gris = 8\n**Blanco = 9\n**Dorado = 10\n**Plata = 11\n");

                    //Primer Banda
                    cout << "Para iniciar introduce cualquier tecla y presiona Enter" << endl;
                    cin >> continuar;

                    cout << "Primer Banda: " << endl;
                    color = SeleccionarColor();
                    PrimerBanda = color;

                    cout << "Segunda Banda: " << endl;
                    color = SeleccionarColor();
                    SegundaBanda = color;

                    cout << "Tercer Banda: " << endl;
                    color = SeleccionarColor();
                    escalaOhms = escala;
                    TercerBandaMultiplicadora = multiplicador;
                    /////////////
                    miClase.EstablecerEscala(escalaOhms);
                    miClase.EstablecerValoresDeBanda(PrimerBanda, SegundaBanda, TercerBandaMultiplicadora);
                    miClase.ValorDeResistencia(PrimerBanda, SegundaBanda, TercerBandaMultiplicadora);
                    /////////////
                    cout << "Cuarta Banda: " << endl;
                    color = SeleccionarColor();
                    tolerancia = tol;///////////

                    /////////////
                    miClase.EstablecerValorTolerancia(tolerancia);
                    ////////////
                    break;
                case '2':
                    exit(0);
                    break;///SALIDA
                }

                printf("\n\nRESUMEN FINAL:\n\a");

                if ((miClase.ObtenerValorResistencia() == 0)) {
                    cout << "La Resistencia no existe" << endl;
                }
                else {
                    cout << "**El valor de la Resistencia es: " << miClase.ObtenerValorResistencia() << " " << miClase.ObtenerEscala() << "Ohms\a" << endl;
                    cout << "  Con una toletancia de: " << miClase.ObtenerTolerancia() << "\a\n\n\n\n" << endl;
                }
                break;
                
            case '3'://Definir el valor de la resistencia para un Diodo LED
                printf("\nA continuación podrás calcular el valor de la resistencia necesario para que un Diodo LED opere correctamente\n");
                printf("Para lo anterior necesitarás introducir el valor de tu fuente de alimentación, la corriente esperada y el color de tu LED\n");
                 
                cout << "Introduce el valor de tu fuente de alimentación (en volts):\n";
                cin >> fuente;
                miClase.EstablecerValorDeFuente(fuente);

                cout<< "Introduce el valor de la corriente esperada (en amperes):\n";
                cin >> corrienteEsperada;
                miClase.EstablecerValorDeCorrienteDelCircuito(corrienteEsperada);

                cout << "Introduce el color de tu LED:\n";
                cout << "Considera el siguiente código de colores:\n" << endl;
                printf("**Rojo = 0\n**Amarillo = 1\n**Naranja = 2\n**Verde = 3\n**Azul = 4\n**Blanco = 5 \n\n");
                codigo = VoltajeUmbral();
                voltajeDiodo = voltajeUmbral;

                miClase.EstablecerVoltajeDiodo(voltajeDiodo);
                ///
                miClase.CalculoVoltajeResistencia(fuente, voltajeDiodo);
                miClase.ResistenciaSugerida(miClase.ObtenerVoltajeResistencia(), corrienteEsperada);
                ///
                printf("\n\nRESULTADO:\n\a");
                cout << "El valor de la resistencia sugerida es: " << miClase.ObtenerValorResistenciaSugerida() << " " << "Ohms\n\n\n\n" << endl;
              
                break;

            case '4': //SALIR
                exit(0);
                break;
                // Si ninguno de los casos anteriores se cumplió, entonces realiza lo siguiente
            default:
                cout << "Operacion no valida\n";
                break;
            }

               
        }
        while (option != 4);
   
    return 0;
}


//DEFINICIÓN DE FUNCIONES:

//LEY DE OHM

    // Solicita una operación válida al usuario
    char PedirOpcion()
    {
        char option;
        do {
            cout << "Digita el número de la operación: ";
            cin >> option;
        } while (option != '1' && option != '2' && option != '3' && option != '4');
        return option;
    }

    char ElegirVariante()
    {
        char Variante;
        do {
            cout << "Digita el número de la operación: ";
            cin >> Variante;
        } while (Variante != '1' && Variante != '2');
        return Variante;
    }
   
    char ElegirValoresConocidos()
    {
        char ValoresConocidosOhm;
        do {
            cout << "Digita el número de la operación: ";
            cin >> ValoresConocidosOhm;
        } while (ValoresConocidosOhm != '1' && ValoresConocidosOhm != '2' && ValoresConocidosOhm != '3');
        return ValoresConocidosOhm;
    }

    char    DefinirNResistencias()
    {
        char NResis;
       
        do {
            printf("Introduce el valor de las resistencias (en ohms)\n");
            printf("¿Cuántas resistencias tiene tu circuito¨?\n  Respuesta: ");
            cin >> NResis;

        } while (NResis != '1' && NResis != '2' && NResis != '3' && NResis != '4' && NResis != '5' && NResis != '6');

        if (NResis == '1') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            Rparalelo = R1;
            Rserie = R1;

        }
        else if (NResis == '2') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
            Rparalelo = 1 / ((1 / R1) + (1 / R2));
            Rserie = R1 + R2;
        }
        else if (NResis == '3') {
            cout << "Valor resistencia 1: ";
            cin >> R1;
            cout << "Valor resistencia 2: ";
            cin >> R2;
            cout << "Valor resistencia 3: ";
            cin >> R3;
            Rparalelo = 1 / ((1 / R1) + (1 / R2) + (1 / R3));
            Rserie = R1 + R2 + R3;

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
            Rparalelo = 1 / ((1 / R1) + (1 / R2) + (1 / R3) + (1 / R4));
            Rserie = R1 + R2 + R3 + R4;

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
            Rparalelo = 1 / ((1 / R1) + (1 / R2) + (1 / R3) + (1 / R4) + (1 / R5) );
            Rserie = R1 + R2 + R3 + R4 + R5;

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
            Rparalelo = 1 / ((1 / R1) + (1 / R2) + (1 / R3) + (1 / R4) + (1 / R5) + (1 / R6));
            Rserie = R1 + R2 + R3 + R4 + R5 + R6;

        }
        return NResis;
    }

//CÁLCULO DE RESISTENCIA POR CÓDIGO DE COLORES

    double SeleccionarColor()

    {
        double Negro = 0;
        double Cafe = 1;
        double Rojo = 2;
        double Naranja = 3;
        double Amarillo = 4;
        double Verde = 5;
        double Azul = 6;
        double Violeta = 7;
        double Gris = 8;
        double Blanco = 9;
        double Dorado = 0;
        double Plata = 0;
        char kilos = 'K';
        char megas = 'M';
        char NA = ' ';
        double m1 = 0.01;
        double m2 = 0.1;
        double m3 = 1;
        double m4 = 10;
        double m5 = 100;    

        do {
            cout << "¿Cuál es el color de la banda?\n";
            cin >> color;
        } while (color != 0 && color != 1 && color != 2 && color != 3 && color != 4 && color != 5 && color != 6 && color != 7 && color != 8 && color != 9 && color != 10 && color != 11);
        
            if (color == 0) {
                color = Negro;
                multiplicador = m3;
                tol = "No Aplica";
                escala = NA;
        }
            else if (color == 1) {
                color = Cafe;
                multiplicador = m4;
                tol = "1% (F)";
                escala = NA;
            }
            else if (color == 2) {
                color = Rojo;
                multiplicador = m5;
                tol = "±2% (G)";
                escala = NA;
            }
            else if (color == 3) {
                color = Naranja;
                multiplicador=m3;
                escala = kilos;
                tol = "No Aplica";
            }
            else if (color == 4) {
                color = Amarillo;
                multiplicador = m4;
                escala = kilos;
                tol = "No Aplica";
            }
            else if (color == 5) {
                color = Verde;
                multiplicador = m5;
                escala = kilos;
                tol = "±5% (D)";
            }
            else if (color == 6) {
                color = Azul;
                multiplicador = m3;
                escala = megas;
                tol = "±0.25% (C)";
            }
            else if (color == 7) {
                color = Violeta;
                multiplicador = m4;
                escala = megas;
                tol = "±0.10% (B)";
            }
            else if (color == 8) {
                color = Gris;
                multiplicador = 0;
                tol = "±0.05%";
                escala = NA;
            }
            else if (color == 9) {
                color = Blanco;
                multiplicador = 0;
                tol = "No Aplica";
                escala = NA;
            }
            else if (color == 10) {
                color = Dorado;
                multiplicador = m2;
                tol = "±5%";
                escala = NA;
            }
            else if (color == 11) {
                color = Plata;
                multiplicador = m3;
                tol = "±10%";
                escala = NA;
            }

        return color;
    }

    //DIODO LED

    double VoltajeUmbral()
    {
    do {
        cout << "¿Cuál es el color del LED?\n";
        cin >> codigo;
    } while (codigo != 0 && codigo != 1 && codigo != 2 && codigo != 3 && codigo != 4 && codigo != 5);

    if (codigo == 0) {
        voltajeUmbral = 1.9;     
    }
    else if (codigo == 1) {
        voltajeUmbral = 1.7;
    }
    else if (codigo == 2) {
        voltajeUmbral = 2.4;
    }
    else if (codigo == 3) {
        voltajeUmbral = 2.4;
    }
    else if (codigo == 4) {
        voltajeUmbral = 3.4;
    }
    else if (codigo == 5) {
        voltajeUmbral = 3.4;
    }
    return codigo;
    }
