/*
*Author: Martín Morales Trejo
*martin.mo.tre@comunidad.unam.mx
*sept 17, 2021
*/
#include <iostream>
#include <array>

#define LEN 3 //Número de elementos en los arreglos

// Añadir std para fácil llamado de funciones
using namespace std;

// Declaración de funciones
void ImprimirArreglo(array<float, LEN> arreglo);
array<float, LEN> LlenarArreglo(void);
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo);
array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2);

int main()
{

    char decision;
    array<float, LEN> arr = { 0 };// Inicializamos el arreglo con ceros como buena práctica
    array<float, LEN> arrs = { 0 };
    array<float, LEN> arrm = { 0 };
    arr = LlenarArreglo(); // Solicitamos al usuario que llene un arreglo y lo asignamos a nuestro arreglo principal
    cout << "Operación: ";
    cin >> decision;
    // Si la operación no es '+' de suma, o '*' de multiplicación, seguimos preguntando al usuario.
    while (decision != '+' && decision != '*')
    {
        cout << "Operación: ";
        cin >> decision;
    }
    // Si se ingresa la multiplicación
    if (decision == '*') {
        float factor;
        cout << "Factor: ";
        cin >> factor;  // Pedimos el factor a multiplicar
        arrm = MultiplicarArreglo(arr, factor); // Multiplicamos nuestro arreglo principal por el factor y el resultado
        // lo asignamos a nuestro arreglo principal.
        cout << "Resultado: ";
        ImprimirArreglo(arrm);
    }
    // Si se ingresa la suma
    else if (decision == '+') {
        array<float, LEN> arr2 = { 0 }; // Creamos el segundo arreglo y lo inicializamos en ceros
        arr2 = LlenarArreglo(); // Pedimos al usuario que llene otro arreglo y lo asignamos a nuetsro nuevo arreglo
        arrs = SumarArreglos(arr, arr2); // Sumamos ambos arreglos elemento a elemento, y reasignamos el resutlado a nuestro
        // arreglo principal
        cout << "Resultado: ";
        ImprimirArreglo(arrs);
    }
    // Imprimimos el resultado de la operación sobre el arreglo principal

    return 0; // Indicamos que salimos del programa con éxito
}

// Imprime los elementos del arreglo 'arreglo' separando cada elemento con un espacio en blanco
void ImprimirArreglo(array<float, LEN> arreglo)
{
    for (int i = 0; i < LEN; i++)
        cout << arreglo[i] << ' ';
    cout << '\n';
}


// Llena un arreglo de tamaño LEN y lo "regresa" como resultado
array<float, LEN> LlenarArreglo() //La funcion LlenarArreglo consiste en el llenado de un arreglo con 3 posiciones
{
    array<float, LEN> Arreglo = { 0 }; //primeramente se inicializa el arreglo a llenar llamado "Arreglo"
    for (int i = 0; i < LEN; i++) { //Posteriormente se hace una iteración con la fucnión for desde la posición i= 0 hasta LEN
        cout << "Valor Elemento [" << i << "]: "; // Se imprime en pantalla los valores que fue tomando i mientras se ejecutó la iteración
        cin >> Arreglo[i];// Se guardan los valores en el Arreglo
    }
    return Arreglo;
}

// Multiplica cada elemento del arreglo 'arreglo' por el factor 'mult'
array<float, LEN> MultiplicarArreglo(array<float, LEN> arr, float factor){
//La función MultiplicarArreglo tiene como argumento 2 arreglos llamados arr y factor, argumento esperado para que la función
//pueda realizar la multiplicación de 2 arreglos
    array<float, LEN> Multiplicacion = { 0 }; //primeramente se inicializa el arreglo a llenar llamado "Multiplicación"
    for (int i = 0; i < LEN; i++) { //Posteriormente se hace una iteración con la fucnión for desde la posición i= 0 hasta LEN
        Multiplicacion[i] = arr[i] * factor; //A continuación se llena el arreglo de 3 elementos mediante la multiplicación del 
        //arreglo arr multiplicado por el arreglo factor
    }
    return Multiplicacion; //Regresa el procedimiento de la multiplicación para ser usado
}

// Suma elemento a elemento los arreglos 'arr1' y 'arr2' y regresa el arreglo resultante
array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2){
//La función de SumarArreglos NECESITA usar de los arreglos arr1 y arr2 para sumarlos, por lo que primero se llenan estos mediante 
    array<float, LEN> Suma = { 0 };//primeramente se inicializa el arreglo a llenar llamado "Suma"
    for (int i = 0; i < LEN; i++) {//Posteriormente se hace una iteración con la fucnión for desde la posición i= 0 hasta LEN
        Suma[i] = arr1[i] + arr2[i];//A continuación se llena el arreglo Suma de 3 elementos mediante la suma del 
        //arreglo arr1 y el arr2
    }
    return Suma; //Regresa el procedimiento de la suma para ser usado
}
