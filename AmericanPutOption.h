#pragma once
#include "AmericanOption.h"
#include <algorithm>

// Classe repr�sentant une option am�ricaine de vente
class AmericanPutOption : public AmericanOption {
private:
    double _strike;

public:
    // Constructeur
    AmericanPutOption(double expiry, double strike) : AmericanOption(expiry), _strike(strike) {}

    // Payoff sp�cifique pour un Put am�ricain
    double payoff(double spotPrice) const override {
        return std::max(_strike - spotPrice, 0.0);
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option am�ricaine de vente (Put) avec strike : " << _strike << std::endl;
    }
};
