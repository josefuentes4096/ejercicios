/**
 * a) Crear una función (no recursiva) que calcule la potencia xn
 * b) Permitir ingresar números x, n, y debe invocarse la función creada,
 *    hasta que el usuario ingrese 0, 0
 * c) Mostrar el promedio de las potencias calculadas
 */

#include <iostream>
using namespace std;

float potencia(float base, int exponente)
{
    float resultado = 1.0f;
    int absExponente = (exponente < 0) ? -exponente : exponente;

    for (int i = 0; i < absExponente; ++i)
    {
        resultado *= base;
    }

    resultado = (exponente < 0) ? 1.0f / resultado : resultado;
    return resultado;
}

int main()
{
    float sumatoria = 0.0f;
    int contador = 0;

    while (true)
    {
        float x;
        int n;

        cout << "Ingrese x: ";
        cin >> x;
        cout << "Ingrese n (numero entero): ";
        cin >> n;

        if (x == 0 && n == 0)
            break;

        float resultado = potencia(x, n);
        cout << x << " elevado a la " << n << " es: " << resultado << endl;

        sumatoria += resultado;
        contador++;
    }

    if (contador > 0)
    {
        cout << "Promedio de las potencias calculadas: " << (sumatoria / contador) << endl;
    }
    else
    {
        cout << "No se ingresaron valores válidos para calcular potencias." << endl;
    }

    return 0;
}
