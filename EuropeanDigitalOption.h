#pragma once
#include "Option.h"
#include <string>
#include <stdexcept>

// Classe abstraite pour les options num�riques europ�ennes
class EuropeanDigitalOption : public Option {
protected:
    double _strike; // Prix d'exercice (strike)

public:
    // Constructeur
    EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {
        if (strike <= 0) {
            throw std::invalid_argument("Le prix d'exercice doit �tre sup�rieur � z�ro.");
        }
    }

    // Getter pour le prix d'exercice
    double getStrike() const { return _strike; }

    // M�thode virtuelle pure pour le type d'option (Call/Put)
    virtual std::string getOptionType() const = 0;

    // M�thode pour afficher les d�tails
    void printDetails() const override {
        std::cout << "Type d'option : " << getOptionType() << std::endl;
        std::cout << "Expiration : " << getExpiry() << " ans" << std::endl;
        std::cout << "Prix d'exercice : " << _strike << std::endl;
    }
};
