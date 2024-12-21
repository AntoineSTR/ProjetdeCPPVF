#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

// Classe abstraite de base pour toutes les options
class Option {
protected:
    double _expiry; // Date d'expiration de l'option

public:
    // Constructeur avec validation de l'expiration
    Option(double expiry) : _expiry(expiry) {
        if (expiry <= 0) {
            throw std::invalid_argument("L'expiration doit �tre sup�rieure � z�ro.");
        }
    }

    // Destructeur virtuel pour permettre une destruction correcte des objets d�riv�s
    virtual ~Option() {}

    // Getter pour l'expiration
    double getExpiry() const { return _expiry; }

    // M�thode virtuelle pure pour le calcul du payoff
    virtual double payoff(double spotPrice) const = 0;

    // M�thode pour calculer le payoff en fonction d'un chemin (par d�faut, utilise le dernier prix)
    virtual double payoffPath(const std::vector<double>& path) const {
        return payoff(path.back());
    }

    // M�thodes virtuelles pour identifier le type d'option
    virtual bool isAsianOption() const { return false; }
    virtual bool isAmericanOption() const { return false; }

    // M�thode virtuelle pure pour afficher les d�tails de l'option
    virtual void printDetails() const = 0;
};
