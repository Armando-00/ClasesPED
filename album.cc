#include <iostream>
#include <string>
#include <vector>
#include <utility> 

// Estructura para el artista
struct Artista {
    std::string nombre;
    std::string nacionalidad;
};

// Estructura para el álbum
struct Album {
    std::string nombre;
    int fecha, tiempo_transcurrido;
    std::vector<std::pair<int, std::string>> canciones; 
    Artista artista; 
};

Album SolicitarDatosArtista() {
    char opcion;
    Album album;

    std::cout << "Ingrese el nombre del artista: ";
    std::cin >> album.artista.nombre;

    std::cout << "Ingrese la nacionalidad del artista: ";
    std::cin >> album.artista.nacionalidad;

    std::cout << "Ingrese el nombre del album: ";
    std::cin >> album.nombre;

    std::cout << "Ingrese el año del album: ";
    std::cin >> album.fecha;

    int numero_cancion = 1;
    do { 
        std::string nombre_cancion;
        std::cout << "Ingrese el nombre de la cancion #" << numero_cancion << ": ";
        std::cin >> nombre_cancion;
        album.canciones.push_back({numero_cancion, nombre_cancion});
        numero_cancion++;

        std::cout << "Desea agregar otra cancion? (s/n): ";
        std::cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return album;
}

void ImprimirInformacion(Album album) {
    std::cout << "Nombre del artista: " << album.artista.nombre << std::endl;
    std::cout << "Nacionalidad del artista: " << album.artista.nacionalidad << std::endl;
    std::cout << "Nombre del Album: " << album.nombre << std::endl;
    std::cout << "Fecha del Album: " << album.fecha << std::endl;

    for (const auto &cancion : album.canciones) {
        std::cout << "Cancion " << cancion.first << ": " << cancion.second << std::endl;
    }
}

int CalcularFechaAlbum(const Album& album){
    int tiempotranscurrido = 2025 - album.fecha;
    std::cout << "El tiempo transcurrido desde la fecha del album es: " 
              << tiempotranscurrido << " años." << std::endl;
    return tiempotranscurrido;
}

void BuscarCancion(const Album& album) {
    std::string nombreBuscado;
    std::cout << "Ingrese el nombre de la cancion a buscar: ";
    std::cin >> nombreBuscado;

    bool encontrada = false;
    for (auto cancion : album.canciones) {
        if (cancion.second == nombreBuscado) {  
        std::cout << "Cancion encontrada: " << cancion.second << std::endl;
        encontrada = true;
        }
    }
    if (!encontrada) {
        std::cout << "Cancion no encontrada en el album." << std::endl;
    }
    
}

int main() {
    Album album = SolicitarDatosArtista();
    ImprimirInformacion(album);
    album.tiempo_transcurrido = CalcularFechaAlbum(album); 
    BuscarCancion(album);
    return 0;
}








