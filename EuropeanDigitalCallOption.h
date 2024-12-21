#pragma once
#include "EuropeanDigitalOption.h"

// Classe représentant une option numérique d'achat (Digital Call)
class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    // Constructeur
    EuropeanDigitalCallOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    // Implémentation du payoff pour un Digital Call
    double payoff(double spotPrice) const override {
        return spotPrice >= _strike ? 1.0 : 0.0;
    }

    // Retourne le type d'option
    std::string getOptionType() const override {
        return "Digital Call";
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option numérique d'achat (Digital Call)" << std::endl;
        EuropeanDigitalOption::printDetails();
    }
};
