#pragma once
#include "AmericanOption.h"
#include <algorithm>

// Classe représentant une option américaine d'achat
class AmericanCallOption : public AmericanOption {
private:
    double _strike;

public:
    // Constructeur
    AmericanCallOption(double expiry, double strike) : AmericanOption(expiry), _strike(strike) {}

    // Payoff spécifique pour un Call américain
    double payoff(double spotPrice) const override {
        return std::max(spotPrice - _strike, 0.0);
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option américaine d'achat (Call) avec strike : " << _strike << std::endl;
    }
};
