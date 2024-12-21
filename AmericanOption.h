#pragma once
#include "Option.h"

// Classe abstraite pour les options am�ricaines
class AmericanOption : public Option {
public:
    // Constructeur
    AmericanOption(double expiry) : Option(expiry) {}

    // Indique qu'il s'agit d'une option am�ricaine
    bool isAmericanOption() const override { return true; }

    // M�thode virtuelle pure pour le payoff
    virtual double payoff(double spotPrice) const = 0;

    // M�thode pour afficher les d�tails
    void printDetails() const override {
        std::cout << "Option am�ricaine" << std::endl;
    }
};
