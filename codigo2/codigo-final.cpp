#include <iostream>
#include <string>
#include <vector>

// Función para capturar los datos personales
void capturarDatos(std::string& nombre, std::string& apellido1, std::string& apellido2, int& ciclo, int& cedula) {
    std::cout << "Ingrese el primer nombre: ";
    std::getline(std::cin >> std::ws, nombre);

    std::cout << "Ingrese el primer apellido: ";
    std::getline(std::cin >> std::ws, apellido1);

    std::cout << "Ingrese el segundo apellido: ";
    std::getline(std::cin >> std::ws, apellido2);

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

// Función para capturar notas de exámenes
void capturarNotas(std::vector<float>& notas) {
    float nota;
    for (int i = 0; i < 5; ++i) {
        do {
            std::cout << "Ingrese la nota del examen #" << (i + 1) << ": ";
            std::cin >> nota;
            if (std::cin.fail() || nota < 0.0 || nota > 100.0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Error: nota debe estar entre 0 y 100.\n";
            }
        } while (nota < 0.0 || nota > 100.0);
        notas.push_back(nota);
    }
}

// Función para calcular el promedio
float calcularPromedio(const std::vector<float>& notas) {
    float suma = 0.0;
    for (float n : notas) suma += n;
    return suma / notas.size();
}

// Función principal
int main() {
    std::string nombre, apellido1, apellido2;
    int ciclo, cedula;
    std::vector<float> notas;

    capturarDatos(nombre, apellido1, apellido2, ciclo, cedula);
    capturarNotas(notas);
    float promedio = calcularPromedio(notas);

    std::cout << "\nResumen:\n";
    std::cout << "Nombre completo: " << nombre << " " << apellido1 << " " << apellido2 << "\n";
    std::cout << "Ciclo: " << ciclo << ", Cédula: " << cedula << "\n";
    std::cout << "Promedio: " << promedio << "\n";

    return 0;
}