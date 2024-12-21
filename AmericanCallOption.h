#pragma once
#include "AmericanOption.h"
#include <algorithm>

// Classe repr�sentant une option am�ricaine d'achat
class AmericanCallOption : public AmericanOption {
private:
    double _strike;

public:
    // Constructeur
    AmericanCallOption(double expiry, double strike) : AmericanOption(expiry), _strike(strike) {}

    // Payoff sp�cifique pour un Call am�ricain
    double payoff(double spotPrice) const override {
        return std::max(spotPrice - _strike, 0.0);
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option am�ricaine d'achat (Call) avec strike : " << _strike << std::endl;
    }
};
