/**
 * a) Crear una función (no recursiva) que calcule el factorial de un
 *    número natural
 * b) Permitir ingresar números hasta que el usuario ingrese un número
 *    negativo
 * c) Mostrar el promedio de los factoriales calculados
 */

#include <iostream>
using namespace std;

int factorial(int n)
{
    int resultado = 1;
    for (int i = 1; i <= n; ++i)
    {
        resultado = resultado * i;
    }
    return resultado;
}

int main()
{
    float sumatoria = 0.0f;
    int contador = 0;

    while (true)
    {
        int n;

        cout << "Ingrese n (numero entero): ";
        cin >> n;

        if (n < 0)
        {
            break;
        }

        float resultado = factorial(n);
        cout << "El factorial de " << n << " es: " << resultado << endl;

        sumatoria += resultado;
        contador++;
    }

    if (contador > 0)
    {
        cout << "Promedio de los factoriales calculados: " << (sumatoria / contador) << endl;
    }
    else
    {
        cout << "No se ingresaron valores válidos para calcular factoriales." << endl;
    }

    return 0;
}
