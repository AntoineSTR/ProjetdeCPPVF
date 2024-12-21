#include "MT.h"

// Initialisation du générateur Mersenne Twister
std::mt19937 MT::generator(std::random_device{}());
