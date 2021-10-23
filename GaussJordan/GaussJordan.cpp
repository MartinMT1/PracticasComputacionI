/*
* Author: Martín Morales Trejo
* martin.mo.tre@comunidad.unam.mx
* sep 30, 2021

El siguiente código se base en el método de Gauss Jordan para resolver un sistema de 2 ecuaciones.
*/

#include <iostream>
#include <array>

 // Añadir std para fácil llamado de funciones
using namespace std;

//// Declaración de funciones
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
    // Definimos el número de variables de nuestro sistema
    const int variables = 3;
    // El número de columnas será el número de variables más su solición para cada ecuación
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con éxito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
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
No regresa ningún valor.
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
Imprime en pantalla la solución para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz& miMatriz)
{
    int variables = miMatriz.size();
    cout << "\n\nSolucion:" << endl;
    for (int i = 0; i < variables; i++) {
        cout << "x" << i << " = " << miMatriz[i][variables] << endl; //Esta línea imprimirá el valor de x segiodo por el indíce del 0 al 2
        //que hará referencia a al resultado 
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz& miMatriz)
{
    float Mayor; 
    float Aux;
    float Pivote;
    int Ind; 
    

    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) //La función for va a iterar considerando las condiciones establecidas
    {
        Mayor = abs(miMatriz[i][i]); //de lo anterior va a establecer un valor a la variable Mayor
        Ind = i; //Y posteriormente otorgará un valor a la varialbe Ind, la cual nos servirá cono el índice del arreglo

        for (int j = i + 1; j < variables; j++)  //Esta función hace lo mismo, pero con la variable j que ayuda a identificar valores de un arreglo por índice
        {
            if (Mayor < abs(miMatriz[j][i])) 
            {
                Mayor = abs(miMatriz[j][i]);
                Ind = j;
            }
        }

        if (i != Ind)  //Nuevamente se repite la operación par un tercer valor h
        {
            for (int h = 0; h < variables + 1; h++) 
            {
                Aux = miMatriz[i][h];
                miMatriz[i][h] = miMatriz[Ind][h];
                miMatriz[Ind][h] = Aux;
            }
        }

        if (miMatriz[i][i] == 0) //Ahora establecemos que sí en la matriz al acceder por incdice a los valores es cero, entonces el sistema no tiene solución
        {
            cout << "El sistema no tiene solucion" << endl;
        }

        else //En caso contrario se ejecuta el siguiente procedimiento 
        {
        for (int h = 0; h < variables; h++) //Se establece un civlo for que va a aiterar valores de h
            {
            if (h != i) //Mientras h no sea igual a i
            {
                Pivote = -miMatriz[h][i]; //se establecerá un valor al pivote compuesto por h e i
                    for (int k = i; k < variables + 1; k++) //Ahora se establece la operación que permitirá generar cambios en la matriz por GJ
                    {
                        miMatriz[h][k] = miMatriz[h][k] + Pivote * miMatriz[i][k] / miMatriz[i][i]; //Establece valores a miMatriz
                    }
            }
                else //en caso de que i sea igual a h
                {
                    Pivote = miMatriz[i][i]; //El pivote estará conformado por valores localizados por i
                    for (int k = i; k < variables + 1; k++)  
                    {
                        miMatriz[h][k] = miMatriz[h][k] / Pivote; //Entonces se establece la operación que divide valores de h y k entre el pivote
                    }
                }
            }
        }
    }
}