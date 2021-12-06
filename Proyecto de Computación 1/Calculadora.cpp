#include <iostream>
#include <stdlib.h>
#include <map>

// Incluimos nuestro encabezado con la definición de la clase CalculadoraDeElectronica
#include "CalculadoraDeElectronica.h"

using namespace std;

//////////////////////////////////
// Declaración de funciones
///////////////////////////////////

//Funciones para Ley de Ohm
char PedirOpcion();//Para seleccionar la operación
char ElegirVariante();
char ElegirValoresConocidos();//Para definir los valores cococidos para aplicar la ley de ohm
char ElegirValoresResistencias();
char DefinirNElementos();

//Funciones para calcular valor de resistencia por sus bandas de color
double SeleccionarColor();

//Funciones para calcular resistencia de diodo LED
string VoltajeUmbral();

//Funciones para calculos con capacitores
char ElegirValoresCapacitores();

//Funciones para calculos con inductores
char ElegirValoresInductores();

//Se definen variables globales para el cálculo de la ley de Ohm
float E1 = 0, E2 = 0, E3 = 0, E4 = 0, E5 = 0, E6 = 0;
float Rserie = 0;
float Rparalelo = 0;
char NElementos;

//Se definen variables globales 
double color=0;
double multiplicador = 0;
double multiplicador5 = 0;
char escala;
string InicialesColor; 
string tol;
string tol5;
string codigo;
double voltajeUmbral = 0;


