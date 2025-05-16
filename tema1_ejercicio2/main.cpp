/**
 * En una plataforma de streaming se ingresan por hora, los siguientes datos
 * de películas reproducidas:
 *   Código de película
 *   País de origen
 *   Duración en minutos
 *   Tamaño en GB
 *   Cantidad de reproducciones
 * La carga finaliza con código “FIN”.
 *
 * Se pide:
 *   Calcular el uso total de datos (tamaño x reproducciones)
 *   Calcular el promedio de duración de las películas reproducidas
 *   Mostrar cuál fue la película con más reproducciones
 *   Informar la cantidad de películas de origen argentino reproducidas
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string codigo;
    string pais;
    int duracion;
    float tamanioGB;
    int reproducciones;

    float uso_total_datos = 0.0f;
    int sumatoria_duracion = 0;
    int sumatoria_reproducciones = 0;
    int maximo_reproducciones = 0;
    string codigo_maximas_reproducciones = "";
    int total_peliculas_argentinas = 0;

    do
    {
        cout << "Ingrese codigo: ";
        cin >> codigo;

        if (codigo != "FIN")
        {
            cout << "Ingrese pais: ";
            cin >> pais;

            cout << "Ingrese duracion (minutos): ";
            cin >> duracion;

            cout << "Ingrese tamaño (GB): ";
            cin >> tamanioGB;

            cout << "Ingrese cantidad de reproducciones: ";
            cin >> reproducciones;

            uso_total_datos += tamanioGB * reproducciones;
            sumatoria_duracion += duracion * reproducciones;
            sumatoria_reproducciones += reproducciones;

            if (reproducciones > maximo_reproducciones)
            {
                maximo_reproducciones = reproducciones;
                codigo_maximas_reproducciones = codigo;
            }

            if (pais == "Argentina")
            {
                total_peliculas_argentinas++;
            }
        }

    } while (codigo != "FIN");

    cout << "Uso total de datos: " << uso_total_datos << " GB" << endl;

    if (sumatoria_reproducciones > 0)
    {
        float promedio_duracion = static_cast<float>(sumatoria_duracion) / sumatoria_reproducciones;
        cout << "Promedio de duracion: " << promedio_duracion << " minutos" << endl;
    }
    else
    {
        cout << "No se registraron reproducciones para calcular el promedio de duracion." << endl;
    }

    cout << "Codigo de la pelicula con mas reproducciones: " << codigo_maximas_reproducciones << endl;
    cout << "Cantidad de peliculas argentinas reproducidas: " << total_peliculas_argentinas << endl;

    return 0;
}
