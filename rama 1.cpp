#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Declaración de funciones
void capturarDatos(std::string&, std::string&, std::string&, int&, int&);
void capturarNotas(std::vector<float>&);
float calcularPromedio(const std::vector<float>&);
void mostrarResultados(const std::vector<std::string>&, const std::vector<std::string>&, const std::vector<int>&, const std::vector<int>&, const std::vector<float>&);

int main() {
    int cantidad;
    std::vector<std::string> nombres;
    std::vector<std::string> apellidos;
    std::vector<int> ciclos;
    std::vector<int> cedulas;
    std::vector<float> promedios;

    do {
        std::cout << "¿Cuántos alumnos desea evaluar?: ";
        std::cin >> cantidad;
