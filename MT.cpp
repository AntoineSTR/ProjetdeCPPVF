#include "MT.h"

// Initialisation du g�n�rateur Mersenne Twister
std::mt19937 MT::generator(std::random_device{}());
