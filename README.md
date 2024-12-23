# C++ for Finance - The Project

## Description
Ce projet implémente plusieurs modèles de pricing pour différents types d'options, notamment les options européennes (vanille et numériques), les options asiatiques, et les options américaines.

Les deux principales méthodes d'évaluation utilisées sont :
1. **Modèle de Monte Carlo** basé sur le modèle Black-Scholes.
2. **Modèle Cox-Ross-Rubinstein (CRR)** pour l'évaluation par arbre binaire.

---

## Fonctionnalités
- Prise en charge de plusieurs types d'options :
  - Options européennes vanille (Call, Put).
  - Options européennes numériques (Digital Call, Digital Put).
  - Options asiatiques (Call, Put).
  - Options américaines (Call, Put).
- Méthodes d'évaluation :
  - **Monte Carlo** avec génération de chemins stochastiques.
  - **Modèle CRR** avec calcul des prix explicites et récursifs.
- Gestion d'arbres binaires pour le stockage des prix et des politiques d'exercice.
- Calculs avancés :
  - Payoff en fonction des spécificités de chaque option.
  - Calculs des deltas (sensibilité au prix sous-jacent).
  - Intervalle de confiance pour Monte Carlo.

---

## Structure du projet
### Classes principales
| Classe                      | Description                                                                                 |
|-----------------------------|---------------------------------------------------------------------------------------------|
| `Option`                    | Classe abstraite de base pour toutes les options.                                           |
| `EuropeanVanillaOption`     | Options européennes vanille avec Call et Put.                                               |
| `EuropeanDigitalOption`     | Options numériques européennes avec Digital Call et Put.                                    |
| `AsianOption`               | Classe abstraite pour les options asiatiques.                                               |
| `AmericanOption`            | Classe abstraite pour les options américaines.                                              |
| `CRRPricer`                 | Implémentation du modèle CRR pour le pricing des options.                                   |
| `BlackScholesPricer`        | Implémentation du modèle Black-Scholes pour le pricing des options.                         |
| `BinaryTree`                | Classe générique pour stocker les arbres binaires (utilisée pour les arbres CRR).           |
| `MT`                        | Générateur aléatoire utilisant le moteur Mersenne Twister pour Monte Carlo.                 |

---

## Prérequis
### Langage et outils
- **C++**.
- **Microsoft Visual Studio** .

---

## Auteurs
SOREL Gautier, STREICHENBERGER Antoine, TARANTINO Tancrède - Étudiant en ingénierie financière à l'ESILV.
Ce projet a été réalisé dans le cadre du cours de C++ for finance.
