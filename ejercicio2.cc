#include <iostream>   // Para entrada/salida (std::cin, std::cout)
#include <string>     // Para std::string y getline
#include <vector>     // Para usar std::vector (arreglos dinámicos)

// Estructura que representa una serie
struct Serie {
    int horas_vistas;         // Cuántas horas se vieron
    float pago_vistas;        // Pago por cada hora vista
    float ingreso_generado;   // Calculo: horas_vistas * pago_vistas
    std::string titulo_serie; // Nombre/título de la serie
    std::string genero_serie; // Género de la serie
};

// Vector global que almacenará varias series
std::vector<Serie> vector_series;


// Función para solicitar datos de una serie
Serie SolicitarDatos() {
    Serie info_serie; 
    std::cin.ignore(); // Limpia el buffer para que getline funcione bien después de un cin

    // Pedir datos al usuario
    std::cout << "Ingrese el titulo de la serie: ";
    std::getline(std::cin, info_serie.titulo_serie);

    std::cout << "Ingrese el genero de la serie: ";
    std::getline(std::cin, info_serie.genero_serie);

    std::cout << "Ingrese horas vistas: ";
    std::cin >> info_serie.horas_vistas;

    std::cout << "Ingrese pago por hora vista: ";
    std::cin >> info_serie.pago_vistas;

    // Calcular ingreso generado automáticamente
    info_serie.ingreso_generado = info_serie.horas_vistas * info_serie.pago_vistas;

    return info_serie; // Devuelve la serie con toda su info
}

// Función para mostrar todas las series
void MostrarSeries(const std::vector<Serie>& series) {
    std::cout << "\n--- Lista de Series ---\n";

    // Recorremos el vector e imprimimos cada serie
    for (size_t i = 0; i < series.size(); i++) {
        std::cout << "\nSerie #" << i+1 << "\n";
        std::cout << "Titulo: " << series[i].titulo_serie << "\n";
        std::cout << "Genero: " << series[i].genero_serie << "\n";
        std::cout << "Horas vistas: " << series[i].horas_vistas << "\n";
        std::cout << "Pago por hora: " << series[i].pago_vistas << "\n";
        std::cout << "Ingreso generado: " << series[i].ingreso_generado << "\n";
    }
}

int main() {
    int n; // número de series que ingresará el usuario

    std::cout << "Cuantas series desea ingresar? ";
    std::cin >> n;

    // Bucle para pedir los datos de n series
    for (int i = 0; i < n; i++) {
        std::cout << "\n--- Serie #" << i+1 << " ---\n";
        Serie nueva = SolicitarDatos();      // Llama a la función que pide los datos
        vector_series.push_back(nueva);      // Guarda la serie en el vector
    }

    // Mostrar todas las series ingresadas
    MostrarSeries(vector_series);

    return 0;
}
