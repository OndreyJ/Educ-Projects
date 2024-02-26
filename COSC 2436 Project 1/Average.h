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

void Average ::setPricesYear() {
    std::string line;
    std::ifstream file("GasPrices.txt");
    while (std::getline(file, line)) {
        std::string key = line.substr(6, 4);
        std::string value = line.substr(11, (line.length() - 11));
        Prices[key].push_back(value);
    }
    file.close();
}

void Average ::setPricesMonth() {
    std::string line;
    std::ifstream file("GasPrices.txt");
    while (std::getline(file, line)) {
        std::string key = line.substr(6, 4) + "-" + line.substr(0, 2);
        std::string value = line.substr(11, (line.length() - 11));
        Prices[key].push_back(value);
    }
    file.close();
}

void Average ::displayPrices() {
    for (auto map : Prices) {
        double total = 0;
        int count = 0;

        for (auto vector : map.second) {
            total += std::stod(vector);
            count++;
        }

        std::cout << map.first << ": " << std::fixed << std::setprecision(3) << total / count << std::endl;

        total = 0;
        count = 0;
    }
    Prices.clear();
}

#endif