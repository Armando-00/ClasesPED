#include <iostream>
#include <string>
#include <vector>

// Estructura para el artista
struct Artista {
    std::string nombre;
    std::string nacionalidad;
};

// Estructura para el álbum
struct Album {
    std::string nombre;
    int fecha;
    std::vector<std::string> canciones; 
    Artista artista; 
};
int main() {

    return 0;
}


