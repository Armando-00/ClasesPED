#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

struct InformacionCupon
{
    int cantidad_cupones;
    std::string nombre_persona;
    std::vector<std::pair<std::string, std::string>> cupones_premio;
};

std::string SolicitarDatos();
std::string GenerarCupon(std::string identificador_letras);
std::string VerificarCupon(std::string cupon);

struct InformacionCupon SolicitarDatosGenerales();

void ImprimirformacionCupon(const InformacionCupon &cupon);

int main(){
    srand(time(0));

    // Vector de tipo struct
    std::vector<InformacionCupon> inf_cupones;

    // Almacenar el struct cupon en el vector
    InformacionCupon cupon = SolicitarDatosGenerales();
    inf_cupones.push_back(cupon);

    // Imprimir la información usando la función
    ImprimirInformacionCupon(cupon);

    return 0;
}

struct InformacionCupon SolicitarDatosGenerales()
{
    InformacionCupon cupon;

    // Solicitar la cantidad de cupones a generar
    std::cout << "Ingresa cantidad de cupones a generar:\n";
    std::cin >> cupon.cantidad_cupones;

    std::cout << "Ingresa el nombre de la persona:\n";
    std::cin >> cupon.nombre_persona;

    for (int i = 0; i < cupon.cantidad_cupones; i++)
    {
        std::string cupon_generado = GenerarCupon(SolicitarDatos());
        std::string premio = VerificarCupon(cupon_generado);
        cupon.cupones_premio.push_back(std::make_pair(cupon_generado, premio));
    }

    return cupon;
}

std::string SolicitarDatos()
{
    std::string prefijo;

    do
    {
        std::cout << "Ingrese las letras del cupon (3 letras):\n";
        std::cin >> prefijo;

        if (prefijo.length() != 3)
        {
            std::cout << "Error: Debe ingresar exactamente 3 letras.\n";
        }
        else
        {
            return prefijo;
        }
    } while (true);
}

std::string GenerarCupon(std::string identificador_letras)
{
    int numero_aleatorio = rand() % 9000 + 1000; // 4 dígitos
    return identificador_letras + std::to_string(numero_aleatorio);
}

std::string VerificarCupon(std::string cupon)
{
    std::string mensaje;
    std::string num_extraido = cupon.substr(3, 4);
    int num_cupon = std::stoi(num_extraido);

    if (num_cupon % 2 == 0)
        mensaje = "Tiene premio";
    else
        mensaje = "No tiene premio";

    return mensaje;
}

// Función para imprimir la información del cupon
void ImprimirInformacionCupon(const InformacionCupon &cupon)
{

    // Solicitar nombre de la persona
    std::cout << "\nNombre de la persona: " << cupon.nombre_persona << "\n";
    // Solititar cantidad de cupones
    std::cout << "Cantidad de cupones: " << cupon.cantidad_cupones << "\n\n";

    for (const auto &c : cupon.cupones_premio)
    {
        std::cout << "Cupon generado: " << c.first
                  << " | Premio: " << c.second << "\n";
    }
}
