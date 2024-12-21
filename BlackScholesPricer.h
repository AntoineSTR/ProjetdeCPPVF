#pragma once

#include "EuropeanVanillaOption.h"
#include "EuropeanDigitalOption.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

class BlackScholesPricer {
private:
    Option* _option;    // Pointeur vers l'option
    double _S;          // Prix de l'actif sous-jacent
    double _r;          // Taux d'intérêt sans risque
    double _sigma;      // Volatilité du sous-jacent

    // Calcul de d1 dans la formule Black-Scholes
    double d1() const {
        double strike = getStrike();
        return (std::log(_S / strike) +
            (_r + 0.5 * _sigma * _sigma) * _option->getExpiry()) /
            (_sigma * std::sqrt(_option->getExpiry()));
    }

    // Calcul de d2 dans la formule Black-Scholes
    double d2() const {
        return d1() - _sigma * std::sqrt(_option->getExpiry());
    }

    // Fonction de répartition cumulative de la loi normale
    double normalCDF(double value) const {
        return 0.5 * std::erfc(-value / std::sqrt(2));
    }

    // Récupérer le prix d'exercice pour l'option
    double getStrike() const {
        if (auto vanilla_option = dynamic_cast<EuropeanVanillaOption*>(_option)) {
            return vanilla_option->getStrike();
        }
        if (auto digital_option = dynamic_cast<EuropeanDigitalOption*>(_option)) {
            return digital_option->getStrike();
        }
        throw std::logic_error("Type d'option non supporté pour obtenir le strike.");
    }

public:
    // Constructeur avec validation des arguments
    BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility)
        : _option(option), _S(asset_price), _r(interest_rate), _sigma(volatility) {
        if (!_option || asset_price <= 0 || interest_rate < 0 || volatility <= 0) {
            throw std::invalid_argument("Les paramètres doivent être valides et positifs.");
        }
    }

    // Calcul du prix de l'option
    double operator()() const {
        double d1_val = d1();
        double d2_val = d2();

        // Options numériques
        if (auto digital_option = dynamic_cast<EuropeanDigitalOption*>(_option)) {
            if (digital_option->getOptionType() == "Digital Call") {
                return std::exp(-_r * _option->getExpiry()) * normalCDF(d2_val);
            }
            else if (digital_option->getOptionType() == "Digital Put") {
                return std::exp(-_r * _option->getExpiry()) * normalCDF(-d2_val);
            }
        }

        // Options vanille
        if (auto vanilla_option = dynamic_cast<EuropeanVanillaOption*>(_option)) {
            if (vanilla_option->getOptionType() == "Call") {
                return _S * normalCDF(d1_val) -
                    vanilla_option->getStrike() * std::exp(-_r * _option->getExpiry()) * normalCDF(d2_val);
            }
            else if (vanilla_option->getOptionType() == "Put") {
                return vanilla_option->getStrike() * std::exp(-_r * _option->getExpiry()) * normalCDF(-d2_val) -
                    _S * normalCDF(-d1_val);
            }
        }

        throw std::logic_error("Type d'option non pris en charge.");
    }

    // Calcul du delta de l'option
    double delta() const {
        double d1_val = d1();

        // Options numériques
        if (auto digital_option = dynamic_cast<EuropeanDigitalOption*>(_option)) {
            if (digital_option->getOptionType() == "Digital Call") {
                return std::exp(-_r * _option->getExpiry()) * normalCDF(d1_val) / _S;
            }
            else if (digital_option->getOptionType() == "Digital Put") {
                return -std::exp(-_r * _option->getExpiry()) * normalCDF(-d1_val) / _S;
            }
        }

        // Options vanille
        if (auto vanilla_option = dynamic_cast<EuropeanVanillaOption*>(_option)) {
            if (vanilla_option->getOptionType() == "Call") {
                return normalCDF(d1_val);
            }
            else if (vanilla_option->getOptionType() == "Put") {
                return normalCDF(d1_val) - 1;
            }
        }

        throw std::logic_error("Type d'option non pris en charge.");
    }
};
