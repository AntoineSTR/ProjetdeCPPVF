#pragma once
#include "AsianOption.h"
#include <algorithm>

// Classe repr�sentant une option asiatique d'achat
class AsianCallOption : public AsianOption {
private:
    double _strike;

public:
    // Constructeur
    AsianCallOption(const std::vector<double>& timeSteps, double strike)
        : AsianOption(timeSteps.back(), timeSteps), _strike(strike) {}

    // Payoff sp�cifique pour un Call asiatique
    double payoff(double spotPrice) const override {
        return std::max(spotPrice - _strike, 0.0);
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option asiatique d'achat (Call) avec strike : " << _strike << std::endl;
    }
};
