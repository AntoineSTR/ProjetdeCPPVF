#pragma once
#include <random>

// Classe pour la g�n�ration de nombres al�atoires
class MT {
private:
    static std::mt19937 generator;  // D�claration statique du g�n�rateur

    MT() {}  // Constructeur priv� pour emp�cher l'instanciation

public:
    // G�n�re un nombre uniforme entre 0 et 1
    static double rand_unif() {
        static std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(generator);
    }

    // G�n�re un nombre normal standard (moyenne = 0, �cart-type = 1)
    static double rand_norm() {
        static std::normal_distribution<double> dist(0.0, 1.0);
        return dist(generator);
    }
};
