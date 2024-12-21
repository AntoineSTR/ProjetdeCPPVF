#pragma once
#include "EuropeanVanillaOption.h"
#include <algorithm>

// Classe repr�sentant une option de vente (Put)
class PutOption : public EuropeanVanillaOption {
public:
    // Constructeur
    PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    // Impl�mentation du payoff pour une option Put
    double payoff(double spotPrice) const override {
        return std::max(_strike - spotPrice, 0.0);
    }

    // Retourne le type de l'option
    std::string getOptionType() const override {
        return "Put";
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option de vente (Put)" << std::endl;
        EuropeanVanillaOption::printDetails();
    }
};
