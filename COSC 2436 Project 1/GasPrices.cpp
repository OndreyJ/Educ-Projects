#include <iostream>

#include "header\Average.h"
#include "header\Outliers.h"
#include "header\PriceToText.h"

int main() {
    char input;
    bool tryAgain = true;
    Average GasPrices;
    Outliers MinMaxPrices;
    PriceToText FileGen;

    while (tryAgain) {
        std::cout << "\nAverage Price per Year(1)";
        std::cout << "\nAverage Price per Month(2)";
        std::cout << "\nHighest and Lowest Prices per year(3)";
        std::cout << "\nFile of Prices, Lowest to Highest(4)";
        std::cout << "\nFile of Prices, Highest to Lowest(5)";
        std::cout << "\nEnd Program (6)";
        std::cout << "\nEnter a number: ";

        std::cin >> input;

        std::cout << "\n\n";

        if (input >= '1' && input <= '6') {
            switch (input) {
                case '1':
                    GasPrices.setPricesYear();
                    GasPrices.displayPrices();
                    break;
                case '2':
                    GasPrices.setPricesMonth();
                    GasPrices.displayPrices();
                    break;
                case '3':
                    MinMaxPrices.setPrices();
                    MinMaxPrices.displayPrices();
                    break;
                case '4':
                    FileGen.setPrices();
                    FileGen.lowHigh();
                    break;
                case '5':
                    FileGen.setPrices();
                    FileGen.highLow();
                    break;
                case '6':
                    tryAgain = false;
                    break;
            }
        } else {
            std::cout << "Invalid input: " << input << "\n\n";
        }
    }

    return 0;
}