int main()
{
    //Creamos un objeto de la clase OperacionesDeCalculadora
    OperacionesDeCalculadora miClase;

    //Variables de las operaciones con Ley de Ohm
    char option;
    char Variante;
    char ValoresConocidos3;
    float Voltaje = 1;
    float Corriente = 1;
    float Resistencia=1;


    //Variables del cálfulo de resistencia por código de colores
    double ValorResistencia = 0;
    double PrimerBanda = 0;
    double SegundaBanda = 0;
    double TercerBandaMultiplicadora = 0;
    double TercerBanda5 = 0;
    double CuartaBandaMultiplicadora = 0;
    char escalaOhms=0;
    string tolerancia;
    char continuar;
    float omitir=0;

    
    //Calculo resoistencia para diodo
    double fuente = 0;
    double corrienteEsperada = 0;
    double voltajeDiodo = 0;

    //Capacitores
    float cargaElectrica = 0;
    double capacitancia = 0;

    //Inductores
    double inductancia = 0;

	
        do {
            printf("\n\n           Bienvenido a la calculadora de electrónica :)\n\nAquí podrás realizar operaciones para reforzar tus conocimientos en electrónica\n");
            printf("Selecciona la operación que deseas realizar\n\n");
            printf("1). Cálculo de circuitos con ley de Ohm\n");
            printf("2). Definir el valor de una resistencia por su código de colores\n");
            printf("3). Definir el valor de la resistencia para un Diodo LED\n");
            printf("4). Cálculos con capacitores\n");
            printf("5). Cálculos con inductores\n");
            printf("6). SALIR\n\n");

            option = PedirOpcion();
            switch (option)
            {
                // Si operacion == '1' entonces realiza lo siguiente:

            case '1'://Cálculo de circuitos con ley de Ohm
                //Agregar do-while si se desea salir de la calculadora en cada operación 
                printf("Selecciona la operación que deseas realizar\n");
                printf("1). Cálculo de circuitos en serie\n");
                printf("2). Cálculo de circuitos en paralelo\n\n");

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

                    ValoresConocidos3 = ElegirValoresConocidos();              
                    switch (ValoresConocidos3)
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
                        NElementos = ElegirValoresResistencias();
                        Resistencia = Rserie;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                        //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.CorrienteTotal(miClase.ObtenerR(), miClase.ObtenerV());
                        break;
                    case '3': //Corriente y resistencias
                        cout << "Introduce el valor de la Corriente (en amperes)";
                        cin >> Corriente;
                        NElementos = ElegirValoresResistencias();
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

                    ValoresConocidos3 = ElegirValoresConocidos();
                    switch (ValoresConocidos3)
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
                        NElementos = ElegirValoresResistencias();
                        Resistencia = Rparalelo; 
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.CorrienteTotal(miClase.ObtenerR(), miClase.ObtenerV());
                        break;

                    case '3': //Corriente y resistencias
                        cout << "Introduce el valor de la Corriente (en amperes)";
                        cin >> Corriente;
                        NElementos = ElegirValoresResistencias();         
                        Resistencia = Rparalelo; 
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
                
                try {
                    if ((Resistencia == 0) || (Voltaje == 0) || (Corriente == 0)) {
                        throw("** El valor de una variable introducida NO ES VÁLIDO, esto pasa cuando:\n\n\a");
                    }
                }
                catch(const char *s){
                    cout<<"Catch: "<<s<<endl;
                    cout<<"** Has proporcionado un valor 0 a alguna de las variables de Voltaje, Corriente o Resistencia"<<endl;
                    cout<<"Recuerda que para los cálculos con ley de ohm requieres los valores de 2 variables que sean disferentes a 0"<<endl;
                    cout<<"SOLUCIÓN: Selecciona la opción para cálculos con ley de ohm y en el apartado de ´variables con las que cuentas´"<<endl;
                    cout<<"Digita valores válidos diferentes a 0 \n\n\n\n"<<endl;

                    printf("Reinicia la calculadora y vuelve a intentarlo :)\n\n\n\n");
                    exit(0);

                }
                 
                    cout << "**La Corriente Total es: " << miClase.ObtenerI() << " Amperes\n" << endl;
                    cout << "**La Resistencia Total es: " << miClase.ObtenerR() << " Ohms\n" << endl;
                    cout << "**El Voltaje Total es: " << miClase.ObtenerV() << " Volts\n\n\n\n" << endl;
                miClase.~OperacionesDeCalculadora();
                break;


            case '2'://Definir el valor de una resistencia por su código de colores\n");
                printf("A continuación podrás conocer el valor de una resistencia mediante la interpretación de sus bandas de colores:\n");
                printf("NOTA: Para obtener un resultado correcto debes orientar tu resistencia de la siguiente manera: \n\n");
                printf("** Localiza el extremo donde las bandas de colores se encuentren más juntas \n");
                printf("** Una vez localizado, mantén ese estremo a tu izquierda\n");
                printf("** Por último es importante que identifiques los colores de izquierda a derecha\n\n\n\n"); 
                printf("Dicho lo anterior, selecciona la operación\n\n");
                printf("1). Calculadora de resistencia con 4 bandas.\n\n");
                printf("2). Calculadora de resistencia con 5 bandas.\n\n");

                Variante = ElegirVariante();
                switch (Variante)
                {
                case '1': //resistencia con 4 bandas
                    printf("Para definir un color tendrás que introducir las iniciales de cada color como se muestra a continuación:\n");
                    printf("**Negro = ne\n**Café = ca\n**Rojo = ro\n**Naranja = na\n**Amarillo = am\n**Verde = ve\n**Azul = az\n");
                    printf("**Violeta = vi\n**Gris = gr\n**Blanco = bl\n**Dorado = do\n**Plata = pl\n");

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
                    tolerancia = tol;
                    /////////////
                    miClase.EstablecerValorTolerancia(tolerancia);
                    ////////////
                    break;
                    
                case '2':
                    printf("Para definir un color tendrás que introducir las iniciales de cada color como se muestra a continuación:\n");
                    printf("**Negro = ne\n**Café = ca\n**Rojo = ro\n**Naranja = na\n**Amarillo = am\n**Verde = ve\n**Azul = az\n");
                    printf("**Violeta = vi\n**Gris = gr\n**Blanco = bl\n**Dorado = do\n**Plata = pl\n");

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
                    TercerBanda5 = color;

                    cout << "Cuarta Banda: " << endl;
                    escalaOhms = escala;
                    color = SeleccionarColor();
                    CuartaBandaMultiplicadora = multiplicador5;
                    /////////////
                    miClase.EstablecerEscala(escalaOhms);
                    miClase.EstablecerValoresDeBanda(PrimerBanda, SegundaBanda, TercerBanda5, CuartaBandaMultiplicadora);
                    miClase.ValorDeResistencia(PrimerBanda, SegundaBanda, TercerBanda5, CuartaBandaMultiplicadora);
                    /////////////
                    cout << "Quinta Banda: " << endl;
                    color = SeleccionarColor();
                    tolerancia = tol5;
                    /////////////
                    miClase.EstablecerValorTolerancia(tolerancia);
                    ////////////
                    break;///
                }

                printf("\n\nRESUMEN FINAL:\n\a");

                if ((miClase.ObtenerValorResistencia() == 0)) {
                    cout << "La Resistencia no existe" << endl;
                }
                else {
                    cout << "**El valor de la Resistencia es: " << miClase.ObtenerValorResistencia() << " " << miClase.ObtenerEscala() << "Ohms\a" << endl;
                    cout << "  Con una toletancia de: " << miClase.ObtenerTolerancia() << "\a\n\n\n\n" << endl;
                }
                miClase.~OperacionesDeCalculadora();
                break;
                
            case '3'://Definir el valor de la resistencia para un Diodo LED
                printf("\nA continuación podrás calcular el valor de la resistencia necesaria para que un Diodo \nLED opere correctamente");
                printf("Para lo anterior necesitarás introducir el valor de tu fuente de\n alimentación, la corriente esperada y el color de tu LED\n\n");
                 
                cout << "Introduce el valor de tu fuente de alimentación (en volts):\n";
                cin >> fuente;
                miClase.EstablecerValorDeFuente(fuente);

                cout<< "Introduce el valor de la corriente esperada (en amperes):\n";
                cin >> corrienteEsperada;
                miClase.EstablecerValorDeCorrienteDelCircuito(corrienteEsperada);

                cout << "Introduce el color de tu LED:\n";
                cout << "Considera el siguiente código de colores:\n" << endl;
                printf("**Rojo = ro\n**Amarillo = am\n**Naranja = na\n**Verde = ve\n**Azul = az\n**Blanco = bl \n\n");
                codigo = VoltajeUmbral();
                voltajeDiodo = voltajeUmbral;

                miClase.EstablecerVoltajeDiodo(voltajeDiodo);
                ///
                miClase.CalculoVoltajeResistencia(fuente, voltajeDiodo);
                miClase.ResistenciaSugerida(miClase.ObtenerVoltajeResistencia(), corrienteEsperada);
                ///
                printf("\n\nRESULTADO:\n\a");
                cout << "El valor de la resistencia sugerida es: " << miClase.ObtenerValorResistenciaSugerida() << " " << "Ohms\n\n\n\n" << endl;             
                
                miClase.~OperacionesDeCalculadora();
                break;

            case '4': //Capacitores
                printf("Selecciona la operación\n\n");
                printf("1). Calculadora de capacitancia total en circuitos serie y paralelo.\n\n");
                printf("2). Calculadora de Carga eléctrica (Q), Voltaje (V) y Capacitancia (C).\n\n");
                printf("3). Calculadora de tiempo de carga.\n\n");

               ValoresConocidos3 = ElegirValoresConocidos();
               switch (ValoresConocidos3)
               {
               case '1'://Capacitores en serie y paralelo
                   printf("Selecciona la operación que deseas realizar\n\n");
                   printf("1). Cálculo de circuitos en serie\n");
                   printf("2). Cálculo de circuitos en paralelo\n\n");
                   
                   Variante = ElegirVariante();
                   switch (Variante)
                   {
                   case '1': //Circuito en serie
                       printf("A continuación ingresarás el número de capacitores que tiene tu circuito equivalente\n\n");
                           NElementos = ElegirValoresCapacitores();
                           capacitancia = Rparalelo;
                           //LLamamos una función miembro de la clase mediante el objeto miclase
                           //Para Realizar la Operación
                           miClase.EstablecerCapacitanciaTotal(capacitancia); 
                       break;

                   case '2': //Circuito Paralelo

                           printf("A continuación ingresarás el número de capacitores que tiene tu circuito equivalente\n\n");

                           NElementos = ElegirValoresCapacitores();
                           capacitancia = Rserie;
                           omitir = 1;
                           //LLamamos una función miembro de la clase mediante el objeto miclase
                           miClase.EstablecerCapacitanciaTotal(capacitancia);
                       break;

                   default:
                       cout << "Operacion no valida\n";
                       break;

                   }
                   printf("\nRESUMEN FINAL:\n\a");
                       cout << "**La Capacitancia total es: " << miClase.ObtenerCapacitancia() << " Faradios\n\n\n\n" << endl;
                   break;

               case '2'://Capacitancia,voltaje y carga total
                   printf("A continuación podrás calcular la capacitancia, voltaje y carga electrica totales de un circuito, para hacerlo\n");
                   printf("necesitarás dos de los tres datos\n");
                   printf("¿Qué valores conoces?\n");
                   printf("1). Voltaje y Capacitancia\n");
                   printf("2). Voltaje y Carga eléctrica\n");
                   printf("3). Carga eléctrica y Capacitancia\n\n");

                   ValoresConocidos3 = ElegirValoresConocidos();
                   switch (ValoresConocidos3)
                   {
                   case '1'://V y C
                       cout << "Introduce el valor del voltaje (en volts)\n";
                       cin >> Voltaje;
                       cout << "Introduce el valor de la Capacitancia (en Faradios)\n";
                       cin >> capacitancia;
                       //LLamamos una función miembro de la clase mediante el objeto miclase
                      //Para Realizar la Operación
                       miClase.EstablecerValoresVCCe(Voltaje, capacitancia, cargaElectrica);
                       miClase.CargaTotal(miClase.ObtenerV(), miClase.ObtenerCapacitancia());
                       break;

                   case '2'://V y Q
                       cout << "Introduce el valor del voltaje (en volts)\n";
                       cin >> Voltaje;
                       cout << "Introduce el valor de la Carga eléctrica (en coulombs)\n";
                       cin >> cargaElectrica;
                       //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                       miClase.EstablecerValoresVCCe(Voltaje, capacitancia, cargaElectrica);
                       miClase.CapacitanciaEnCircuito(miClase.ObtenerCargaElectrica(), miClase.ObtenerV());
                       break;

                   case '3': //C y Q
                       cout << "Introduce el valor de la Capacitancia (en Faradios)\n";
                       cin >> capacitancia;
                       cout << "Introduce el valor de la Carga eléctrica (en coulombs)\n";
                       cin >> cargaElectrica;
                       //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                       miClase.EstablecerValoresVCCe(Voltaje, capacitancia, cargaElectrica);
                       miClase.VoltajeEnCapacitores(miClase.ObtenerCargaElectrica(), miClase.ObtenerCapacitancia());
                       break;

                   default:
                       cout << "Operacion no valida\n";
                       break;
                   }
                   printf("\nRESUMEN FINAL:\n\a");

                   cout << "**La Capacitancia Total es: " << miClase.ObtenerCapacitancia() << " Faradios\n" << endl;
                   cout << "**La Carga Eléctrica Total es: " << miClase.ObtenerCargaElectrica() << " Couloums\n" << endl;
                   cout << "**El Voltaje Total es: " << miClase.ObtenerV() << " Volts\n\n\n\n" << endl;
                   break;

               case '3':
                   printf("Para el calculo del tiempo que tarda en cargar un capacitor, es necesario que cuentes con:\n");
                   printf("1). La Capacitancia en Faradios\n");
                   printf("2). La Resistencia tortal en ohms (puedes emplear alguna de las opciones de la calculadora para calcularla)\n\n");

                   cout << "Introduce el valor de la capacitancia de tu capacitor electrólitico o cerámico (en Faradios):\n";
                   cin >> capacitancia;
                   //miClase.EstablecerValorDeFuente(fuente);

                   cout << "Introduce el valor de la Resistencia (en ohms):\n";
                   cin >> Resistencia;
                   miClase.EstablecerCyR(capacitancia, Resistencia);
                   miClase.CalculoTiempo();


                   printf("\n\nRESULTADO:\n\a");
                   cout << "El tiempo que tarda en cargarse el capacitor es de " << miClase.ObtenerTiempoCarga() << " " << "Segundos\n\n\n\n" << endl;

                   break;
                }
                miClase.~OperacionesDeCalculadora();
                break;

            case '5': //INDUCTORES

                printf("Selecciona la operación\n\n");
                printf("1). Calculadora de inductancia total en circuitos serie y paralelo.\n\n");
                printf("2). Calculadora de Corriente, Voltaje y Reactancia Inductiva.\n\n");

                Variante = ElegirVariante();
                switch (Variante)
                {
                case '1'://Capacitores en serie y paralelo
                    printf("Selecciona la operación que deseas realizar\n\n");
                    printf("1). Cálculo de circuitos en serie\n");
                    printf("2). Cálculo de circuitos en paralelo\n\n");

                    Variante = ElegirVariante();
                    switch (Variante)
                    {
                    case '1': //Circuito en serie
                        printf("A continuación ingresarás el número de inductores que tiene tu circuito equivalente\n\n");

                        NElementos = ElegirValoresInductores();
                        inductancia = Rserie;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                        //Para Realizar la Operación
                        miClase.EstablecerInductanciaTotal(inductancia);
                        break;

                    case '2': //Circuito Paralelo
                        printf("A continuación ingresarás el número de capacitores que tiene tu circuito equivalente\n\n");
                        NElementos = ElegirValoresInductores();
                        inductancia = Rparalelo;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                        miClase.EstablecerInductanciaTotal(inductancia);
                        break;

                    default:
                        cout << "Operacion no valida\n";
                        break;

                    }
                    printf("\nRESUMEN FINAL:\n\a");
                        cout << "**La Inductantancia total es: " << miClase.ObtenerInductancia() << " Henrios\n\n\n\n" << endl;
                    
                    break;

                case '2'://Corriente ,voltaje y reactancia inductiva
                    printf("A continuación podrás calcular la Reactancia inductiva, voltaje y Corriente totales de un circuito, para hacerlo\n");
                    printf("necesitarás dos de los tres datos\n\n");
                    printf("NOTA: La reactancia inductiva se presenta por el efecto electromagnetico de una bobina energizada, lo que genera\n");
                    printf("oposición al flujo de electrones (corriente). Lo anterior puede considerarse como una resistencia en ohms.\n\n");


                    printf("¿Qué valores conoces?\n");
                    printf("1). Voltaje y Corriente\n");
                    printf("2). Voltaje y Reactancia Inductiva\n");
                    printf("3). Reactancia Inductiva y Corriente\n\n");

                    //A continuación utilizaremos la ley de ohm para generar los cálculos

                    ValoresConocidos3 = ElegirValoresConocidos();
                    switch (ValoresConocidos3)
                    {
                    case '1'://Voltaje y corriente
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        cout << "Introduce el valor de la Corriente (en amperes)\n";
                        cin >> Corriente;
                        //LLamamos una función miembro de la clase mediante el objeto miclase
                       //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.ResistenciaTotal(Voltaje, Corriente);

                        break;
                    case '2'://Voltaje y resistencias
                        cout << "Introduce el valor del voltaje (en volts)\n";
                        cin >> Voltaje;
                        cout << "Introduce el valor de la Reactancia inductiva  (en ohms)\n";
                        cin >> Resistencia;

                        //Para Realizar la Operación
                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.CorrienteTotal(miClase.ObtenerR(), miClase.ObtenerV());
                        break;

                    case '3': //Corriente y resistencias
                        cout << "Introduce el valor de la Reactancia inductiva (en ohms)\n";
                        cin >> Resistencia;
                        cout << "Introduce el valor de la Corriente (en amperes)";
                        cin >> Corriente;

                        miClase.EstablecerValoresVRI(Voltaje, Resistencia, Corriente);
                        miClase.VoltajeTotal(Resistencia, Corriente);
                        break;

                    default:
                        cout << "Operacion no valida\n";
                        break;
                    }
                    printf("\nRESUMEN FINAL:\n\a");

                    try {
                        if ((Resistencia == 0) || (Voltaje == 0) || (Corriente == 0)) {
                            throw("** El valor de una variable introducida NO ES VÁLIDO, esto pasa cuando:\n\n\a");
                        }
                    }
                    catch (const char* s) {
                        cout << "Catch: " << s << endl;
                        cout << "** Has proporcionado un valor 0 a alguna de las variables de Voltaje, Corriente o Reactancia inductiva" << endl;
                        cout << "Recuerda que para los cálculos con ley de ohm requieres los valores de 2 variables que sean disferentes a 0" << endl;
                        cout << "SOLUCIÓN: Selecciona la opción para cálculos con inductores y en el apartado de ´variables con las que cuentas´" << endl;
                        cout << "Digita valores válidos diferentes a 0 \n\n\n\n" << endl;

                        printf("Reinicia la calculadora y vuelve a intentarlo :)\n\n\n\n");
                        exit(0);

                    }
                        cout << "**La Corriente es: " << miClase.ObtenerI() << " Amperes\n" << endl;
                        cout << "**La Reactancia inductiva es: " << miClase.ObtenerR() << " Ohms\n" << endl;
                        cout << "**El Voltaje es: " << miClase.ObtenerV() << " Volts\n\n\n\n" << endl;
                    break;
                }
                miClase.~OperacionesDeCalculadora();
                break;
               
            case '6': //SALIR
                exit(0);
                break;
                // Si ninguno de los casos anteriores se cumplió, entonces realiza lo siguiente
            default:
                cout << "Operacion no valida\n";
                break;
            }      
        }
        while (option != 6);
   
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

//DEFINICIÓN DE FUNCIONES:

////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//LEY DE OHM
    // Solicita una operación válida al usuario para elegir entre las opciones del menú entre 6 opciones
    char PedirOpcion()
    {
        char option;
        do {
            cout << "Digita el número de la operación: ";
            cin >> option;
        } while (option != '1' && option != '2' && option != '3' && option != '4' && option != '5' && option != '6');
        return option;
    }

    // Solicita una operación válida al usuario para elegir entre las opciones del menú entre 2 opciones
    char ElegirVariante()
    {
        char Variante;
        do {
            cout << "Digita el número de la operación: ";
            cin >> Variante;
        } while (Variante != '1' && Variante != '2');
        return Variante;
    }

    // Solicita una operación válida al usuario para elegir entre las opciones del menú entre 3 opciones
    char ElegirValoresConocidos()
    {
        char ValoresConocidos3;
        do {
            cout << "Digita el número de la operación: ";
            cin >> ValoresConocidos3;
        } while (ValoresConocidos3 != '1' && ValoresConocidos3 != '2' && ValoresConocidos3 != '3');
        return ValoresConocidos3;
    }

    char ElegirValoresResistencias()
    {
        //char NResis;
        do {
            printf("Introduce el valor de las resistencias (en ohms)\n");
            printf("¿Cuántas resistencias tiene tu circuito¨?\n  Respuesta: ");
            cin >> NElementos;
        } while (NElementos != '1' && NElementos != '2' && NElementos != '3' && NElementos != '4' && NElementos != '5' && NElementos != '6');
      
        NElementos = DefinirNElementos();
        return NElementos;
    }

//CÁLCULO DE RESISTENCIA POR CÓDIGO DE COLORES
    double SeleccionarColor()
    {
        map<string, double> mp; //mapeo

        mp["ne"] = 0;//negro
        mp["ca"] = 1;//café
        mp["ro"] = 2;//rojo
        mp["na"] = 3;//naranja
        mp["am"] = 4;//amarillo
        mp["ve"] = 5;//verde
        mp["az"] = 6;//azul
        mp["vi"] = 7;//violeta
        mp["gr"] = 8;//gris
        mp["bl"] = 9;//blanco
        mp["do"] = 0;//dorado
        mp["pl"] = 0;//plateado

        char kilos = 'K';
        char megas = 'M';
        char gigas = 'G';
        char NA = ' ';

        do {
            cout << "¿Cuál es el color de la banda?\n";
            cin >> InicialesColor;
        } while (InicialesColor != "ne" && InicialesColor != "ca" && InicialesColor != "ro" && InicialesColor != "na" 
            && InicialesColor != "am" && InicialesColor != "ve" && InicialesColor != "az" && InicialesColor != "vi" 
            && InicialesColor != "gr" && InicialesColor != "bl" && InicialesColor != "do" && InicialesColor != "pl");
        
            if (InicialesColor == "ne") {
                color = mp["ne"];
                multiplicador = 1;
                multiplicador5 = 1;
                tol = "No Aplica";
                tol5 = "±1%";
                escala = NA;
        }
            else if (InicialesColor == "ca") {
                color = mp["ca"];
                multiplicador = 10;
                multiplicador5 = 10;
                tol = "1% (F)";
                tol5 = "±2%";
                escala = NA;
            }
            else if (InicialesColor == "ro") {
                color = mp["ro"];
                multiplicador = 100;
                multiplicador5 = 100;
                tol = "±2% (G)";
                tol5 = "No Aplica";
                escala = NA;
            }
            else if (InicialesColor == "na") {
                color = mp["na"];
                multiplicador=1;
                multiplicador5 = 1;
                escala = kilos;
                tol = "No Aplica";
                tol5 = "No Aplica";
            }
            else if (InicialesColor == "am") {
                color = mp["am"];
                multiplicador = 10;
                multiplicador5 = 10;
                escala = kilos;
                tol = "No Aplica";
                tol5 = "No Aplica";
            }
            else if (InicialesColor == "ve") {
                color = mp["ve"];
                multiplicador = 100;
                multiplicador5 = 100;
                escala = kilos;
                tol = "±5% (D)";
                tol5 = "±0.5%";
            }
            else if (InicialesColor == "az") {
                color = mp["az"];
                multiplicador = 1;
                multiplicador5 = 1;
                escala = megas;
                tol = "±0.25% (C)";
                tol5 = "±0.25%";
            }
            else if (InicialesColor == "vi") {
                color = mp["vi"];
                multiplicador = 10;
                multiplicador5 = 10;
                escala = megas;
                tol = "±0.10% (B)";
                tol5 = "±0.10%";
            }
            else if (InicialesColor == "gr") {
                color = mp["gr"];
                multiplicador = 100;
                multiplicador5 = 100;
                tol = "±0.05%";
                tol5 = "±0.05%";
                escala = megas;
            }
            else if (InicialesColor == "bl") {
                color = mp["bl"];
                multiplicador = 1;
                multiplicador5 = 1;
                tol = "No Aplica";
                tol5 = "No Aplica";
                escala = gigas; 
            }
            else if (InicialesColor == "do") {
                color = mp["do"];
                multiplicador = 0.1;
                multiplicador5 = 0.1;
                tol = "±5%";
                tol5 = "±5%";
                escala = NA;
            }
            else if (InicialesColor == "pl") {
                color = mp["pl"];
                multiplicador = 1;
                multiplicador5 = 0.01;
                tol = "±10%";
                tol5 = "±10%";
                escala = NA;
            }
        return color;
    }

    //DIODO LED
    string VoltajeUmbral()
    {
    do {
        cout << "¿Cuál es el color del LED?\n";
        cin >> codigo;
    } while (codigo != "ro" && codigo != "am" && codigo != "na" && codigo != "ve" && codigo != "az" && codigo != "bl");

    if (codigo == "ro") {
        voltajeUmbral = 1.9;     
    }
    else if (codigo == "am") {
        voltajeUmbral = 1.7;
    }
    else if (codigo == "na") {
        voltajeUmbral = 2.4;
    }
    else if (codigo == "ve") {
        voltajeUmbral = 2.4;
    }
    else if (codigo == "az") {
        voltajeUmbral = 3.4;
    }
    else if (codigo == "bl") {
        voltajeUmbral = 3.4;
    }
    return codigo;
    }

    //Capacitores
    char ElegirValoresCapacitores()
    {
        do {
            printf("Introduce el valor de los capacitores (en Faradios)\n");
            printf("¿Cuántos capacitores tiene tu circuito¨?\n  Respuesta: ");
            cin >> NElementos;
        } while (NElementos != '1' && NElementos != '2' && NElementos != '3' && NElementos != '4' && NElementos != '5' && NElementos != '6');
        NElementos = DefinirNElementos();
        return NElementos;
    }
  
    //INDUCTORES
    char ElegirValoresInductores()
    {
        do {
            printf("Introduce el valor de los inductores (en Henrios)\n");
            printf("¿Cuántos inductores tiene tu circuito¨?\n  Respuesta: ");
            cin >> NElementos;
        } while (NElementos != '1' && NElementos != '2' && NElementos != '3' && NElementos != '4' && NElementos != '5' && NElementos != '6');
        NElementos = DefinirNElementos();
        return NElementos;
    }

    ////////////////////////Funciones compartidas///////////////////////
    char   DefinirNElementos()
    {      
        if (NElementos == '1') {
            cout << "Valor elemento pasivo 1: ";
            cin >> E1;
            Rparalelo = E1;
            Rserie = E1;
        }
        else if (NElementos == '2') {
            cout << "Valor elemento pasivo 1: ";
            cin >> E1;
            cout << "Valor elemento pasivo 2: ";
            cin >> E2;
            Rparalelo = 1 / ((1 / E1) + (1 / E2));
            Rserie = E1 + E2;
        }
        else if (NElementos == '3') {
            cout << "Valor elemento pasivo 1: ";
            cin >> E1;
            cout << "Valor elemento pasivo 2: ";
            cin >> E2;
            cout << "Valor elemento pasivo 3: ";
            cin >> E3;
            Rparalelo = 1 / ((1 / E1) + (1 / E2) + (1 / E3));
            Rserie = E1 + E2 + E3;
        }
        else if (NElementos == '4') {
            cout << "Valor elemento pasivo 1: ";
            cin >> E1;
            cout << "Valor elemento pasivo 2: ";
            cin >> E2;
            cout << "Valor elemento pasivo 3: ";
            cin >> E3;
            cout << "Valor elemento pasivo 4: ";
            cin >> E4;
            Rparalelo = 1 / ((1 / E1) + (1 / E2) + (1 / E3) + (1 / E4));
            Rserie = E1 + E2 + E3 + E4;
        }
        else if (NElementos == '5') {
            cout << "Valor elemento pasivo 1: ";
            cin >> E1;
            cout << "Valor elemento pasivo 2: ";
            cin >> E2;
            cout << "Valor elemento pasivo 3: ";
            cin >> E3;
            cout << "Valor elemento pasivo 4: ";
            cin >> E4;
            cout << "Valor elemento pasivo 5: ";
            cin >> E5;
           Rparalelo = 1 / ((1 / E1) + (1 / E2) + (1 / E3) + (1 / E4) + (1 / E5));
           Rserie = E1 + E2 + E3 + E4 + E5;
        }
        else if (NElementos == '6') {
            cout << "Valor elemento pasivo 1: ";
            cin >> E1;
            cout << "Valor elemento pasivo 2: ";
            cin >> E2;
            cout << "Valor elemento pasivo 3: ";
            cin >> E3;
            cout << "Valor elemento pasivo 4: ";
            cin >> E4;
            cout << "Valor elemento pasivo 5: ";
            cin >> E5;
            cout << "Valor elemento pasivo 6: ";
            cin >> E6;
            Rparalelo = 1 / ((1 / E1) + (1 / E2) + (1 / E3) + (1 / E4) + (1 / E5) + (1 / E6));
            Rserie = E1 + E2 + E3 + E4 + E5 + E6;
        }
        return NElementos;
    }

   