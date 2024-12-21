#pragma once
#include "AsianOption.h"
#include <algorithm>

// Classe repr�sentant une option asiatique de vente
class AsianPutOption : public AsianOption {
private:
    double _strike;

public:
    // Constructeur
    AsianPutOption(const std::vector<double>& timeSteps, double strike)
        : AsianOption(timeSteps.back(), timeSteps), _strike(strike) {}

    // Payoff sp�cifique pour un Put asiatique
    double payoff(double spotPrice) const override {
        return std::max(_strike - spotPrice, 0.0);
    }

    // Affiche les d�tails sp�cifiques
    void printDetails() const override {
        std::cout << "Option asiatique de vente (Put) avec strike : " << _strike << std::endl;
    }
};
