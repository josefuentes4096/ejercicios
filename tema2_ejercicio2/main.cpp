/**
 * Una central telefónica genera un registro de todas las llamadas 
 * telefónicas de larga distancia:
 *   Provincia desde donde se origina la llamada
 *   Fecha y hora de inicio
 *   Duración en minutos
 *   Ancho de banda utilizado (MB/segundo)
 * La carga finaliza con provincia “N”.
 * 
 * Se pide:
 *   Calcular el uso total de datos (ancho de banda x minutos de la 
 *     suma de todas las llamadas)
 *   Calcular el promedio de duración de las llamadas
 *   Mostrar fecha y hora de inicio de la llamada de mayor duración
 *   Informar la cantidad de llamadas originadas en CABA
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string provincia_origen;
    string fecha_hora_inicio;
    int duracion;
    int ancho_de_banda_utilizado;

    float uso_total_datos = 0.0f;
    int sumatoria_duracion = 0;
    int cantidad_llamadas = 0;
    int maximo_duracion = 0;
    string fecha_hora_inicio_llamada_mas_larga = "";
    int cantidad_llamadas_CABA = 0;

    do
    {
        cout << "Ingrese provincia origen: ";
        cin >> provincia_origen;

        if (provincia_origen != "N")
        {
            cout << "Ingrese fecha-hora de inicio (AAAA-MM-DD_HH:mm:ss): ";
            cin >> fecha_hora_inicio;

            cout << "Ingrese duracion (minutos): ";
            cin >> duracion;

            cout << "Ingrese ancho de banda utilizado: ";
            cin >> ancho_de_banda_utilizado;


            uso_total_datos += ancho_de_banda_utilizado * duracion;

            sumatoria_duracion += duracion;
            cantidad_llamadas++;

            if (duracion > maximo_duracion)
            {
                maximo_duracion = duracion;
                fecha_hora_inicio_llamada_mas_larga = fecha_hora_inicio;
            }

            if (provincia_origen == "CABA")
            {
                cantidad_llamadas_CABA++;
            }
        }

    } while (provincia_origen != "N");

    cout << "Uso total de datos: " << uso_total_datos << " GB" << endl;

    if (cantidad_llamadas > 0)
    {
        float promedio_duracion = static_cast<float>(sumatoria_duracion) / cantidad_llamadas;
        cout << "Promedio de duracion: " << promedio_duracion << " minutos" << endl;
    }
    else
    {
        cout << "No se registraron llamadas para calcular el promedio de duracion." << endl;
    }

    cout << "Fecha-hora de la llamada mas larga: " << fecha_hora_inicio_llamada_mas_larga << endl;
    cout << "Cantidad de llamadas originadas en CABA: " << cantidad_llamadas_CABA << endl;

    return 0;
}
