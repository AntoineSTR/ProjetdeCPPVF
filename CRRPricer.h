#pragma once
#include "BinaryTree.h"
#include "Option.h"
#include <cmath>
#include <stdexcept>
#include <vector>

// Classe pour évaluer les options avec le modèle CRR
class CRRPricer {
private:
    Option* _option;      // Pointeur vers l'option
    int _depth;           // Profondeur de l'arbre (N)
    double _asset_price;  // Prix initial de l'actif sous-jacent (S0)
    double _up;           // Facteur de hausse (U)
    double _down;         // Facteur de baisse (D)
    double _interest_rate; // Taux sans risque (R)
    BinaryTree<double> _tree; // Arbre pour stocker les valeurs des prix

    // Vérifie les conditions d'arbitrage
    void checkArbitrage() const {
        double U = 1 + _up;
        double D = 1 + _down;
        double R = 1 + _interest_rate;

        if (D >= 1 || U <= 1 || R <= D || R >= U) {
            throw std::invalid_argument("Paramètres d'arbitrage invalides : vérifier que D < R < U.");
        }
    }

    // Calcule la valeur binomiale avec une formule fermée
    double binomialFormula() const {
        double U = 1 + _up;
        double D = 1 + _down;
        double R = 1 + _interest_rate;
        double q = (R - D) / (U - D);

        double price = 0.0;
        for (int i = 0; i <= _depth; ++i) {
            double binomial_coeff = std::tgamma(_depth + 1) /
                (std::tgamma(i + 1) * std::tgamma(_depth - i + 1));
            double prob = std::pow(q, i) * std::pow(1 - q, _depth - i);
            double spotPrice = _asset_price * std::pow(U, i) * std::pow(D, _depth - i);
            price += binomial_coeff * prob * _option->payoff(spotPrice);
        }
        return price / std::pow(R, _depth);
    }

public:
    // Constructeur prenant les paramètres U, D, R directement
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
        : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate) {
        checkArbitrage();
        _tree.setDepth(_depth);
    }

    // Nouveau constructeur prenant la volatilité (sigma) et le taux (r)
    CRRPricer(Option* option, int depth, double asset_price, double r, double sigma)
        : _option(option), _depth(depth), _asset_price(asset_price) {
        double dt = 1.0 / depth;
        _up = std::exp(sigma * std::sqrt(dt)) - 1;
        _down = std::exp(-sigma * std::sqrt(dt)) - 1;
        _interest_rate = std::exp(r * dt) - 1;

        checkArbitrage();
        _tree.setDepth(_depth);
    }

    // Remplit et calcule l'arbre
    void compute() {
        double U = 1 + _up;
        double D = 1 + _down;
        double R = 1 + _interest_rate;

        // Remplissage de l'arbre des prix
        for (int n = 0; n <= _depth; ++n) {
            for (int i = 0; i <= n; ++i) {
                _tree.setNode(n, i, _asset_price * std::pow(U, i) * std::pow(D, n - i));
            }
        }

        // Calcul des payoffs à la maturité
        for (int i = 0; i <= _depth; ++i) {
            _tree.setNode(_depth, i, _option->payoff(_tree.getNode(_depth, i)));
        }

        // Calcul rétrograde dans l'arbre
        for (int n = _depth - 1; n >= 0; --n) {
            for (int i = 0; i <= n; ++i) {
                double value = (1.0 / R) * (
                    _tree.getNode(n + 1, i + 1) +
                    _tree.getNode(n + 1, i)) / 2.0;
                _tree.setNode(n, i, value);
            }
        }
    }

    // Retourne le prix de l'option à la racine
    double operator()(bool closed_form = false) {
        if (closed_form) {
            return binomialFormula();
        }
        compute();
        return _tree.getNode(0, 0);
    }
};
