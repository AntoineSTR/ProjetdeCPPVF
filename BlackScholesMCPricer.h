#pragma once
#include "Option.h"
#include "MT.h"
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>

// Classe pour �valuer les options avec la m�thode Monte Carlo
class BlackScholesMCPricer {
private:
    Option* _option;          // Pointeur vers l'option � pricer
    double _S0;               // Prix initial de l'actif sous-jacent
    double _r;                // Taux d'int�r�t sans risque
    double _sigma;            // Volatilit�
    int _nbPaths;             // Nombre de chemins g�n�r�s
    double _currentEstimate;  // Estimation actuelle du prix

public:
    // Constructeur
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
        : _option(option), _S0(initial_price), _r(interest_rate), _sigma(volatility), _nbPaths(0), _currentEstimate(0) {}

    // G�n�re des chemins et met � jour l'estimation du prix
    void generate(int nb_paths) {
        std::vector<double> payoffs;

        for (int i = 0; i < nb_paths; ++i) {
            std::vector<double> path = generatePath();
            payoffs.push_back(_option->payoffPath(path));
        }

        // Calcul de la moyenne des payoffs
        double average = std::accumulate(payoffs.begin(), payoffs.end(), 0.0) / payoffs.size();
        _currentEstimate = std::exp(-_r * _option->getExpiry()) * average;
        _nbPaths += nb_paths;
    }

    // G�n�re un chemin stochastique selon le mod�le Black-Scholes
    std::vector<double> generatePath() const {
        std::vector<double> path;
        double S = _S0;
        double T = _option->getExpiry();
        int steps = 100; // Nombre d'�tapes par chemin
        double dt = T / steps;

        for (int i = 0; i < steps; ++i) {
            double Z = MT::rand_norm(); // Variable al�atoire normale standard
            S = S * std::exp((_r - 0.5 * _sigma * _sigma) * dt + _sigma * std::sqrt(dt) * Z);
            path.push_back(S);
        }

        return path;
    }

    // Retourne l'estimation actuelle du prix
    double operator()() const {
        if (_nbPaths == 0) {
            throw std::runtime_error("Aucun chemin g�n�r�.");
        }
        return _currentEstimate;
    }

    // Retourne le nombre total de chemins g�n�r�s
    int getNbPaths() const { return _nbPaths; }

    // Retourne l'intervalle de confiance � 95 %
    std::vector<double> confidenceInterval() const {
        if (_nbPaths == 0) {
            throw std::runtime_error("Aucun chemin g�n�r�.");
        }
        double margin = 1.96 * std::sqrt(_currentEstimate / _nbPaths);
        return { _currentEstimate - margin, _currentEstimate + margin };
    }
};
