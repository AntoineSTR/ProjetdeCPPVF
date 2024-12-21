#pragma once
#include <random>

// Classe pour la génération de nombres aléatoires
class MT {
private:
    static std::mt19937 generator;  // Déclaration statique du générateur

    MT() {}  // Constructeur privé pour empêcher l'instanciation

public:
    // Génère un nombre uniforme entre 0 et 1
    static double rand_unif() {
        static std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(generator);
    }

    // Génère un nombre normal standard (moyenne = 0, écart-type = 1)
    static double rand_norm() {
        static std::normal_distribution<double> dist(0.0, 1.0);
        return dist(generator);
    }
};
