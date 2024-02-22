#include <fstream>
#include <iostream>
#include <string>

double pricePerYear(std::string);

int main() {
    std::string line;

    std::ifstream file("GasPrices-1.txt");

    while (!file.eof()) {
        std::getline(file, line);

        pricePerYear(line);
    }
    return 0;
}

double pricePerYear(std::string line) {
    int year;

    year = stoi(line.substr(6, 9));

    std::cout << year << std::endl;

    return 1.00;
}