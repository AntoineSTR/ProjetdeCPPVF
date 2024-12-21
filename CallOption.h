#pragma once
#include "EuropeanVanillaOption.h"
#include <algorithm>

// Classe repr�sentant une option d'achat (Call)
class CallOption : public EuropeanVanillaOption {
public:
    // Constructeur
    CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    // Impl�mentation du payoff pour une option Call
    double payoff(double spotPrice) const override {
        return std::max(spotPrice - _strike, 0.0);
    }

    // Retourne le type de l'option
    std::string getOptionType() const override {
        return "Call";
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option d'achat (Call)" << std::endl;
        EuropeanVanillaOption::printDetails();
    }
};
