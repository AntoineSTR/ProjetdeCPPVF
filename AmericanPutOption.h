#pragma once
#include "AmericanOption.h"
#include <algorithm>

// Classe représentant une option américaine de vente
class AmericanPutOption : public AmericanOption {
private:
    double _strike;

public:
    // Constructeur
    AmericanPutOption(double expiry, double strike) : AmericanOption(expiry), _strike(strike) {}

    // Payoff spécifique pour un Put américain
    double payoff(double spotPrice) const override {
        return std::max(_strike - spotPrice, 0.0);
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option américaine de vente (Put) avec strike : " << _strike << std::endl;
    }
};
