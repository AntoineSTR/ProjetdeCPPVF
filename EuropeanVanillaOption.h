#pragma once
#include "Option.h"
#include <string>
#include <stdexcept>

// Classe abstraite pour les options européennes vanille
class EuropeanVanillaOption : public Option {
protected:
    double _strike; // Prix d'exercice (strike)

public:
    // Constructeur avec validation des arguments
    EuropeanVanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) {
        if (strike <= 0) {
            throw std::invalid_argument("Le prix d'exercice doit être supérieur à zéro.");
        }
    }

    // Getter pour le prix d'exercice
    double getStrike() const { return _strike; }

    // Méthode virtuelle pure pour obtenir le type de l'option (Call/Put)
    virtual std::string getOptionType() const = 0;

    // Méthode pour afficher les détails de l'option
    void printDetails() const override {
        std::cout << "Type d'option : " << getOptionType() << std::endl;
        std::cout << "Expiration : " << getExpiry() << " ans" << std::endl;
        std::cout << "Prix d'exercice : " << _strike << std::endl;
    }

    // Méthode pour ajuster le prix d'exercice (utile pour des événements comme les splits)
    void adjustStrike(double new_strike) {
        if (new_strike <= 0) {
            throw std::invalid_argument("Le nouveau prix d'exercice doit être supérieur à zéro.");
        }
        _strike = new_strike;
    }
};
