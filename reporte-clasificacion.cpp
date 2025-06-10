#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Captura y validación de datos personales
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

// Captura de calificaciones con validación
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

// Cálculo del promedio
float calcularPromedio(const std::vector<float>& notas) {
    float suma = 0.0;
    for (float n : notas) suma += n;
    return suma / notas.size();
}

// Mostrar resultados organizados
void mostrarResultados(const std::vector<std::string>& nombres,
                       const std::vector<int>& ciclos,
                       const std::vector<int>& cedulas,
                       const std::vector<float>& promedios) {
    std::cout << "\n==================== APROBADOS ====================\n";
    std::cout << std::left << std::setw(30) << "Nombre completo"
              << std::setw(8) << "Ciclo"
              << std::setw(12) << "Cédula"
              << "Promedio\n";

    for (size_t i = 0; i < nombres.size(); ++i) {
        if (promedios[i] >= 70.0) {
            std::cout << std::left << std::setw(30) << nombres[i]
                      << std::setw(8) << ciclos[i]
                      << std::setw(12) << cedulas[i]
                      << std::fixed << std::setprecision(2)
                      << promedios[i] << "\n";
        }
    }

    std::cout << "\n==================== REPROBADOS ===================\n";
    std::cout << std::left << std::setw(30) << "Nombre completo"
              << std::setw(8) << "Ciclo"
              << std::setw(12) << "Cédula"
              << "Promedio\n";

    for (size_t i = 0; i < nombres.size(); ++i) {
        if (promedios[i] < 70.0) {
            std::cout << std::left << std::setw(30) << nombres[i]
                      << std::setw(8) << ciclos[i]
                      << std::setw(12) << cedulas[i]
                      << std::fixed << std::setprecision(2)
                      << promedios[i] << "\n";
        }
    }
}

int main() {
    int cantidad;
    std::vector<std::string> nombres;
    std::vector<int> ciclos;
    std::vector<int> cedulas;
    std::vector<float> promedios;

    // Captura de cantidad de alumnos
    do {
        std::cout << "¿Cuántos alumnos desea evaluar?: ";
        std::cin >> cantidad;
        if(std::cin.fail() || cantidad <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada inválida. Ingrese un número mayor a 0.\n";
        }
    } while (cantidad <= 0);

    // Captura de datos por alumno
    for (int i = 0; i < cantidad; ++i) {
        std::string nombre, apellido1, apellido2;
        int ciclo, cedula;
        std::vector<float> notas;

        std::cout << "\n********** Alumno #" << (i + 1) << " **********\n";
        capturarDatos(nombre, apellido1, apellido2, ciclo, cedula);
        capturarNotas(notas);
        float promedio = calcularPromedio(notas);

        nombres.push_back(nombre + " " + apellido1 + " " + apellido2);
        ciclos.push_back(ciclo);
        cedulas.push_back(cedula);
        promedios.push_back(promedio);
    }

    // Mostrar resultados finales
    mostrarResultados(nombres, ciclos, cedulas, promedios);

    return 0;
}