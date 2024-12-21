#pragma once
#include "Option.h"
#include <string>
#include <stdexcept>

// Classe abstraite pour les options numériques européennes
class EuropeanDigitalOption : public Option {
protected:
    double _strike; // Prix d'exercice (strike)

public:
    // Constructeur
    EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {
        if (strike <= 0) {
            throw std::invalid_argument("Le prix d'exercice doit être supérieur à zéro.");
        }
    }

    // Getter pour le prix d'exercice
    double getStrike() const { return _strike; }

    // Méthode virtuelle pure pour le type d'option (Call/Put)
    virtual std::string getOptionType() const = 0;

    // Méthode pour afficher les détails
    void printDetails() const override {
        std::cout << "Type d'option : " << getOptionType() << std::endl;
        std::cout << "Expiration : " << getExpiry() << " ans" << std::endl;
        std::cout << "Prix d'exercice : " << _strike << std::endl;
    }
};
