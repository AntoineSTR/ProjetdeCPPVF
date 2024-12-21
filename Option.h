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
            throw std::invalid_argument("L'expiration doit être supérieure à zéro.");
        }
    }

    // Destructeur virtuel pour permettre une destruction correcte des objets dérivés
    virtual ~Option() {}

    // Getter pour l'expiration
    double getExpiry() const { return _expiry; }

    // Méthode virtuelle pure pour le calcul du payoff
    virtual double payoff(double spotPrice) const = 0;

    // Méthode pour calculer le payoff en fonction d'un chemin (par défaut, utilise le dernier prix)
    virtual double payoffPath(const std::vector<double>& path) const {
        return payoff(path.back());
    }

    // Méthodes virtuelles pour identifier le type d'option
    virtual bool isAsianOption() const { return false; }
    virtual bool isAmericanOption() const { return false; }

    // Méthode virtuelle pure pour afficher les détails de l'option
    virtual void printDetails() const = 0;
};
