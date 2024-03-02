#ifndef OUTLIER_H
#define OUTLIER_H

#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Outliers {
private:
    std::map<std::string, std::array<double, 2>> Prices;

public:
    Outliers() {  // Initialize all of the years as keys in the map
        std::string line, year;
        std::ifstream file("GasPrices.txt");
        while (std::getline(file, line)) {  // Loops through entire text file
            year = line.substr(6, 4);
            Prices[year];
        }
        file.close();
    }

    void setPrices();
    void displayPrices();
};

void Outliers ::setPrices() {  // Extracts the lowest and highest prices for each year
    std::string line, year;
    double indivPrice;
    std::ifstream file("GasPrices.txt");

    while (std::getline(file, line)) {  // Loops through entire text file
        year = line.substr(6, 4);
        indivPrice = std::stod(line.substr(11, line.length() - 11));

        if (Prices[year][0] == 0 || Prices[year][0] > indivPrice) {  // Gets lowest price
            Prices[year][0] = indivPrice;
        }
        if (Prices[year][1] == 0 || Prices[year][1] < indivPrice) {  // Gets highest price
            Prices[year][1] = indivPrice;
        }
    }
    file.close();
}

void Outliers ::displayPrices() {  // Displays the lowest and highest prices for each year
    for (auto year : Prices) {
        std::cout << year.first << "| Lowest: $" << year.second[0] << ", Highest: $" << year.second[1] << std::endl;
    }
}

#endif