/*
*Author: Martín Morales Trejo
*martin.mo.tre@comunidad.unam.mx
*sept 17, 2021
*/

#include <iostream>

using namespace std;

int main() {
	int x = 0;
	int y = 0;
	string s = "";


	cout << "Primer numero:" << endl;
	cin >> x;
	cout << "Operacion:" << endl;
	cin >> s;
	cout << "Segundo numero:" << endl;
	cin >> y;


	if (s == "+") {
		cout << "Resultado: "<<"x + y = "<<x + y << endl;
	}
	if (s == "-") {
		cout << "Resultado: " <<"x - y = "<< x - y << endl;
    }
	if (s == "*") {
		cout << "Resultado: " <<"x * y = " << x * y << endl;
    } 
	if (s == "/") {
		cout << "Resultado: " << "x / y = " << x / y << endl;
    }
	if (s == "%") {
		cout << "Resultado: " << "x % y = " << x % y << endl;
    }

   return 0; 
}

