#include <iostream>
#include <string>
#include <vector>

void capturarDatos(std::string& nombre, std::string& apellido1, std::string& apellido2, int& ciclo, int& cedula) {
    std::cout << "Ingrese el primer nombre: ";
    std::cin >> nombre;

    std::cout << "Ingrese el primer apellido: ";
    std::cin >> apellido1;

    std::cout << "Ingrese el segundo apellido: ";
    std::cin >> apellido2;

    do {
        std::cout << "Ingrese el ciclo de estudio: ";
        std::cin >> ciclo;
        if (std::cin.fail() || ciclo <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Error: ciclo debe ser un número positivo.\n";
        }
    } while (ciclo <= 0);

    do {
        std::cout << "Ingrese el número de cédula: ";
        std::cin >> cedula;
        if (std::cin.fail() || cedula <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Error: cédula debe ser un número positivo.\n";
        }
    } while (cedula <= 0);
}
