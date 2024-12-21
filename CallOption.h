#pragma once
#include "EuropeanVanillaOption.h"
#include <algorithm>

// Classe représentant une option d'achat (Call)
class CallOption : public EuropeanVanillaOption {
public:
    // Constructeur
    CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    // Implémentation du payoff pour une option Call
    double payoff(double spotPrice) const override {
        return std::max(spotPrice - _strike, 0.0);
    }

    // Retourne le type de l'option
    std::string getOptionType() const override {
        return "Call";
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option d'achat (Call)" << std::endl;
        EuropeanVanillaOption::printDetails();
    }
};
