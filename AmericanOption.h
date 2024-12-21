#pragma once
#include "Option.h"

// Classe abstraite pour les options américaines
class AmericanOption : public Option {
public:
    // Constructeur
    AmericanOption(double expiry) : Option(expiry) {}

    // Indique qu'il s'agit d'une option américaine
    bool isAmericanOption() const override { return true; }

    // Méthode virtuelle pure pour le payoff
    virtual double payoff(double spotPrice) const = 0;

    // Méthode pour afficher les détails
    void printDetails() const override {
        std::cout << "Option américaine" << std::endl;
    }
};
