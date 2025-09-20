 #include <iostream>   // Para entrada y salida (std::cin, std::cout)
#include <cstdlib>    // Para funciones de números aleatorios (rand, srand)
#include <ctime>      // Para usar la hora actual como semilla de rand()
#include <vector>     // Para utilizar std::vector (arreglos dinámicos)
#include <utility>    // Para utilizar std::pair (pares de datos)



// Estructura que guarda la información de una persona
struct InformacionPersona
{
    std::string nombre_persona; // Nombre de la persona
};

// Estructura que guarda información sobre los cupones generados
struct InformacionCupon
{
    int cantidad_cupones;   // Cantidad de cupones que tendrá la persona
    // Vector de pares: cada cupón generado y su premio asociado
    std::vector<std::pair<std::string, std::string>> cupones_premio;
    struct InformacionPersona inf_persona; // Información de la persona
};


std::string SolicitarDatos(); // Solicita las letras del cupón (3 letras)
std::string GenerarCupon(std::string identificador_letras); // Genera el cupón
std::string VerificarCupon(std::string cupon); // Verifica si el cupón tiene premio
struct InformacionCupon SolicitarDatosGenerales(); // Pide datos de persona y genera cupones
void ImprimirInformacionCupon(const InformacionCupon &cupon); // Muestra la info en pantalla


int main()
{
    srand(time(0)); // Inicializa los números aleatorios con la hora actual

    // Vector que almacenará varios "InformacionCupon" (para varias personas)
    std::vector<InformacionCupon> inf_cupones;

    char opcion; 
    do {
        // 1. Se solicitan los datos de una persona y sus cupones
        InformacionCupon cupon = SolicitarDatosGenerales();

        // 2. Se almacena en el vector
        inf_cupones.push_back(cupon);

        // 3. Se imprime la información en pantalla
        ImprimirInformacionCupon(cupon);

        // 4. Pregunta si se quieren generar más cupones
        std::cout<< "¿Desea generar más cupones? (s/n)\n";
        std::cin >> opcion;

    } while (opcion == 's' || opcion == 'S'); // Repite mientras la respuesta sea 's' o 'S'

    return 0; // Fin del programa
}

// Solicita datos generales: cantidad de cupones y nombre de la persona
struct InformacionCupon SolicitarDatosGenerales()
{
    InformacionCupon cupon;

    // Pide cuántos cupones se van a generar
    std::cout << "Ingresa cantidad de cupones a generar:\n";
    std::cin >> cupon.cantidad_cupones;

    // Pide el nombre de la persona
    std::cout << "Ingresa el nombre de la persona:\n";
    std::cin >> cupon.inf_persona.nombre_persona;

    // Genera cada cupón según la cantidad solicitada
    for (int i = 0; i < cupon.cantidad_cupones; i++)
    {
        // Pide las 3 letras
        std::string cupon_generado = GenerarCupon(SolicitarDatos());
        // Verifica si el cupón tiene premio
        std::string premio = VerificarCupon(cupon_generado);
        // Almacena el cupón y su resultado en el vector cupones_premio
        cupon.cupones_premio.push_back(std::make_pair(cupon_generado, premio));
    }

    return cupon;
}

// Pide al usuario las letras del cupón (deben ser exactamente 3)
std::string SolicitarDatos()
{
    std::string prefijo;

    do
    {
        std::cout << "Ingrese las letras del cupon (3 letras):\n";
        std::cin >> prefijo;

        if (prefijo.length() != 3) // Valida que sean 3 letras exactas
        {
            std::cout << "Error: Debe ingresar exactamente 3 letras.\n";
        }
        else
        {
            return prefijo; // Si cumple, devuelve el prefijo
        }
    } while (true); // Repite hasta que sea correcto
}

// Genera el cupón completo: las letras + un número aleatorio de 4 dígitos
std::string GenerarCupon(std::string identificador_letras)
{
    int numero_aleatorio = rand() % 9000 + 1000; // Genera número entre 1000 y 9999
    return identificador_letras + std::to_string(numero_aleatorio);
}

// Verifica si el cupón tiene premio
std::string VerificarCupon(std::string cupon)
{
    std::string num_extraido = cupon.substr(3, 4); // Extrae los 4 números
    int num_cupon = std::stoi(num_extraido); // Convierte a entero

    // Si el número es par → tiene premio
    if (num_cupon % 2 == 0)
        return "Tiene premio";
    else
        return "No tiene premio";
}

// Imprime toda la información de un cupón
void ImprimirInformacionCupon(const InformacionCupon &cupon)
{
    std::cout << "\nNombre de la persona: " << cupon.inf_persona.nombre_persona << "\n";
    std::cout << "Cantidad de cupones: " << cupon.cantidad_cupones << "\n\n";

    // Recorre cada cupón generado y muestra su estado
    for (const auto &c : cupon.cupones_premio)
    {
        std::cout << "Cupon generado: " << c.first
                  << " | Premio: " << c.second << "\n";
    }
}