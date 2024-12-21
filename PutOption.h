#pragma once
#include "EuropeanVanillaOption.h"
#include <algorithm>

// Classe représentant une option de vente (Put)
class PutOption : public EuropeanVanillaOption {
public:
    // Constructeur
    PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    // Implémentation du payoff pour une option Put
    double payoff(double spotPrice) const override {
        return std::max(_strike - spotPrice, 0.0);
    }

    // Retourne le type de l'option
    std::string getOptionType() const override {
        return "Put";
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option de vente (Put)" << std::endl;
        EuropeanVanillaOption::printDetails();
    }
};
