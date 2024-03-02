#ifndef AVERAGE_H
#define AVERAGE_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Average {
private:
    std::map<std::string, std::vector<std::string>> Prices;

public:
    void setPricesYear();
    void setPricesMonth();
    void displayPrices();
};

void Average ::setPricesYear() {  // Adds all Gas Prices according to their year into the vector
    std::string line, year, indivPrice;
    std::ifstream file("GasPrices.txt");
    while (std::getline(file, line)) {  // Loops through entire text file
        year = line.substr(6, 4);
        indivPrice = line.substr(11, (line.length() - 11));

        Prices[year].push_back(indivPrice);
    }
    file.close();
}

void Average ::setPricesMonth() {  // Adds all Gas Prices according to their month into the vector
    std::string line, year, indivPrice;
    std::ifstream file("GasPrices.txt");
    while (std::getline(file, line)) {  // Loops through entire text file
        year = line.substr(6, 4) + "-" + line.substr(0, 2);
        indivPrice = line.substr(11, (line.length() - 11));
        Prices[year].push_back(indivPrice);
    }
    file.close();
}

void Average ::displayPrices() {  // Displays the average prices per month and year

    for (auto i : Prices) {  // Iterates through every key-value pair of the map
        double total = 0;
        int count = 0;

        for (auto j : i.second) {  // Iterates through every value of each map, adding them together
                                   // and getting the total count of the prices per month or year
            total += std::stod(j);
            count++;
        }

        // Outputs the average by dividing the total from the count
        std::cout << i.first << ": $" << std::fixed << std::setprecision(3) << total / count << std::endl;

        total = 0;
        count = 0;
    }
    Prices.clear();
}

#endif