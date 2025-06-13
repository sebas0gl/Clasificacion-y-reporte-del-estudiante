#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void mostrarResultados(const std::vector<std::string>& nombres,
                       const std::vector<std::string>& apellidos,
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