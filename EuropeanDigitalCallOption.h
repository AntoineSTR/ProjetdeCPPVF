#pragma once
#include "EuropeanDigitalOption.h"

// Classe repr�sentant une option num�rique d'achat (Digital Call)
class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    // Constructeur
    EuropeanDigitalCallOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    // Impl�mentation du payoff pour un Digital Call
    double payoff(double spotPrice) const override {
        return spotPrice >= _strike ? 1.0 : 0.0;
    }

    // Retourne le type d'option
    std::string getOptionType() const override {
        return "Digital Call";
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option num�rique d'achat (Digital Call)" << std::endl;
        EuropeanDigitalOption::printDetails();
    }
};
