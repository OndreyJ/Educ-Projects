#ifndef PRICETOTEXT_H
#define PRICETOTEXT_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>

class PriceToText {
private:
    std::multimap<double, std::string> Prices;

public:
    void setPrices();
    void lowHigh();
    void highLow();
};

void PriceToText ::setPrices() {  // Sets the Price as the key and the year as the value
    double indivPrice;            // Doing this sorts the keys from lowest to highest price
    std::string line, date;
    std::ifstream file("GasPrices.txt");

    while (std::getline(file, line)) {  // Loops through entire text file
        indivPrice = std::stod(line.substr(11, line.length() - 11));
        date = line.substr(0, 10);
        Prices.emplace(indivPrice, date);
    }

    file.close();
}

void PriceToText ::lowHigh() {  // Creates an iterator that iterates from beginning to end
                                // Putting the data in the file from lowest to highest price
    std::ifstream fileExist("PricesLowHigh.txt");
    if (fileExist) {
        std::cout << "File already exists!\n";
    } else {
        std::ofstream file("PricesLowHigh.txt", std::ios::out);
        for (auto it = Prices.begin(); it != Prices.end(); it++) {
            file << it->second << ": $" << it->first << std::endl;
        }
        file.close();
    }
    fileExist.close();
    Prices.clear();
}

void PriceToText ::highLow() {  // Creates a reverse iterator that iterates from end to beginning
                                // putting the data in the file from highest to lowest price
    std::ifstream fileExist("PricesHighLow.txt");
    if (fileExist) {
        std::cout << "File already exists!\n";
    } else {
        std::ofstream file("PricesHighLow.txt", std::ios::out);
        for (auto rit = Prices.rbegin(); rit != Prices.rend(); rit++) {
            file << rit->second << ": $" << rit->first << std::endl;
        }
        file.close();
    }
    fileExist.close();
    Prices.clear();
}
#endif