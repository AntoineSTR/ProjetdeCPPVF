#pragma once
#include "Option.h"
#include <vector>
#include <numeric>

// Classe abstraite pour les options asiatiques
class AsianOption : public Option {
protected:
    std::vector<double> _timeSteps; // Dates des observations

public:
    // Constructeur
    AsianOption(double expiry, const std::vector<double>& timeSteps) : Option(expiry), _timeSteps(timeSteps) {}

    // Retourne les dates des observations
    const std::vector<double>& getTimeSteps() const { return _timeSteps; }

    // Calcul du payoff basé sur la moyenne des prix (par chemin)
    double payoffPath(const std::vector<double>& path) const override {
        double average = std::accumulate(path.begin(), path.end(), 0.0) / path.size();
        return payoff(average);
    }

    // Indique qu'il s'agit d'une option asiatique
    bool isAsianOption() const override { return true; }

    // Méthode virtuelle pure pour le payoff
    virtual double payoff(double spotPrice) const = 0;
};
