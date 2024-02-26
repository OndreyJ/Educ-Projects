#include <fstream>
#include <iostream>
#include <string>

#include "Average.h"

int main() {
    std::string line;
    int input = 1;
    bool tryAgain = true;
    Average GasPrices;

    // while (tryAgain) {
    //     try {
    //         std::cout << "Average Price per Year(1), Average Price per Month(2), Highest and Lowest Prices per year(3),\nList of Prices, Lowest to Highest(4), List of Prices, Highest to Lowest(5). Enter a number: ";
    //         std::cin >> input;
    //         if (input < 0 || input > 5) {
    //             throw input;
    //         } else {
    //             tryAgain = false;
    //         }
    //     } catch (int) {
    //         std::cout << "Invalid";
    //     }
    // }

    GasPrices.setPricesMonth();
    GasPrices.displayPrices();
    GasPrices.setPricesYear();
    GasPrices.displayPrices();

    return 0;
}