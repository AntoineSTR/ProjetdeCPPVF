#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

// Classe générique pour représenter un arbre binaire
template <typename T>
class BinaryTree {
private:
    int _depth;                     // Profondeur de l'arbre
    std::vector<std::vector<T>> _tree; // Arbre représenté par un vecteur de vecteurs

public:
    // Constructeur par défaut
    BinaryTree() : _depth(0) {}

    // Définit la profondeur de l'arbre et alloue l'espace
    void setDepth(int depth) {
        _depth = depth;
        _tree.clear();
        _tree.resize(_depth + 1);
        for (int n = 0; n <= _depth; ++n) {
            _tree[n].resize(n + 1);
        }
    }

    // Définit la valeur d'un nœud spécifique
    void setNode(int n, int i, T value) {
        if (n >= 0 && n <= _depth && i >= 0 && i <= n) {
            _tree[n][i] = value;
        }
        else {
            throw std::out_of_range("Indices hors limites.");
        }
    }

    // Récupère la valeur d'un nœud spécifique
    T getNode(int n, int i) const {
        if (n >= 0 && n <= _depth && i >= 0 && i <= n) {
            return _tree[n][i];
        }
        else {
            throw std::out_of_range("Indices hors limites.");
        }
    }

    // Affiche les valeurs de l'arbre
    void display() const {
        for (int n = 0; n <= _depth; ++n) {
            for (int i = 0; i <= n; ++i) {
                std::cout << _tree[n][i] << " ";
            }
            std::cout << std::endl;
        }
    }
};
