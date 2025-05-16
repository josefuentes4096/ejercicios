/**
 * En una mesa de entrada de un instituto se recibe a quienes deseen 
 * inscribirse para cursar en esa institución.  Por cada persona se 
 * ingresan:
 *   Nombre
 *   Edad
 *   Tipo de carrera: ‘T’ para terciaria, ‘U’ para universitaria
 * El trámite finaliza con edad 0.  
 * 
 * Se debe:
 * Derivar a Ventanilla “A” si:
 *   Es mayor de 18 y la carrera es terciaria
 *   Es mayor de 25 y la carrera es universitaria
 *   Derivar el resto a Ventanilla “B”.
 * 
 * Al finalizar, informar:
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
    char tipo_carrera;
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
            cout << "Tipo de carrera (T/U)";
            cin >> tipo_carrera;

            if ((edad > 18 && tipo_carrera == 'T') || (edad > 25 && tipo_carrera == 'U'))
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