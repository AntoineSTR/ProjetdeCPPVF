#pragma once
#include "EuropeanDigitalOption.h"

// Classe représentant une option numérique de vente (Digital Put)
class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    // Constructeur
    EuropeanDigitalPutOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    // Implémentation du payoff pour un Digital Put
    double payoff(double spotPrice) const override {
        return spotPrice < _strike ? 1.0 : 0.0;
    }

    // Retourne le type d'option
    std::string getOptionType() const override {
        return "Digital Put";
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option numérique de vente (Digital Put)" << std::endl;
        EuropeanDigitalOption::printDetails();
    }
};
