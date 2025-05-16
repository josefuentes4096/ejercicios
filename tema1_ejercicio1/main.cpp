/**
 * En la mesa de entrada de ANSES se registran personas que desean iniciar
 * su trámite jubilatorio.  Por cada persona se ingresan:
 * Nombre
 * Edad
 * Sexo (‘M’ para masculino, ‘F’ para femenino)
 *
 * El trámite finaliza con edad 0.  Se debe:
 * Derivar a Ventanilla “A” si:
 *   Es mujer y tiene 60 años o más
 *   Es hombre y tiene más de 65 años
 * Derivar el resto a Ventanilla “B”.
 *
 * Al finalizar, se debe informar:
 *   Cantidad de personas derivadas a cada ventanilla
 *   Porcentaje de personas que fueron a la Ventanilla A
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int edad;
    string nombre;
    char sexo;
    int ventanillaA = 0;
    int ventanillaB = 0;

    do
    {
        cout << "Ingrese edad: ";
        cin >> edad;
        if (edad > 0)
        {
            cout << "Ingrese Nombre: ";
            getline(cin, nombre);
            cout << "Ingrese sexo (M/F)";
            cin >> sexo;

            if ((sexo == 'F' && edad >= 60) || (sexo == 'M' && edad > 65))
            {
                ventanillaA++;
            }
            else
            {
                ventanillaB++;
            }
        }
    } while (edad > 0);

    cout << "Ventanilla A: " << ventanillaA << endl;
    cout << "Ventanilla B: " << ventanillaB << endl;
    if ((ventanillaA + ventanillaB) > 0)
    {
        cout << "Porcentaje ventanilla A: " << 100 * ventanillaA / (float)(ventanillaA + ventanillaB) << "%" << endl;
    }

    return 0;
}