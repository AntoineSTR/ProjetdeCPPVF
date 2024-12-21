#pragma once
#include "EuropeanDigitalOption.h"

// Classe repr�sentant une option num�rique de vente (Digital Put)
class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    // Constructeur
    EuropeanDigitalPutOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    // Impl�mentation du payoff pour un Digital Put
    double payoff(double spotPrice) const override {
        return spotPrice < _strike ? 1.0 : 0.0;
    }

    // Retourne le type d'option
    std::string getOptionType() const override {
        return "Digital Put";
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option num�rique de vente (Digital Put)" << std::endl;
        EuropeanDigitalOption::printDetails();
    }
};
