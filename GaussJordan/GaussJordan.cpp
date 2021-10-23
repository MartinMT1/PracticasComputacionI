/*
* Author: Mart�n Morales Trejo
* martin.mo.tre@comunidad.unam.mx
* sep 30, 2021

El siguiente c�digo se base en el m�todo de Gauss Jordan para resolver un sistema de 2 ecuaciones.
*/

#include <iostream>
#include <array>

 // A�adir std para f�cil llamado de funciones
using namespace std;

//// Declaraci�n de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz& miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz& miMatriz);

template <typename matriz>
void GaussJordan(matriz& miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz& miMatriz);


int main()
{
    // Definimos el n�mero de variables de nuestro sistema
    const int variables = 3;
    // El n�mero de columnas ser� el n�mero de variables m�s su solici�n para cada ecuaci�n
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el m�todo de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la soluci�n de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con �xito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ning�n valor.
*/
template <typename matriz>
void LlenarMatriz(matriz& miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ning�n valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz& miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime en pantalla la soluci�n para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ning�n valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz& miMatriz)
{
    int variables = miMatriz.size();
    cout << "\n\nSolucion:" << endl;
    for (int i = 0; i < variables; i++) {
        cout << "x" << i << " = " << miMatriz[i][variables] << endl; //Esta l�nea imprimir� el valor de x segiodo por el ind�ce del 0 al 2
        //que har� referencia a al resultado 
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la soluci�n del algoritmo.
No regresa ning�n valor.
*/
template <typename matriz>
void GaussJordan(matriz& miMatriz)
{
    float Mayor; 
    float Aux;
    float Pivote;
    int Ind; 
    

    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) //La funci�n for va a iterar considerando las condiciones establecidas
    {
        Mayor = abs(miMatriz[i][i]); //de lo anterior va a establecer un valor a la variable Mayor
        Ind = i; //Y posteriormente otorgar� un valor a la varialbe Ind, la cual nos servir� cono el �ndice del arreglo

        for (int j = i + 1; j < variables; j++)  //Esta funci�n hace lo mismo, pero con la variable j que ayuda a identificar valores de un arreglo por �ndice
        {
            if (Mayor < abs(miMatriz[j][i])) 
            {
                Mayor = abs(miMatriz[j][i]);
                Ind = j;
            }
        }

        if (i != Ind)  //Nuevamente se repite la operaci�n par un tercer valor h
        {
            for (int h = 0; h < variables + 1; h++) 
            {
                Aux = miMatriz[i][h];
                miMatriz[i][h] = miMatriz[Ind][h];
                miMatriz[Ind][h] = Aux;
            }
        }

        if (miMatriz[i][i] == 0) //Ahora establecemos que s� en la matriz al acceder por incdice a los valores es cero, entonces el sistema no tiene soluci�n
        {
            cout << "El sistema no tiene solucion" << endl;
        }

        else //En caso contrario se ejecuta el siguiente procedimiento 
        {
        for (int h = 0; h < variables; h++) //Se establece un civlo for que va a aiterar valores de h
            {
            if (h != i) //Mientras h no sea igual a i
            {
                Pivote = -miMatriz[h][i]; //se establecer� un valor al pivote compuesto por h e i
                    for (int k = i; k < variables + 1; k++) //Ahora se establece la operaci�n que permitir� generar cambios en la matriz por GJ
                    {
                        miMatriz[h][k] = miMatriz[h][k] + Pivote * miMatriz[i][k] / miMatriz[i][i]; //Establece valores a miMatriz
                    }
            }
                else //en caso de que i sea igual a h
                {
                    Pivote = miMatriz[i][i]; //El pivote estar� conformado por valores localizados por i
                    for (int k = i; k < variables + 1; k++)  
                    {
                        miMatriz[h][k] = miMatriz[h][k] / Pivote; //Entonces se establece la operaci�n que divide valores de h y k entre el pivote
                    }
                }
            }
        }
    }
}