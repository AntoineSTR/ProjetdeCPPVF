#pragma once
#include "AsianOption.h"
#include <algorithm>

// Classe représentant une option asiatique d'achat
class AsianCallOption : public AsianOption {
private:
    double _strike;

public:
    // Constructeur
    AsianCallOption(const std::vector<double>& timeSteps, double strike)
        : AsianOption(timeSteps.back(), timeSteps), _strike(strike) {}

    // Payoff spécifique pour un Call asiatique
    double payoff(double spotPrice) const override {
        return std::max(spotPrice - _strike, 0.0);
    }

    // Affiche les détails spécifiques
    void printDetails() const override {
        std::cout << "Option asiatique d'achat (Call) avec strike : " << _strike << std::endl;
    }
};
